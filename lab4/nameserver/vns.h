#include <string>
#include <utility>
#include <vector>
#include "nameserverinterface.h"

class VNS : public NameServerInterface {
public:
    VNS();

    /* Inherited functions override */
	void insert(const HostName& host, const IPAddress& address) override;
	bool remove(const HostName& host) override;
	IPAddress lookup(const HostName& host) const override;

private:
    /* Member values */
    std::vector<std::pair<HostName, IPAddress>> name_server;
};
