#include "get-<domainName>.controller.h"
#include "<domainName>/core/application/ports/in/get-<domainName>.input-port.h"

Get<DomainName>Controller::Get<DomainName>Controller(Get<DomainName>InputPort* service) : m_service(service) {
}

void Get<DomainName>Controller::handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id) {

	// fetch
	auto result = m_service->workWith(<domainName>Id);
	if (!result.has_value() && result.error() == Get<DomainName>Error::NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<DomainName> not found";
		res.end();
		return;
	}

	// respond with found <domainName>
	<DomainName> found<DomainName> = result.value();
	crow::json::wvalue response;
	response["id"] = found<DomainName>.id;

	res.code = crow::status::OK;
	res.body = response.dump();
	res.end();
}
