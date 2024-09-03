#ifndef UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H
#define UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H

#include <string>

#include "crow.h"

class Unlink<DomainName><TargetName>InputPort;

class Unlink<DomainName><TargetName>Controller {
public:
	Unlink<DomainName><TargetName>Controller(Unlink<DomainName><TargetName>InputPort* serivce);

	void handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id, const std::string& <targetName>Id);

private:
	Unlink<DomainName><TargetName>InputPort* m_service;
};

#endif // !UNLINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H
