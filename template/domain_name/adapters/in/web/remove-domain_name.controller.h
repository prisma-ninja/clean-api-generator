#ifndef REMOVE_<DOMAIN_NAME>_CONTROLLER_H
#define REMOVE_<DOMAIN_NAME>_CONTROLLER_H

#include <string>

#include "crow.h"

class Remove<DomainName>InputPort;

class Remove<DomainName>Controller {
public:
	Remove<DomainName>Controller(Remove<DomainName>InputPort* serivce);

	void handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id);

private:
	Remove<DomainName>InputPort* m_service;
};

#endif // !REMOVE_<DOMAIN_NAME>_CONTROLLER_H
