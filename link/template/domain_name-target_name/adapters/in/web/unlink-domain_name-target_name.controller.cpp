#include "unlink-<domainName>-<targetName>.controller.h"
#include "<domainName>-<targetName>/core/application/ports/in/unlink-<domainName>-<targetName>.input-port.h"

Unlink<DomainName><TargetName>Controller::Unlink<DomainName><TargetName>Controller(Unlink<DomainName><TargetName>InputPort* service) : m_service(service) {
}

void Unlink<DomainName><TargetName>Controller::handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id, const std::string& <targetName>Id) {

	// remove
	auto result = m_service->workWith(<domainName>Id, <targetName>Id);
	if (!result.has_value() && result.error() == Unlink<DomainName><TargetName>Error::<DomainName>NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<DomainName> not found";
		res.end();
		return;
	}

	if (!result.has_value() && result.error() == Unlink<DomainName><TargetName>Error::<TargetName>NotFound) {
		res.code = crow::status::NOT_FOUND;
		res.body = "<TargetName> not found";
		res.end();
		return;
	}

	// response
	res.code = crow::status::NO_CONTENT;
	res.body = "<TargetName> unlinked successfully";
	res.end();
}
