target_sources(clientserver
    PRIVATE
        connection.cc
        server.cc
        messagehandler.cc
)

add_subdirectory(clientserver)