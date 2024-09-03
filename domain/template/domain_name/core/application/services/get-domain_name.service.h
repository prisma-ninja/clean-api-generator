#ifndef GET_<DOMAIN_NAME>_SERVICE_H
#define GET_<DOMAIN_NAME>_SERVICE_H

#include "<domainName>/core/application/ports/in/get-<domainName>.input-port.h"

class <DomainName>RepositoryOutputPort;

class Get<DomainName>Service : public Get<DomainName>InputPort {
public:
	Get<DomainName>Service(<DomainName>RepositoryOutputPort* repository); 

	std::expected<<DomainName>, Get<DomainName>Error> workWith(const std::string& <domainName>Id) override;

private:
	<DomainName>RepositoryOutputPort* m_repository;
};


#endif // !GET_<DOMAIN_NAME>_SERVICE_H
