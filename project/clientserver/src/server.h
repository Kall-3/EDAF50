/* A server listens to a port and handles multiple connections */
#ifndef SERVER_H
#define SERVER_H
#include <memory>
#include <vector>
#include "connection.h"
#include "database/primeDatabase.cc"

static int pending_socket = -1;

class Server {
    public:
        int my_socket;
        std::vector<std::shared_ptr<Connection>> connections;
        PrimeDatabase database;

        /* Creates a server that listens to a port */
        explicit Server(int port);

        /* Removes all registered connections */
        virtual ~Server();

        /* Returns true if the server has been initialized correctly */
        bool isReady() const;

        /* Waits for activity on the port. Returns a previously registered
        connection object if an existing client wishes to communicate,
        nullptr if a new client wishes to communicate */
        std::shared_ptr<Connection> waitForActivity() const;

        /* Registers a new connection */
        void registerConnection(const std::shared_ptr<Connection>& conn);

        /* Deregisters a connection */
        void deregisterConnection(const std::shared_ptr<Connection>& conn);

        /* Print error message */
        void error(const char* msg) const;

        /* Servers cannot be copied */
        Server(const Server&) = delete;
        Server& operator=(const Server&) = delete;
        Server& operator=(Server&&) = delete;
        Server(Server&&);
        
        /* TEMPS */
};
#endif
