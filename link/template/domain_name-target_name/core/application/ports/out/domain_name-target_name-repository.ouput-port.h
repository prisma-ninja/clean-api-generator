#ifndef <DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_OUTPUT_PORT_H
#define <DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_OUTPUT_PORT_H

#include <vector>
#include <optional>
#include "<domainName>/core/domain/<domainName>.h"
#include "<targetName>/core/domain/<targetName>.h"

class <DomainName><TargetName>RepositoryOutputPort {
public:
	virtual std::optional<<DomainName>> link(const <DomainName>& <domainName>, const <TargetName>& <targetName>) = 0;
	virtual std::vector<<TargetName>> get<DomainName><TargetName>s(const <DomainName>& <domainName>) = 0;
	virtual bool unlink(const <DomainName>& <domainName>, const <TargetName>& <targetName>) = 0;
};

#endif // !<DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_OUTPUT_PORT_H
