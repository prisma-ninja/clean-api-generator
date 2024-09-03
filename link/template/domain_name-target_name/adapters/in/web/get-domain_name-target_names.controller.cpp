#include "get-<domainName>-<targetName>s.controller.h"
#include "<domainName>-<targetName>/core/application/ports/in/get-<domainName>-<targetName>s.input-port.h"

Get<DomainName><TargetName>sController::Get<DomainName><TargetName>sController(Get<DomainName><TargetName>sInputPort* service) : m_service(service) {
}

void Get<DomainName><TargetName>sController::handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id) {

	// fetch
	auto result = m_service->workWith(<domainName>Id);
	if (!result.has_value() && result.error() == Get<DomainName><TargetName>sError::<DomainName>NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<DomainName> not found";
		res.end();
		return;
	}

	// response
	std::vector<<TargetName>> <targetName>s = result.value();
	crow::json::wvalue::list <targetName>List;
	for (const <TargetName>& <targetName> : <targetName>s) {
		crow::json::wvalue json<TargetName>;
		json<TargetName>["id"] = <targetName>.id;
		<targetName>List.push_back(json<TargetName>);
	}
	crow::json::wvalue response = <targetName>List;
	
	res.code = crow::status::OK;
	res.body = response.dump();
	res.end();
}
