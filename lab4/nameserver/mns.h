#include "nameserverinterface.h"
#include <map>
#include <string>

class MNS : public NameServerInterface {
public:
    MNS();

    /* Inherited functions override */
	void insert(const HostName& host, const IPAddress& address) override;
	bool remove(const HostName& host) override;
	IPAddress lookup(const HostName& host) const override;

private:
    /* Member values */
    std::map<HostName, IPAddress> name_server;
};
