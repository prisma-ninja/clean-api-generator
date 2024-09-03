#ifndef GET_<DOMAIN_NAME>S_CONTROLLER_H
#define GET_<DOMAIN_NAME>S_CONTROLLER_H

#include <string>

#include "crow.h"

class Get<DomainName>sInputPort;

class Get<DomainName>sController {
public:
	Get<DomainName>sController(Get<DomainName>sInputPort* serivce);

	void handle(const crow::request& req, crow::response& res);

private:
	Get<DomainName>sInputPort* m_service;
};

#endif // !GET_<DOMAIN_NAME>S_CONTROLLER_H
