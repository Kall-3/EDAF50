#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include "hns.h"
#include "nameserverinterface.h"

HNS::HNS(size_t size) : size(size), load_factor(0), max_load_factor(0.7) {
    this->size = size;
    this->name_server.resize(size, std::vector<std::pair<HostName, IPAddress>>(1, std::make_pair("", NON_EXISTING_ADDRESS)));
}

void HNS::insert(const HostName& host, const IPAddress& address) {
    std::size_t idx = std::hash<HostName>{}(host) % this->size;

    if (load_factor >= max_load_factor) {
        rehash();
    }
    load_factor += (1.0/size);

    if (this->name_server[idx][0].second == NON_EXISTING_ADDRESS) {
        this->name_server[idx][0] = std::make_pair(host, address);
    } else {
        // std::cout << "Hashing collision on index " << idx << std::endl;
        this->name_server[idx].push_back(std::make_pair(host, address));
    }
}

bool HNS::remove(const HostName& host) {
    std::size_t idx = std::hash<HostName>{}(host) % this->size;

    // Find if bucket at hash index is empty
    if (this->name_server[idx][0].second != NON_EXISTING_ADDRESS) {
        // Go through bucket and remove element
        for (auto element : this->name_server[idx]) {
            if (element.first == host) {
                element.second = NON_EXISTING_ADDRESS;
                return true;
            }
        }
    }
    return false;
}

IPAddress HNS::lookup(const HostName& host) const {
    std::size_t idx = std::hash<std::string>{}(host) % this->size;

    if (this->name_server[idx][0].second != NON_EXISTING_ADDRESS) {
        // Find element in bucket and return
        for (auto element : this->name_server[idx]) {
            if (element.first == host) {
                return element.second;
            }
        }
    }
    return NON_EXISTING_ADDRESS;
}

void HNS::rehash() {

    // Double capacity
    this->size *= 2;
    this->load_factor = static_cast<float>(std::count_if(this->name_server.begin(), this->name_server.end(), [](std::vector<std::pair<HostName, IPAddress>> v){ return (v[0].second != NON_EXISTING_ADDRESS) ? v.size() : 0; })) / this->size;

    std::vector<std::vector<std::pair<HostName, IPAddress>>> new_name_server(this->size, std::vector<std::pair<HostName, IPAddress>>(1, std::make_pair("", NON_EXISTING_ADDRESS)));

    int tot_elements = 0, collisions = 0;

    for (auto bucket : this->name_server) {
        for (auto element : bucket) {
            tot_elements += 1;

            std::size_t idx = std::hash<std::string>{}(element.first) % this->size;

            if (new_name_server[idx][0].second == NON_EXISTING_ADDRESS) {
                new_name_server[idx][0] = element;
            } else {
                new_name_server[idx].push_back(element);
                collisions += 1;
            }
        }
    }

    this->name_server = std::move(new_name_server);
}
