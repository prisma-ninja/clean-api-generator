#include "<domainName>-<targetName>.repository.in-memory.h"

#include <functional>
#include <algorithm>
#include <tuple>
#include <cstdint>


/*!
********************************************************************************
********************************************************************************
*/
<DomainName><TargetName>RepositoryInMemory::<DomainName><TargetName>RepositoryInMemory() {
}

/*!
********************************************************************************
\brief Links a <targetName> to a <domainName>
\param <domainName>
\param <targetName>
********************************************************************************
*/
std::optional<<DomainName>> <DomainName><TargetName>RepositoryInMemory::link(const <DomainName>& <domainName>, const <TargetName>& <targetName>) {

	m_<domainName><TargetName>s[<domainName>.id].push_back(<targetName>);
	return <domainName>;
}

/*!
********************************************************************************
\brief Gets all <domainName> matching filter
\param <domainName>
********************************************************************************
*/
std::vector<<TargetName>> <DomainName><TargetName>RepositoryInMemory::get<DomainName><TargetName>s(const <DomainName>& <domainName>) {
	return m_<domainName><TargetName>s[<domainName>.id];
}

/*!
********************************************************************************
\brief Gets <domainName> with specific <domainName>Id
\param <domainName>Id
********************************************************************************
*/
bool <DomainName><TargetName>RepositoryInMemory::unlink(const <DomainName>& <domainName>, const <TargetName>& <targetName>) {

	if (m_<domainName><TargetName>s.find(<domainName>.id) == m_<domainName><TargetName>s.end()) {
		return false;
	}

	auto it = std::find_if(m_<domainName><TargetName>s[<domainName>.id].begin(), m_<domainName><TargetName>s[<domainName>.id].end(), [<targetName>](<TargetName> tofind) { return <targetName>.id == tofind.id; });
	if (it == m_<domainName><TargetName>s[<domainName>.id].end()) {
		return false;
	}

	m_<domainName><TargetName>s[<domainName>.id].erase(it);
	return true;
}