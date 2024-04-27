#include <algorithm>
#include <cstddef>
#include <functional>
#include <utility>
#include <vector>
#include "hns.h"
#include "enums.h"

HashMap::HashMap(size_t size) : size(size), load_factor(0), max_load_factor(0.7) {
    this->size = size;
    this->articles.resize(size, std::vector<std::pair<ArticleName, Article>>(1, std::make_pair("", Article::Empty())));
}

void HashMap::insert(const ArticleName& title, const Article& article) {
    std::size_t idx = std::hash<ArticleName>{}(title) % this->size;

    if (load_factor >= max_load_factor) {
        rehash();
    }
    load_factor += (1.0/size);

    if (this->articles[idx][0].first == "") {
        this->articles[idx][0] = std::make_pair(title, article);
    } else {
        // std::cout << "Hashing collision on index " << idx << std::endl;
        this->articles[idx].push_back(std::make_pair(title, article));
    }
}

bool HashMap::remove(const ArticleName& id) {
    std::size_t idx = std::hash<ArticleName>{}(id) % this->size;

    if (articles[idx][0].first != "") {
        for (auto element : this->articles[idx]) {
            if (element.second.getID() == id) {
                return element.second;
            }
        }
        articles[idx] = std::vector<std::pair<ArticleName, Article>>(1, std::make_pair("", Article::Empty()));
        return true;
    }
    return false;
}

Article* HashMap::lookup(const ArticleName& host) const {
    std::size_t idx = std::hash<std::string>{}(host) % this->size;

    if (this->articles[idx][0].first != "") {
        // Find element in bucket and return
        for (auto element : this->name_server[idx]) {
            if (element.first == host) {
                return element.second;
            }
        }
    }
    return nullptr;
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
