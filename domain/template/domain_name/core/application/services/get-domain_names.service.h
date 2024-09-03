#ifndef GET_<DOMAIN_NAME>S_SERVICE_H
#define GET_<DOMAIN_NAME>S_SERVICE_H

#include "<domainName>/core/application/ports/in/get-<domainName>s.input-port.h"

class <DomainName>RepositoryOutputPort;

class Get<DomainName>sService : public Get<DomainName>sInputPort {
public:
	Get<DomainName>sService(<DomainName>RepositoryOutputPort* repository);

	std::vector<<DomainName>> workWith() override;

private:
	<DomainName>RepositoryOutputPort* m_repository;
};


#endif // !GET_<DOMAIN_NAME>_SERVICE_H
