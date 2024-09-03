#ifndef <DOMAIN_NAME>_REPOSITORY_IN_MEMORY_H
#define <DOMAIN_NAME>_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"

class <DomainName>RepositoryInMemory : public <DomainName>RepositoryOutputPort {
public:
	<DomainName>RepositoryInMemory();

	std::optional<<DomainName>> save(const <DomainName>& <domainName>) override;
	std::vector<<DomainName>> get<DomainName>s(const <DomainName>Filter& filter = {}) override;
	std::optional<<DomainName>> get<DomainName>(const std::string& <domainName>Id);
	bool remove(const std::string& <domainName>Id);

private:
	bool <domainName>IdExists(const std::string& <domainName>Id) const;

private:
	std::vector<<DomainName>> m_<domainName>s;
};

#endif // !<DOMAIN_NAME>_REPOSITORY_IN_MEMORY_H
