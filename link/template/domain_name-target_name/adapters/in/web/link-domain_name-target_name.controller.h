#ifndef LINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H
#define LINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H

#include <string>

#include "crow.h"

class Link<DomainName><TargetName>InputPort;

class Link<DomainName><TargetName>Controller {
public:
	Link<DomainName><TargetName>Controller(Link<DomainName><TargetName>InputPort* serivce);

	void handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id);

private:
	Link<DomainName><TargetName>InputPort* m_service;
};

#endif // !LINK_<DOMAIN_NAME>_<TARGET_NAME>_CONTROLLER_H
