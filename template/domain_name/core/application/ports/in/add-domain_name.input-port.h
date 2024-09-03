#ifndef ADD_<DOMAIN_NAME>_INPUT_PORT_H
#define ADD_<DOMAIN_NAME>_INPUT_PORT_H

#include <string>
#include <expected>

#include "<domainName>/core/domain/<domainName>.h"

enum class Add<DomainName>Error {
    AlreadyExists
};

class Add<DomainName>InputPort {
public:
	virtual std::expected<<DomainName>, Add<DomainName>Error> workWith() = 0;
};

#endif // !ADD_<DOMAIN_NAME>_INPUT_PORT_H
