#include "nameserverinterface.h"
#include <string>
#include <utility>
#include <vector>

class HNS : public NameServerInterface {
public:
    HNS (size_t size);

    /* Inherited functions override */
	void insert(const HostName& host, const IPAddress& address) override;
	bool remove(const HostName& host) override;
	IPAddress lookup(const HostName& host) const override;

private:
    /* Member values */
    int size;
    float load_factor;
    float max_load_factor;
    std::vector<std::vector<std::pair<HostName, IPAddress>>> name_server;

    /* Private member functions */
    void rehash();
};
