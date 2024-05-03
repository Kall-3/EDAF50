#include "connection.h"
#include "connectionclosedexception.h"
#include "messagehandler.h"
#include "protocol.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

Connection init(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: myclient host-name port-number" << endl;
        exit(1);
    }
    int port = -1;
    try {
        port = std::stoi(argv[3]);
    } catch (std::exception& e) {
        cerr << "Wrong port number. " << e.what() << endl;
        exit(2);
    }

    Connection conn(argv[2], port);
    if (!conn.isConnected()) {
        cerr << "Connection attempt failed" << endl;
        exit(3);
    }

    return conn;
}

int app(const std::shared_ptr<Connection>& conn)
{
    auto mh = MessageHandler();
    cout << "Welcome! ";
    string input;
    int request;
    while (true) {
        
        // Handle input
        request = handleInput(input);
        
        try {
            switch (request) {
                // List all newsgroups
                case 1: {
                    mh.sendMessage(conn, Protocol::COM_LIST_NG);
                    mh.sendMessage(conn, Protocol::COM_END);
                    mh.readMessage(conn);   // ANS_LIST_NG

                    int nbr_ng = mh.readNumP(conn);

                    cout << nbr_ng << " total Newsgroups" << endl;

                    for (int i = 0; i < nbr_ng; i++) {
                        cout << "Id: " << mh.readNumP(conn) << "\tName: " << mh.readStringP(conn) << endl;
                    }
                    mh.readMessage(conn);   // ANS_END
                    break; }
                
                // Create new newsgroup
                case 2: {
                    cout << "Create Newsgroup, enter name: ";
                    string name;
                    cin >> name;
                    
                    mh.sendMessage(conn, Protocol::COM_CREATE_NG);
                    mh.sendStringP(conn, name);
                    mh.sendMessage(conn, Protocol::COM_END);

                    mh.readMessage(conn);   // ANS_CREATE_NG
                    auto ack = mh.readMessage(conn);

                    if (ack == Protocol::ANS_ACK) {
                        cout << "Newsgroup created." << endl;
                    } else {
                        cout << "Newsgroup with name " << name << " already exists." << endl;
                        mh.readMessage(conn);   // ERR_NG_ALREADY_EXISTS
                    }
                    mh.readMessage(conn);   // ANS_END
                    break; }
                
                // Remove existing newsgroup
                case 3: {
                    cout << "Delete Newsgroup, enter ID: ";
                    string input;
                    cin >> input;
                    
                    int id;
                    try {
                        id = std::stoi(input);
                    } catch (std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        exit(1);
                    }

                    mh.sendMessage(conn, Protocol::COM_DELETE_NG);
                    mh.sendNumP(conn, id);
                    mh.sendMessage(conn, Protocol::COM_END);

                    mh.readMessage(conn);   // ANS_DELETE_NG
                    auto ack = mh.readMessage(conn);

                    if (ack == Protocol::ANS_ACK) {
                        cout << "Newsgroup deleted." << endl;
                    } else {
                        cout << "Newsgroup with id " << id << " does not exist." << endl;
                        mh.readMessage(conn);   // ERR_NG_DOES_NOT_EXIST
                    }
                    mh.readMessage(conn);   // ANS_END
                    break; }
                
                // List all articles in selected newsgroup
                case 4: {
                    cout << "List Articles, enter newsgroup ID: ";
                    string input;
                    cin >> input;
                    
                    int id;
                    try {
                        id = std::stoi(input);
                    } catch (std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        // Do something
                    }

                    mh.sendMessage(conn, Protocol::COM_LIST_ART);
                    mh.sendNumP(conn, id);
                    mh.sendMessage(conn, Protocol::COM_END);

                    mh.readMessage(conn);   // ANS_LIST_ARTICLE
                    auto ack = mh.readMessage(conn); // ANS_ACK || ANS_NAK

                    if (ack == Protocol::ANS_ACK) {
                        int nbr_newsgroups;
                        cout << "Newsgroup deleted." << endl;
                    } else {
                        cout << "Newsgroup with id " << id << " does not exist." << endl;
                        mh.readMessage(conn);   // ERR_NG_DOES_NOT_EXIST
                    }
                    mh.readMessage(conn);   // ANS_END
                    
                    
                    break; }
                
                // Create new article in selected newsgroup
                case 5: {
                    cout << "Create article, enter title: ";
                    string title;
                    
                    break; }
                
                // Remove existing article from selected newsgroup
                case 6: {
                    cout << "Delete Article, enter Newsgroup ID: ";
                    string ng_input;
                    cin >> ng_input;
                    int ng_id;
                    try {
                        ng_id = std::stoi(ng_input);
                    } catch(std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        // Do something
                    }

                    cout << "Enter Article ID: ";
                    string a_input;
                    cin >> a_input;
                    int a_id;
                    try {
                        a_id = std::stoi(a_input);
                    } catch(std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        // Do something
                    }

                    mh.sendMessage(conn, Protocol::COM_DELETE_ART);
                    mh.sendNumP(conn, ng_id);
                    mh.sendNumP(conn, a_id);
                    mh.sendMessage(conn, Protocol::COM_END);

                    mh.readMessage(conn);   // ANS_DELETE_ART
                    auto ack = mh.readMessage(conn); // ANS_ACK || ANS_NAK

                    if (ack == Protocol::ANS_ACK) {
                        cout << "Article deleted from Newsgroup." << endl;
                    } else {
                        auto err_type = mh.readMessage(conn);   // ERR_NG_DOES_NOT_EXIST || ERR_ART_DOES_NOT_EXIST
                        if (err_type == Protocol::ERR_NG_DOES_NOT_EXIST) {
                            cout << "Newsgroup with id " << ng_id << " does not exist." << endl;
                        }
                        else {
                            cout << "Article with id " << a_id << " does not exist in the selected newsgroup." << endl;
                        }
                    }
                    mh.readMessage(conn);   // ANS_END
                    break; }
                
                // Get existing article from specified newsgroup
                case 7: {
                    cout << "Get Article, enter Newsgroup ID: ";
                    string ng_input;
                    cin >> ng_input;
                    int ng_id;
                    try {
                        ng_id = std::stoi(ng_input);
                    } catch(std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        // Do something
                    }

                    cout << "Enter Article ID: ";
                    string a_input;
                    cin >> a_input;
                    int a_id;
                    try {
                        a_id = std::stoi(a_input);
                    } catch(std::invalid_argument ex) {
                        cout << "Invalid ID, not an integer." << endl;
                        continue;
                    } catch (int e) {
                        // Do something
                    }

                    mh.sendMessage(conn, Protocol::COM_GET_ART);
                    mh.sendNumP(conn, ng_id);
                    mh.sendNumP(conn, a_id);
                    mh.sendMessage(conn, Protocol::COM_END);

                    mh.readMessage(conn);   // ANS_GET_ART
                    auto ack = mh.readMessage(conn); // ANS_ACK || ANS_NAK

                    if (ack == Protocol::ANS_ACK) {
                        string title = mh.readStringP(conn);
                        string author = mh.readStringP(conn);
                        string body = mh.readStringP(conn);
                        cout << "Title: " << title << "\n" << "Author: " << author << "\n" << body << endl;
                    }
                    else {
                        auto err_type = mh.readMessage(conn);   // ERR_NG_DOES_NOT_EXIST || ERR_ART_DOES_NOT_EXIST
                        if (err_type == Protocol::ERR_NG_DOES_NOT_EXIST) {
                            cout << "Newsgroup with id " << ng_id << " does not exist." << endl;
                        }
                        else {
                            cout << "Article with id " << a_id << " does not exist in the selected newsgroup." << endl;
                        }
                    }
                    mh.readMessage(conn); // ANS_END
                    
                    break; }
                
                // Test case to give the server incorrect message protocols
                case 8: {

                    break; }
                
                // Quit and disconnect
                case 9: {
                    cout << "Disconnecting client from server." << endl;
                    exit(0);
                    break; }
                
                default:
                    cout << "Invalid request" << endl;
                    break;
            };
        } catch (ConnectionClosedException&) {
            cout << " no reply from server. Exiting." << endl;
            return 1;
        }
        cout << endl;
    }
    cout << "\nexiting.\n";
    return 0;
}

int handleInput(string input) {
    int req;
    cout << "Enter request:\n 1. List Newsgroups\n 2. Create Newsgroup\n 3. Delete Newsgroup\n 4. List Articles\n 5. Create Article\n 6. Remove Article\n 7. Get Article\n 8. Try fooling server\n 9. Exit client" << endl;
    std::getline(cin, input);
    try {
        req = std::stoi(input);
    } catch (std::invalid_argument ex) {
        cerr << "Invalid input: " << input << endl;
        //continue;
    }
    return req;
}

void getIDs() {

}

void checkErrorType() {

}

int main(int argc, char* argv[])
{
    std::shared_ptr<Connection> conn = std::make_shared<Connection>(init(argc, argv));
    return app(conn);
}
