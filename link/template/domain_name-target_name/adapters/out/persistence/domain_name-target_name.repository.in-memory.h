#ifndef <DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_IN_MEMORY_H
#define <DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_IN_MEMORY_H

#include <unordered_map>
#include "<domainName>-<targetName>/core/application/ports/out/<domainName>-<targetName>-repository.ouput-port.h"

class <DomainName><TargetName>RepositoryInMemory : public <DomainName><TargetName>RepositoryOutputPort {
public:
	<DomainName><TargetName>RepositoryInMemory();

	std::optional<<DomainName>> link(const <DomainName>& <domainName>, const <TargetName>& <targetName>) override;
	std::vector<<TargetName>> get<DomainName><TargetName>s(const <DomainName>& <domainName>) override;
	bool unlink(const <DomainName>& <domainName>, const <TargetName>& <targetName>) override;

private:
	std::unordered_map<std::string, std::vector<<TargetName>>> m_<domainName><TargetName>s;
};

#endif // !<DOMAIN_NAME>_<TARGET_NAME>_REPOSITORY_IN_MEMORY_H
