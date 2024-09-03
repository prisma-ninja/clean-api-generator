#ifndef LINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H
#define LINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H

#include <expected>

#include "<domainName>-<targetName>/core/application/ports/in/link-<domainName>-<targetName>.input-port.h"

class <DomainName>RepositoryOutputPort;
class <TargetName>RepositoryOutputPort;
class <DomainName><TargetName>RepositoryOutputPort;

class Link<DomainName><TargetName>Service : public Link<DomainName><TargetName>InputPort {
public:
	Link<DomainName><TargetName>Service(<DomainName>RepositoryOutputPort* <domainName>Repository, <TargetName>RepositoryOutputPort* <targetName>Repository, <DomainName><TargetName>RepositoryOutputPort* <domainName><TargetName>Repository); 

	std::expected<<DomainName>, Link<DomainName><TargetName>Error> workWith(const std::string& <domainName>Id, const std::string& <targetName>Id) override;

private:
	<DomainName>RepositoryOutputPort* m_<domainName>Repository;
	<TargetName>RepositoryOutputPort* m_<targetName>Repository;
	<DomainName><TargetName>RepositoryOutputPort* m_<domainName><TargetName>Repository;
};


#endif // !LINK_<DOMAIN_NAME>_<TARGET_NAME>_SERVICE_H
