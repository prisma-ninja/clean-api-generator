#include "get-<domainName>s.service.h"
#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Get<DomainName>sService::Get<DomainName>sService(<DomainName>RepositoryOutputPort* repository) : m_repository(repository) {
}

/*!
********************************************************************************
\reimp Return <domainName>s
********************************************************************************
*/
std::vector<<DomainName>> Get<DomainName>sService::workWith() {
	
	<DomainName>Filter filter;

	return m_repository->get<DomainName>s(filter);
}