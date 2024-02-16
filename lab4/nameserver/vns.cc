#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include "vns.h"
#include "nameserverinterface.h"

VNS::VNS() {
    /*
    this->name_server = {};
    // name_server.resize(250000);

    std::ifstream ifs("nameserverdata.txt");

    if (!ifs) {
        std::cerr << "Cannot open file nameserverdata.txt" << std::endl;
    }

    HostName host;
    IPAddress address;
    while (ifs >> host >> address) {
        this->name_server.push_back(std::make_pair(host, address));
    }

    if (ifs.fail() || !ifs.eof()) {
        std::cerr << "Error reading file nameserverdata.txt" << std::endl;
    }
    */
}

void VNS::insert(const HostName& host, const IPAddress& address) {
    this->name_server.push_back(std::make_pair(host, address));
}

bool VNS::remove(const HostName& host) {
    IPAddress target = lookup(host);
    if (target != NON_EXISTING_ADDRESS) {
        this->name_server[target].second = NON_EXISTING_ADDRESS;
        return true;
    } else {
        return false;
    }
}

IPAddress VNS::lookup(const HostName& host) const {
    auto it = std::find_if(this->name_server.begin(), this->name_server.end(), 
            [host](std::pair<HostName, IPAddress> p) {
                return p.first == host;
            });

    if (it != this->name_server.end()) {
        return IPAddress(it->second);
    } else {
        return NON_EXISTING_ADDRESS;
    }
}
