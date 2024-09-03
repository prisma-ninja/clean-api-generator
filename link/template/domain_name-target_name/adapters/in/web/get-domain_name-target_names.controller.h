#ifndef GET_<DOMAIN_NAME>_<TARGET_NAME>S_CONTROLLER_H
#define GET_<DOMAIN_NAME>_<TARGET_NAME>S_CONTROLLER_H

#include <string>

#include "crow.h"

class Get<DomainName><TargetName>sInputPort;

class Get<DomainName><TargetName>sController {
public:
	Get<DomainName><TargetName>sController(Get<DomainName><TargetName>sInputPort* serivce);

	void handle(const crow::request& req, crow::response& res, const std::string& <domainName>Id);

private:
	Get<DomainName><TargetName>sInputPort* m_service;
};

#endif // !GET_<DOMAIN_NAME>_<TARGET_NAME>S_CONTROLLER_H
