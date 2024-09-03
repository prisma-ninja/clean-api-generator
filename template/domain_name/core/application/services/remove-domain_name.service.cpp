#include "remove-<domainName>.service.h"

#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Remove<DomainName>Service::Remove<DomainName>Service(<DomainName>RepositoryOutputPort* repository) : m_repository(repository) {
}

/*!
********************************************************************************
\reimp
********************************************************************************
*/
std::expected<bool, Remove<DomainName>Error> Remove<DomainName>Service::workWith(const std::string& <domainName>Id) {

	if (!m_repository->remove(<domainName>Id)) {
		return std::unexpected(Remove<DomainName>Error::NotFound);
	}

	return true;
}