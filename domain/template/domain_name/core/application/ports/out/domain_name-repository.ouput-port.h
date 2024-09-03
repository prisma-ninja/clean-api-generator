#ifndef <DOMAIN_NAME>_REPOSITORY_OUTPUT_PORT_H
#define <DOMAIN_NAME>_REPOSITORY_OUTPUT_PORT_H

#include <vector>
#include <optional>
#include "<domainName>/core/domain/<domainName>.h"

struct <DomainName>Filter {
    std::optional<std::string> filed;
};

class <DomainName>RepositoryOutputPort {
public:
	virtual std::optional<<DomainName>> save(const <DomainName>& <domainName>) = 0;
	virtual std::vector<<DomainName>> get<DomainName>s(const <DomainName>Filter& filter = {}) = 0;
	virtual std::optional<<DomainName>> get<DomainName>(const std::string& <domainName>Id) = 0;
	virtual bool remove(const std::string& <domainName>Id) = 0;
};
#endif // !<DOMAIN_NAME>_REPOSITORY_OUTPUT_PORT_H
