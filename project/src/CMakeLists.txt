cmake_minimum_required(VERSION 3.14)

add_subdirectory(database)

target_sources(clientserver
    PRIVATE
        connection.cc
        server.cc
        messagehandler.cc
)
