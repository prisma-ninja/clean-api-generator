#ifndef REMOVE_<DOMAIN_NAME>_INPUT_PORT_H
#define REMOVE_<DOMAIN_NAME>_INPUT_PORT_H

#include <string>
#include <expected>

#include "<domainName>/core/domain/<domainName>.h"

enum class Remove<DomainName>Error {
    NotFound
};

class Remove<DomainName>InputPort {
public:
	virtual std::expected<bool, Remove<DomainName>Error> workWith(const std::string& <domainName>Id) = 0;
};

#endif // !REMOVE_<DOMAIN_NAME>_INPUT_PORT_H
