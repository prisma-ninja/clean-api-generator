#ifndef REMOVE_<DOMAIN_NAME>_SERVICE_H
#define REMOVE_<DOMAIN_NAME>_SERVICE_H

#include "<domainName>/core/application/ports/in/remove-<domainName>.input-port.h"

class <DomainName>RepositoryOutputPort;

class Remove<DomainName>Service : public Remove<DomainName>InputPort {
public:
	Remove<DomainName>Service(<DomainName>RepositoryOutputPort* repository);

	std::expected<bool, Remove<DomainName>Error> workWith(const std::string& <domainName>Id) override;

private:
	<DomainName>RepositoryOutputPort* m_repository;
};


#endif // !REMOVE_<DOMAIN_NAME>_SERVICE_H
