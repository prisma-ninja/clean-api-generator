#ifndef GET_<DOMAIN_NAME>_<TARGET_NAME>S_INPUT_PORT_H
#define GET_<DOMAIN_NAME>_<TARGET_NAME>S_INPUT_PORT_H

#include <vector>
#include <expected>
#include "<targetName>/core/domain/<targetName>.h"

enum class Get<DomainName><TargetName>sError {
    <DomainName>NotFound
};

class Get<DomainName><TargetName>sInputPort {
public:
	virtual std::expected<std::vector<<TargetName>>, Get<DomainName><TargetName>sError> workWith(const std::string& <domainName>Id) = 0;
};

#endif // !GET_<DOMAIN_NAME>_<TARGET_NAME>S_INPUT_PORT_H
