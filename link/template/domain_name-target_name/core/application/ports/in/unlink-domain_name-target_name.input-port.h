#ifndef UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H
#define UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H

#include <string>
#include <expected>

enum class Unlink<DomainName><TargetName>Error {
    <DomainName>NotFound,
    <TargetName>NotFound
};

class Unlink<DomainName><TargetName>InputPort {
public:
	virtual std::expected<bool, Unlink<DomainName><TargetName>Error> workWith(const std::string& <domainName>Id, const std::string& <targetName>Id) = 0;
};

#endif // !UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_INPUT_PORT_H
