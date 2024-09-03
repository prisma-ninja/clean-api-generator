#ifndef GET_<DOMAIN_NAME>_<TARGET_NAME>S_SERVICE_H
#define GET_<DOMAIN_NAME>_<TARGET_NAME>S_SERVICE_H

#include "<domainName>-<targetName>/core/application/ports/in/get-<domainName>-<targetName>s.input-port.h"

class <DomainName>RepositoryOutputPort;
class <TargetName>RepositoryOutputPort;
class <DomainName><TargetName>RepositoryOutputPort;

class Get<DomainName><TargetName>sService : public Get<DomainName><TargetName>sInputPort {
public:
	Get<DomainName><TargetName>sService(<DomainName>RepositoryOutputPort* <domainName>Repository, <TargetName>RepositoryOutputPort* <targetName>Repository, <DomainName><TargetName>RepositoryOutputPort* <domainName><TargetName>Repository);

	std::expected<std::vector<<TargetName>>, Get<DomainName><TargetName>sError> workWith(const std::string& <domainName>Id) override;

private:
	<DomainName>RepositoryOutputPort* m_<domainName>Repository;
	<TargetName>RepositoryOutputPort* m_<targetName>Repository;
	<DomainName><TargetName>RepositoryOutputPort* m_<domainName><TargetName>Repository;
};


#endif // !GET_<DOMAIN_NAME>_<TARGET_NAME>S_SERVICE_H
