#include <iostream>
#include <fstream>
#include <utility>
#include "mns.h"
#include "nameserverinterface.h"

MNS::MNS() {
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

void MNS::insert(const HostName& host, const IPAddress& address) {
    this->name_server.insert({host, address});
}

bool MNS::remove(const HostName& host) {
    return this->name_server.erase(host);
}

IPAddress MNS::lookup(const HostName& host) const {
    auto it = this->name_server.find(host);

    if (it != this->name_server.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}
