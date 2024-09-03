#include "get-<domainName>.service.h"

#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Get<DomainName>Service::Get<DomainName>Service(<DomainName>RepositoryOutputPort* repository) : m_repository(repository) {
}

/*!
********************************************************************************
\reimp
********************************************************************************
*/
std::expected<<DomainName>, Get<DomainName>Error> Get<DomainName>Service::workWith(const std::string& <domainName>Id) {

	auto found<DomainName> = m_repository->get<DomainName>(<domainName>Id);
	if (!found<DomainName>.has_value()) {
		return std::unexpected(Get<DomainName>Error::NotFound);
	}

	return found<DomainName>.value();
}