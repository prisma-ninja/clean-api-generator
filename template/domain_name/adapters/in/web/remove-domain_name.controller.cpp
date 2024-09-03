#include "remove-<domainName>.controller.h"
#include "<domainName>/core/application/ports/in/remove-<domainName>.input-port.h"

Remove<DomainName>Controller::Remove<DomainName>Controller(Remove<DomainName>InputPort* service) : m_service(service) {
}

void Remove<DomainName>Controller::handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id) {

	// remove
	auto result = m_service->workWith(<domainName>Id);
	if (!result.has_value() && result.error() == Remove<DomainName>Error::NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<DomainName> not found";
		res.end();
		return;
	}

	// response
	res.code = crow::status::NO_CONTENT;
	res.body = "<DomainName> deleted successfully";
	res.end();
}
