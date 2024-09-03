#ifndef GET_<DOMAIN_NAME>_INPUT_PORT_H
#define GET_<DOMAIN_NAME>_INPUT_PORT_H

#include <expected>
#include "<domainName>/core/domain/<domainName>.h"

enum class Get<DomainName>Error {
	NotFound
};

class Get<DomainName>InputPort {
public:
	virtual std::expected<<DomainName>, Get<DomainName>Error> workWith(const std::string& <domainName>Id) = 0;
};

#endif // !GET_<DOMAIN_NAME>_INPUT_PORT_H
