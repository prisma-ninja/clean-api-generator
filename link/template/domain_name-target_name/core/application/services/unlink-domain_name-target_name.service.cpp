#include "unlink-<domainName>-<targetName>.service.h"
#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"
#include "<targetName>/core/application/ports/out/<targetName>-repository.ouput-port.h"
#include "<domainName>-<targetName>/core/application/ports/out/<domainName>-<targetName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Unlink<DomainName><TargetName>Service::Unlink<DomainName><TargetName>Service(<DomainName>RepositoryOutputPort* <domainName>Repository, <TargetName>RepositoryOutputPort* <targetName>Repository, <DomainName><TargetName>RepositoryOutputPort* <domainName><TargetName>Repository) : 
	m_<domainName>Repository(<domainName>Repository),
	m_<targetName>Repository(<targetName>Repository),
	m_<domainName><TargetName>Repository(<domainName><TargetName>Repository) {
}

/*!
********************************************************************************
\reimp
********************************************************************************
*/
std::expected<bool, Unlink<DomainName><TargetName>Error> Unlink<DomainName><TargetName>Service::workWith(const std::string& <domainName>Id, const std::string& <targetName>Id) {

	auto found<DomainName> = m_<domainName>Repository->get<DomainName>(<domainName>Id);
	if (!found<DomainName>.has_value()) {
		return std::unexpected(Unlink<DomainName><TargetName>Error::<DomainName>NotFound);
	}

	auto found<TargetName> = m_<targetName>Repository->get<TargetName>(<targetName>Id);
	if (!found<TargetName>.has_value()) {
		return std::unexpected(Unlink<DomainName><TargetName>Error::<TargetName>NotFound);
	}

	return m_<domainName><TargetName>Repository->unlink(found<DomainName>.value(), found<TargetName>.value());
}