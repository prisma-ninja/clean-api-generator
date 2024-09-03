#include "<domainName>.repository.in-memory.h"

#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <cstdint>

namespace {
std::string generateUid() {
	static uint64_t uid = 0;

	uid++;
	return std::to_string(uid);
}
}

/*!
********************************************************************************
********************************************************************************
*/
<DomainName>RepositoryInMemory::<DomainName>RepositoryInMemory() {
}

/*!
********************************************************************************
\brief Saves a <domainName>
\param <domainName>
********************************************************************************
*/
std::optional<<DomainName>> <DomainName>RepositoryInMemory::save(const <DomainName>& <domainName>) {

	<DomainName> <domainName>ToAdd = <domainName>;
	<domainName>ToAdd.id = generateUid();
	m_<domainName>s.push_back(<domainName>ToAdd);
	return <domainName>ToAdd;
}

/*!
********************************************************************************
\brief Gets all <domainName> matching filter
\param <domainName>
********************************************************************************
*/
std::vector<<DomainName>> <DomainName>RepositoryInMemory::get<DomainName>s(const <DomainName>Filter& filter) {

	/*bool emptyFilter = !filter.xx.has_value();
	if (emptyFilter) {
		return m_<domainName>s;
	}*/
	return m_<domainName>s;

	/*
	std::vector<std::function<bool(const <DomainName>&)>> filters;

	if (filter.xx.has_value()) {
		std::string xx = filter.xx.value();
		filters.push_back([xx](const <DomainName>& <domainName>) { return <domainName>.xx == xx; });
	}

	std::vector<<DomainName>> result;

	for (auto it = m_<domainName>s.begin(); it != m_<domainName>s.end(); ++it) {
		if (std::all_of(std::begin(filters), std::end(filters), [it](const auto& filter) { return filter(*it); })) {
			result.push_back(*it);
		}
	}
	
	return result;*/
}

/*!
********************************************************************************
\brief Gets <domainName> with specific <domainName>Id
\param <domainName>Id
********************************************************************************
*/
std::optional<<DomainName>> <DomainName>RepositoryInMemory::get<DomainName>(const std::string& <domainName>Id) {

	if (!<domainName>IdExists(<domainName>Id)) {
		return {};
	}

	auto it = std::find_if(m_<domainName>s.cbegin(), m_<domainName>s.cend(), [&](const <DomainName>& <domainName>) {
		return <domainName>Id == <domainName>.id;
		});
	return *it;
}

/*!
********************************************************************************
\brief Removes <domainName>
********************************************************************************
*/
bool <DomainName>RepositoryInMemory::remove(const std::string& <domainName>Id) {
	
	if (!<domainName>IdExists(<domainName>Id)) {
		return false;
	}

	std::erase_if(m_<domainName>s, [<domainName>Id](<DomainName> <domainName>) { return <domainName>.id == <domainName>Id; });
	return true;
}

/*!
********************************************************************************
\return True if the <domainName> id exists
********************************************************************************
*/
bool <DomainName>RepositoryInMemory::<domainName>IdExists(const std::string& <domainName>Id) const {
	auto it = std::find_if(m_<domainName>s.cbegin(), m_<domainName>s.cend(), [&](const <DomainName>& <domainName>) {
		return <domainName>Id == <domainName>.id;
		});

	return it != m_<domainName>s.end();
}
