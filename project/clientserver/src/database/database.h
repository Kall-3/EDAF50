#ifndef DATABASE_H
#define DATABASE_H
#include "newsgroup.h"
#include <unordered_map>

class DatabaseInterface {
public:

    // virtual functions - to be implemented by derived classes

    // Virtual destructor - to allow derived class destructors to be called
    virtual ~DatabaseInterface() {}
};

#endif
