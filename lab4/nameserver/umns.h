#include "nameserverinterface.h"
#include <string>
#include <unordered_map>

class UMNS : public NameServerInterface {
public:
    UMNS ();

    /* Inherited functions override */
	void insert(const HostName& host, const IPAddress& address) override;
	bool remove(const HostName& host) override;
	IPAddress lookup(const HostName& host) const override;

private:
    /* Member values */
    std::unordered_map<HostName, IPAddress> name_server;
};
