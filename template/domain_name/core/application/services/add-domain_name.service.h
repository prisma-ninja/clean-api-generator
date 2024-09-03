#ifndef ADD_<DOMAIN_NAME>_SERVICE_H
#define ADD_<DOMAIN_NAME>_SERVICE_H

#include "<domainName>/core/application/ports/in/add-<domainName>.input-port.h"

class <DomainName>RepositoryOutputPort;

class Add<DomainName>Service : public Add<DomainName>InputPort {
public:
	Add<DomainName>Service(<DomainName>RepositoryOutputPort* repository); 

	std::expected<<DomainName>, Add<DomainName>Error> workWith() override;

private:
	<DomainName>RepositoryOutputPort* m_repository;
};


#endif // !ADD_<DOMAIN_NAME>_SERVICE_H
