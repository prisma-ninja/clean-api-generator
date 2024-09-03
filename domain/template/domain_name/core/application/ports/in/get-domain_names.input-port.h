#ifndef GET_<DOMAIN_NAME>S_INPUT_PORT_H
#define GET_<DOMAIN_NAME>S_INPUT_PORT_H

#include <vector>
#include "<domainName>/core/domain/<domainName>.h"

class Get<DomainName>sInputPort {
public:
	virtual std::vector<<DomainName>> workWith() = 0;
};

#endif // !GET_<DOMAIN_NAME>S_INPUT_PORT_H
