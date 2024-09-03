#include "link-<domainName>-<targetName>.controller.h"

#include <regex>

#include "<domainName>-<targetName>/core/application/ports/in/link-<domainName>-<targetName>.input-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Link<DomainName><TargetName>Controller::Link<DomainName><TargetName>Controller(Link<DomainName><TargetName>InputPort* service) : m_service(service) {
}

/*!
********************************************************************************
\brief Links a <targetName> to <domainName>
********************************************************************************
*/
void Link<DomainName><TargetName>Controller::handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id) {

	// get <targetName> from request
	auto body = crow::json::load(req.body);
	if (!body) {
		res.code = crow::status::BAD_REQUEST;
		res.body = "Cannot decode request body";
		res.end();
		return;
	}

	// check parameters
	bool isComplete = body.has("<targetName>Id") ;
	if (!isComplete) {
		res.code = crow::status::BAD_REQUEST;
		res.body = "At least one parameter is missing";
		res.end();
		return;
	}

	// add <targetName> with service
	auto result = m_service->workWith(<domainName>Id, body["<targetName>Id"].s());
	if (!result.has_value() && result.error() == Link<DomainName><TargetName>Error::AlreadyLinked) {
		res.code = crow::status::CONFLICT;
		res.body = "<TargetName> already linked to <DomainName>";
		res.end();
		return;
	}

	if (!result.has_value() && result.error() == Link<DomainName><TargetName>Error::<DomainName>NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<DomainName> not found";
		res.end();
		return;
	}

	if (!result.has_value() && result.error() == Link<DomainName><TargetName>Error::<TargetName>NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<TargetName> not found";
		res.end();
		return;
	}

	// respond with <domainName>
	<DomainName> linked<DomainName> = result.value();
	crow::json::wvalue response;
	response["id"] = linked<DomainName>.id;
	//response["xx"] = linked<DomainName>.xx;

	res.code = crow::status::CREATED;
	res.body = response.dump();
	res.end();
}