#include "add-<domainName>.controller.h"

#include <regex>

#include "<domainName>/core/application/ports/in/add-<domainName>.input-port.h"

/*!
********************************************************************************
********************************************************************************
*/
Add<DomainName>Controller::Add<DomainName>Controller(Add<DomainName>InputPort* service) : m_service(service) {
}

/*!
********************************************************************************
\brief Adds a <domainName> to <domainName>s resource
********************************************************************************
*/
void Add<DomainName>Controller::handle(const crow::request& req, crow::response& res) {

	// get <domainName> from request
	auto body = crow::json::load(req.body);
	if (!body) {
		res.code = crow::status::BAD_REQUEST;
		res.body = "Cannot decode request body";
		res.end();
		return;
	}

	// check parameters
	/*bool isComplete = body.has("xx") ;
	if (!isComplete) {
		res.code = crow::status::BAD_REQUEST;
		res.body = "At least one parameter is missing";
		res.end();
		return;
	}*/

	// add <domainName> with service
	auto result = m_service->workWith(/*body["xx"].s()*/);
	if (!result.has_value() && result.error() == Add<DomainName>Error::AlreadyExists) {
		res.code = crow::status::CONFLICT;
		res.body = "<DomainName> already exists";
		res.end();
		return;
	}

	// respond with <domainName>
	<DomainName> created<DomainName> = result.value();
	crow::json::wvalue response;
	response["id"] = created<DomainName>.id;
	//response["xx"] = created<DomainName>.xx;

	res.code = crow::status::CREATED;
	res.body = response.dump();
	res.end();
}