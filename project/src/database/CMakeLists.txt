target_sources(clientserver
    INTERFACE
        database.h
    PRIVATE
        primeDatabase.cc
        newsgroup.cc
        article.cc
)
