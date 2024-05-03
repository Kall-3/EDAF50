#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "connection.h"
#include "protocol.h"
#include <memory>
#include <string>

class MessageHandler {
public:
    MessageHandler() = default;
    ~MessageHandler() = default;

    Protocol readMessage(const std::shared_ptr<Connection>& conn);
    void sendMessage(const std::shared_ptr<Connection>& conn, Protocol message);
    void sendNumP(const std::shared_ptr<Connection>& conn, int N);
    void sendStringP(const std::shared_ptr<Connection>& conn, std::string message);
    int readNumP(const std::shared_ptr<Connection>& conn);
    std::string readStringP(const std::shared_ptr<Connection>& conn);

private:
    // const std::shared_ptr<Connection>& conn;
};

#endif
