#ifndef ADD_<DOMAIN_NAME>_CONTROLLER_H
#define ADD_<DOMAIN_NAME>_CONTROLLER_H

#include <string>

#include "crow.h"

class Add<DomainName>InputPort;

class Add<DomainName>Controller {
public:
	Add<DomainName>Controller(Add<DomainName>InputPort* serivce);

	void handle(const crow::request& req, crow::response& res);

private:
	Add<DomainName>InputPort* m_service;
};

#endif // !ADD_<DOMAIN_NAME>_CONTROLLER_H
