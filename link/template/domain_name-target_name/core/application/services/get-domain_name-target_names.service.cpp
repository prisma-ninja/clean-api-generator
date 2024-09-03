#include "get-<domainName>-<targetName>s.service.h"
#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"
#include "<targetName>/core/application/ports/out/<targetName>-repository.ouput-port.h"
#include "<domainName>-<targetName>/core/application/ports/out/<domainName>-<targetName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Get<DomainName><TargetName>sService::Get<DomainName><TargetName>sService(<DomainName>RepositoryOutputPort* <domainName>Repository, <TargetName>RepositoryOutputPort* <targetName>Repository, <DomainName><TargetName>RepositoryOutputPort* <domainName><TargetName>Repository) : 
	m_<domainName>Repository(<domainName>Repository),
	m_<targetName>Repository(<targetName>Repository),
	m_<domainName><TargetName>Repository(<domainName><TargetName>Repository) {
}

/*!
********************************************************************************
\reimp Return <domainName>s
********************************************************************************
*/
std::expected<std::vector<<TargetName>>, Get<DomainName><TargetName>sError> Get<DomainName><TargetName>sService::workWith(const std::string& <domainName>Id) {
	
	auto found<DomainName> = m_<domainName>Repository->get<DomainName>(<domainName>Id);
	if (!found<DomainName>.has_value()) {
		return std::unexpected(Get<DomainName><TargetName>sError::<DomainName>NotFound);
	}

	return m_<domainName><TargetName>Repository->get<DomainName><TargetName>s(found<DomainName>.value());
}