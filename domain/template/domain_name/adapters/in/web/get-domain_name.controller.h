#ifndef GET_<DOMAIN_NAME>_CONTROLLER_H
#define GET_<DOMAIN_NAME>_CONTROLLER_H

#include <string>

#include "crow.h"

class Get<DomainName>InputPort;

class Get<DomainName>Controller {
public:
	Get<DomainName>Controller(Get<DomainName>InputPort* serivce);

	void handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id);

private:
	Get<DomainName>InputPort* m_service;
};

#endif // !GET_<DOMAIN_NAME>S_CONTROLLER_H
