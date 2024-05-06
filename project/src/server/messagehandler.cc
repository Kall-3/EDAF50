#include "messagehandler.h"
#include "clientserverexceptions.h"

#include <memory>
#include <string>

Protocol MessageHandler::readMessage(const std::shared_ptr<Connection>& conn) {
    unsigned char byte = conn->read();
    return Protocol(byte);
}

void MessageHandler::sendMessage(const std::shared_ptr<Connection>& conn, Protocol message) {
    unsigned char byte = int(message);
    conn->write(byte);
}

void MessageHandler::sendNumP(const std::shared_ptr<Connection>& conn, int N) {
    unsigned char head = char(Protocol::PAR_NUM);
    conn->write(head);

    unsigned char byte1 = (N << 24);
    unsigned char byte2 = (N << 16);
    unsigned char byte3 = (N << 8);
    unsigned char byte4 = (N << 0);

    conn->write(byte1);
    conn->write(byte2);
    conn->write(byte3);
    conn->write(byte4);
}

void MessageHandler::sendStringP(const std::shared_ptr<Connection>& conn, std::string message) {
    unsigned char head = char(Protocol::PAR_STRING);
    conn->write(head);

    int N = message.size();

    unsigned char byte1 = (N >> 24) & 0xFF;
    unsigned char byte2 = (N >> 16) & 0xFF;
    unsigned char byte3 = (N >> 8) & 0xFF;
    unsigned char byte4 = N & 0xFF;

    conn->write(byte1);
    conn->write(byte2);
    conn->write(byte3);
    conn->write(byte4);

    for (char ch : message) {
        conn->write(ch);
    }
}

int MessageHandler::readNumP(const std::shared_ptr<Connection>& conn) {
    if (readMessage(conn) != Protocol::PAR_NUM) {
        throw ProtocolViolationException();
    }

    unsigned char byte1 = conn->read();
    unsigned char byte2 = conn->read();
    unsigned char byte3 = conn->read();
    unsigned char byte4 = conn->read();

    return (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | (byte4 << 0);
}

std::string MessageHandler::readStringP(const std::shared_ptr<Connection>& conn) {
    if (readMessage(conn) != Protocol::PAR_STRING) {
        throw ProtocolViolationException();
    }

    unsigned char byte1 = conn->read();
    unsigned char byte2 = conn->read();
    unsigned char byte3 = conn->read();
    unsigned char byte4 = conn->read();
    int N = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | (byte4 << 0);

    std::string res = "";

    for (int i = 0; i < N; i++) {   // Signed or unsigned char for string +=
        res += (conn->read());
    }
    return res;
}
