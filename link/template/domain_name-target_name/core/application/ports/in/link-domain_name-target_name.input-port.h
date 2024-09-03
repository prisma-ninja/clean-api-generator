#ifndef LINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H
#define LINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H

#include <string>
#include <expected>

#include "<targetName>/core/domain/<targetName>.h"
#include "<domainName>/core/domain/<domainName>.h" // fix useless one ?

enum class Link<DomainName><TargetName>Error {
    AlreadyLinked,
    <DomainName>NotFound,
    <TargetName>NotFound
};

class Link<DomainName><TargetName>InputPort {
public:
	virtual std::expected<<DomainName>, Link<DomainName><TargetName>Error> workWith(const std::string& <domainName>Id, const std::string& <targetName>Id) = 0;
};

#endif // !LINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H
