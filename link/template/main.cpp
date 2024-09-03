#include <crow.h>

// <DomainName><TargetName>
#include "<domainName>-<targetName>/core/application/ports/out/<domainName>-<targetName>-repository.ouput-port.h"
#include "<domainName>-<targetName>/adapters/out/persistence/<domainName>-<targetName>.repository.in-memory.h"

#include "<domainName>-<targetName>/core/application/services/link-<domainName>-<targetName>.service.h"
#include "<domainName>-<targetName>/adapters/in/web/link-<domainName>-<targetName>.controller.h"

#include "<domainName>-<targetName>/core/application/services/get-<domainName>-<targetName>s.service.h"
#include "<domainName>-<targetName>/adapters/in/web/get-<domainName>-<targetName>s.controller.h"

#include "<domainName>-<targetName>/core/application/services/unlink-<domainName>-<targetName>.service.h"
#include "<domainName>-<targetName>/adapters/in/web/unlink-<domainName>-<targetName>.controller.h"

int main(int argc, char* argv[]) {

	crow::SimpleApp app;

	// just for heath
	CROW_ROUTE(app, "/health")([]() {
		return "OK";
	});

	// <DomainName><TargetName>
	std::unique_ptr<<DomainName><TargetName>RepositoryOutputPort> <domainName><TargetName>Repository = std::make_unique<<DomainName><TargetName>RepositoryInMemory>();
	
	std::unique_ptr<Link<DomainName><TargetName>InputPort> link<DomainName><TargetName>InputPort = std::make_unique<Link<DomainName><TargetName>Service>(<domainName>Repository.get(), <targetName>Repository.get(), <domainName><TargetName>Repository.get());
	Link<DomainName><TargetName>Controller link<DomainName><TargetName>Controller(link<DomainName><TargetName>InputPort.get());

	std::unique_ptr<Unlink<DomainName><TargetName>InputPort> unlink<DomainName><TargetName>InputPort = std::make_unique<Unlink<DomainName><TargetName>Service>(<domainName>Repository.get(), <targetName>Repository.get(), <domainName><TargetName>Repository.get());
	Unlink<DomainName><TargetName>Controller unlink<DomainName><TargetName>Controller(unlink<DomainName><TargetName>InputPort.get());

	std::unique_ptr<Get<DomainName><TargetName>sInputPort> get<DomainName><TargetName>sInputPort = std::make_unique<Get<DomainName><TargetName>sService>(<domainName>Repository.get(), <targetName>Repository.get(), <domainName><TargetName>Repository.get());
	Get<DomainName><TargetName>sController get<DomainName><TargetName>sController(get<DomainName><TargetName>sInputPort.get());

	// <DomainName><TargetName>
	CROW_ROUTE(app, "/<domainName>s/<string>/<targetName>s")
	.methods("POST"_method)([&link<DomainName><TargetName>Controller](const crow::request& req, crow::response& res, const std::string& <domainName>Id) {
	link<DomainName><TargetName>Controller.handle(req, res, <domainName>Id);
		});

CROW_ROUTE(app, "/<domainName>s/<string>/<targetName>s/<string>")
	.methods("DELETE"_method)([&unlink<DomainName><TargetName>Controller](const crow::request& req, crow::response& res, const std::string& <domainName>Id, const std::string& <targetName>Id) {
	unlink<DomainName><TargetName>Controller.handle(req, res, <domainName>Id, <targetName>Id);
		});

CROW_ROUTE(app, "/<domainName>s/<string>/<targetName>s")([&get<DomainName><TargetName>sController](const crow::request& req, crow::response& res, const std::string& <domainName>Id) {
	get<DomainName><TargetName>sController.handle(req, res, <domainName>Id);
	});

	app.port(18080).run();

	return EXIT_SUCCESS;
}