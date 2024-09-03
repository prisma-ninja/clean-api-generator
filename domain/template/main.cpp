#include <crow.h>

// <DomainName>
#include "<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h"
#include "<domainName>/adapters/out/persistence/<domainName>.repository.in-memory.h"
#include "<domainName>/adapters/out/persistence/<domainName>.repository.sqlite3.h"

#include "<domainName>/core/application/services/add-<domainName>.service.h"
#include "<domainName>/adapters/in/web/add-<domainName>.controller.h"

#include "<domainName>/core/application/services/get-<domainName>s.service.h"
#include "<domainName>/adapters/in/web/get-<domainName>s.controller.h"

#include "<domainName>/core/application/services/get-<domainName>.service.h"
#include "<domainName>/adapters/in/web/get-<domainName>.controller.h"

#include "<domainName>/core/application/services/remove-<domainName>.service.h"
#include "<domainName>/adapters/in/web/remove-<domainName>.controller.h"

int main(int argc, char* argv[]) {

	crow::SimpleApp app;

	// just for heath
	CROW_ROUTE(app, "/health")([]() {
		return "OK";
	});

	// <DomainName>
	std::unique_ptr<<DomainName>RepositoryOutputPort> <domainName>Repository = std::make_unique<<DomainName>RepositoryInMemory>();
	
	std::unique_ptr<Add<DomainName>InputPort> add<DomainName>InputPort = std::make_unique<Add<DomainName>Service>(<domainName>Repository.get());
	Add<DomainName>Controller add<DomainName>Controller(add<DomainName>InputPort.get());

	std::unique_ptr<Get<DomainName>sInputPort> get<DomainName>sInputPort = std::make_unique<Get<DomainName>sService>(<domainName>Repository.get());
	Get<DomainName>sController get<DomainName>sController(get<DomainName>sInputPort.get());

	std::unique_ptr<Get<DomainName>InputPort> get<DomainName>InputPort = std::make_unique<Get<DomainName>Service>(<domainName>Repository.get());
	Get<DomainName>Controller get<DomainName>Controller(get<DomainName>InputPort.get());

	std::unique_ptr<Remove<DomainName>InputPort> remove<DomainName>InputPort = std::make_unique<Remove<DomainName>Service>(<domainName>Repository.get());
	Remove<DomainName>Controller remove<DomainName>Controller(remove<DomainName>InputPort.get());

	// <DomainName>
	CROW_ROUTE(app, "/<domainName>s")
		.methods("POST"_method)([&add<DomainName>Controller](const crow::request& req, crow::response& res) {
			add<DomainName>Controller.handle(req, res);
		});

	CROW_ROUTE(app, "/<domainName>s")([&get<DomainName>sController](const crow::request& req, crow::response& res) {
			get<DomainName>sController.handle(req, res);
		});

	CROW_ROUTE(app, "/<domainName>s/<string>")([&get<DomainName>Controller](const crow::request& req, crow::response& res, const std::string& <domainName>Id) {
			get<DomainName>Controller.handle(req, res, <domainName>Id);
		});

	CROW_ROUTE(app, "/<domainName>s/<string>")
		.methods("DELETE"_method)([&remove<DomainName>Controller](const crow::request& req, crow::response& res, const std::string& <domainName>Id) {
			remove<DomainName>Controller.handle(req, res, <domainName>Id);
		});

	app.port(18080).run();

	return EXIT_SUCCESS;
}