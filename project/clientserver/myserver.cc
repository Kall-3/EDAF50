#include "connection.h"
#include "connectionclosedexception.h"
#include "database/primeDatabase.h"
#include "server.h"
#include "protocol.h"
#include "messagehandler.h"

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

Server init(int argc, char* argv[])
{
    if (argc != 3) {
        cerr << argc << " Usage: myserver port-number" << endl;
        exit(1);
    }
    cout << "Name: " << argv[1] << ", Port: " << argv[2];

    int port = -1;
    try {
        port = std::stoi(argv[2]);
    } catch (std::exception& e) {
        cerr << "Wrong format for port number. " << e.what() << endl;
        exit(2);
    }

    Server server(port);
    if (!server.isReady()) {
        cerr << "Server initialization error." << endl;
        exit(3);
    }
    return server;
}

void process_request(const std::shared_ptr<Connection> conn, Server& server, PrimeDatabase& db) {
    /* Read one char i.e. one protocol message */
    Protocol message = server.mh.readMessage(conn);

    switch (message) {
        case Protocol::COM_LIST_NG: {
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }

            server.mh.sendMessage(conn, Protocol::ANS_LIST_NG);
            auto query = db.listNewsgroups();

            int size = query.second.size();

            server.mh.sendNumP(conn, size);

            for (auto ng : query.second) {
                server.mh.sendNumP(conn, ng.getID());
                server.mh.sendStringP(conn, ng.getName());
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_CREATE_NG: {
            std::string ng_name = server.mh.readStringP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }

            server.mh.sendMessage(conn, Protocol::ANS_CREATE_NG);
            auto res = db.addNewsgroup(ng_name);

            if (res == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_ALREADY_EXISTS);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_DELETE_NG: {
            int ng_id = server.mh.readNumP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }
            server.mh.sendMessage(conn, Protocol::ANS_DELETE_NG);

            auto res = db.removeNewsgroup(ng_id);

            if (res == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_DOES_NOT_EXIST);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_LIST_ART: {
            int ng_id = server.mh.readNumP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }

            server.mh.sendMessage(conn, Protocol::ANS_LIST_ART);

            auto query = db.getArticles(ng_id);

            if (query.first == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
                server.mh.sendNumP(conn, query.second.size());
                for (auto art : query.second) {
                    server.mh.sendNumP(conn, art.getID());
                    server.mh.sendStringP(conn, art.getTitle());
                }
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_DOES_NOT_EXIST);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_CREATE_ART: {
            int ng_id = server.mh.readNumP(conn);
            std::string title = server.mh.readStringP(conn);
            std::string author = server.mh.readStringP(conn);
            std::string body = server.mh.readStringP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }
            server.mh.sendMessage(conn, Protocol::ANS_CREATE_ART);

            auto res = db.newArticle(ng_id, title, author, body);

            if (res == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_DOES_NOT_EXIST);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_DELETE_ART: {
            int ng_id = server.mh.readNumP(conn);
            int art_id = server.mh.readNumP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }
            server.mh.sendMessage(conn, Protocol::ANS_DELETE_ART);

            auto res = db.removeArticle(ng_id, art_id);

            if (res == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
            } else if (res == ActionResult::NG_DOES_NOT_EXIST) {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_DOES_NOT_EXIST);
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_ART_DOES_NOT_EXIST);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        case Protocol::COM_GET_ART: {
            int ng_id = server.mh.readNumP(conn);
            int art_id = server.mh.readNumP(conn);
            if (server.mh.readMessage(conn) != Protocol::COM_END) { throw ProtocolViolationException(); }
            server.mh.sendMessage(conn, Protocol::ANS_GET_ART);

            auto query = db.getArticle(ng_id, art_id);

            if (query.first == ActionResult::ACCEPTED) {
                server.mh.sendMessage(conn, Protocol::ANS_ACK);
                server.mh.sendStringP(conn, query.second.getTitle());
                server.mh.sendStringP(conn, query.second.getAuthor());
                server.mh.sendStringP(conn, query.second.getBody());
            } else if (query.first == ActionResult::NG_DOES_NOT_EXIST) {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_NG_DOES_NOT_EXIST);
            } else {
                server.mh.sendMessage(conn, Protocol::ANS_NAK);
                server.mh.sendMessage(conn, Protocol::ERR_ART_DOES_NOT_EXIST);
            }
            server.mh.sendMessage(conn, Protocol::ANS_END);
            break;
        }
        default:
            throw ProtocolViolationException();
    }
}

void serve_one(Server& server, PrimeDatabase& db)
{
    cout << endl << "Waiting for activity" << endl;
    auto conn = server.waitForActivity();
    if (conn != nullptr) {
        try {
            cout << "Processing request" << std::endl;
            process_request(conn, server, db);
        } catch (ConnectionClosedException&) {
            server.deregisterConnection(conn);
            cout << "Client closed connection" << endl;
        } catch (ProtocolViolationException&) {
            server.deregisterConnection(conn);
            cout << "Client violated protocol, kicked client" << endl;
        }
    } else {
        conn = std::make_shared<Connection>();
        server.registerConnection(conn);
        cout << "New client connects" << endl;
    }
}

int main(int argc, char* argv[])
{
        auto server = init(argc, argv);
        auto db = new PrimeDatabase(std::cout, std::cerr);

        while (true) {
            serve_one(server, *db);
        }
        return 0;
}
