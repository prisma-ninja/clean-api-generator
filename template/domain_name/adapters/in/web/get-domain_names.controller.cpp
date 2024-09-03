#include "get-<domainName>s.controller.h"
#include "<domainName>/core/application/ports/in/get-<domainName>s.input-port.h"

Get<DomainName>sController::Get<DomainName>sController(Get<DomainName>sInputPort* service) : m_service(service) {
}

void Get<DomainName>sController::handle(const crow::request& req, crow::response& res) {

	// filters
	/*std::vector<std::string> key = req.url_params.keys();
	std::string xx;

	if (std::find(key.begin(), key.end(), "xx") != key.end()) {
		xx = req.url_params.get("xx");
	}*/

	// fetch
	std::vector<<DomainName>> <domainName>s = m_service->workWith(/*xx*/);

	// response
	crow::json::wvalue::list <domainName>List;
	for (const <DomainName>& <domainName> : <domainName>s) {
		crow::json::wvalue json<DomainName>;
		json<DomainName>["id"] = <domainName>.id;
		<domainName>List.push_back(json<DomainName>);
	}
	crow::json::wvalue response = <domainName>List;
	
	res.code = crow::status::OK;
	res.body = response.dump();
	res.end();
}
