#include "add-<domainName>.service.h"

#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Add<DomainName>Service::Add<DomainName>Service(<DomainName>RepositoryOutputPort* repository) : m_repository(repository) {
}

/*!
********************************************************************************
\reimp
********************************************************************************
*/
std::expected<<DomainName>, Add<DomainName>Error> Add<DomainName>Service::workWith() {
	
	<DomainName> <domainName>;

	auto created<DomainName> = m_repository->save(<domainName>);
	if (!created<DomainName>.has_value()) {
		return std::unexpected(Add<DomainName>Error::AlreadyExists);
	}

	return created<DomainName>.value();
}