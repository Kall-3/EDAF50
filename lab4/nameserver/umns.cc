#include <iostream>
#include <fstream>
#include "umns.h"
#include "nameserverinterface.h"

UMNS::UMNS() {
    this->name_server = {};

    /*
    std::ifstream ifs("nameserverdata.txt");

    if (!ifs) {
        std::cerr << "Cannot open file nameserverdata.txt" << std::endl;
    }

    HostName host;
    IPAddress address;
    while (ifs >> host >> address) {
        this->name_server.insert({host, address});
    }

    if (ifs.fail() && !ifs.eof()) {
        std::cerr << "Error reading file nameserverdata.txt" << std::endl;
    }
    */
}

void UMNS::insert(const HostName& host, const IPAddress& address) {
    this->name_server.insert({host, address});
}

bool UMNS::remove(const HostName& host) {
    return this->name_server.erase(host);
}

IPAddress UMNS::lookup(const HostName& host) const {
    auto it = this->name_server.find(host);

    if (it != this->name_server.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}
