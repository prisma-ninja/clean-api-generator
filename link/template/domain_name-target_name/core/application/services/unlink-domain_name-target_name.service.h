#ifndef UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H
#define UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H

#include "<domainName>-<targetName>/core/application/ports/in/unlink-<domainName>-<targetName>.input-port.h"

class <DomainName>RepositoryOutputPort;
class <TargetName>RepositoryOutputPort;
class <DomainName><TargetName>RepositoryOutputPort;

class Unlink<DomainName><TargetName>Service : public Unlink<DomainName><TargetName>InputPort {
public:
	Unlink<DomainName><TargetName>Service(<DomainName>RepositoryOutputPort* <domainName>Repository, <TargetName>RepositoryOutputPort* <targetName>Repository, <DomainName><TargetName>RepositoryOutputPort* <domainName><TargetName>Repository); 

	std::expected<bool, Unlink<DomainName><TargetName>Error> workWith(const std::string& <domainName>Id, const std::string& <targetName>Id) override;

private:
	<DomainName>RepositoryOutputPort* m_<domainName>Repository;
	<TargetName>RepositoryOutputPort* m_<targetName>Repository;
	<DomainName><TargetName>RepositoryOutputPort* m_<domainName><TargetName>Repository;
};


#endif // !UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H
