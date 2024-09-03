project(ProjectName)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package(SQLite3 REQUIRED)

set(${PROJECT_NAME}_<DOMAIN_NAME>_CORE_DOMAIN_HPP
	<domainName>/core/domain/<domainName>.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_IN_HPP
	<domainName>/core/application/ports/in/add-<domainName>.input-port.h
	<domainName>/core/application/ports/in/get-<domainName>s.input-port.h
	<domainName>/core/application/ports/in/get-<domainName>.input-port.h
	<domainName>/core/application/ports/in/remove-<domainName>.input-port.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_OUT_HPP
	<domainName>/core/application/ports/out/<domainName>-repository.ouput-port.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_HPP
	<domainName>/core/application/services/add-<domainName>.service.h
	<domainName>/core/application/services/get-<domainName>s.service.h
	<domainName>/core/application/services/get-<domainName>.service.h
	<domainName>/core/application/services/remove-<domainName>.service.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_CPP
	<domainName>/core/application/services/add-<domainName>.service.cpp
	<domainName>/core/application/services/get-<domainName>s.service.cpp
	<domainName>/core/application/services/get-<domainName>.service.cpp
	<domainName>/core/application/services/remove-<domainName>.service.cpp
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_HPP
	<domainName>/adapters/in/web/get-<domainName>s.controller.h
	<domainName>/adapters/in/web/get-<domainName>.controller.h
	<domainName>/adapters/in/web/add-<domainName>.controller.h
	<domainName>/adapters/in/web/remove-<domainName>.controller.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_CPP
	<domainName>/adapters/in/web/get-<domainName>s.controller.cpp
	<domainName>/adapters/in/web/get-<domainName>.controller.cpp
	<domainName>/adapters/in/web/add-<domainName>.controller.cpp
	<domainName>/adapters/in/web/remove-<domainName>.controller.cpp
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP
	<domainName>/adapters/out/persistence/<domainName>.repository.in-memory.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP
	<domainName>/adapters/out/persistence/<domainName>.repository.in-memory.cpp
)

set(${PROJECT_NAME}_SRC 
	main.cpp
	${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_CPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_CPP}
)

set(${PROJECT_NAME}_HDR
	${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_IN_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_OUT_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_DOMAIN_HPP}
)

add_executable (
	${PROJECT_NAME}
	${${PROJECT_NAME}_SRC}
	${${PROJECT_NAME}_HDR} 
)

target_link_libraries(
	${PROJECT_NAME}
	#SQLite::SQLite3
)

if(${CMAKE_VERSION} VERSION_GREATER "3.8.0")
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Source Files" FILES ${${PROJECT_NAME}_SRC})
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Header Files" FILES ${${PROJECT_NAME}_HDR})
	source_group("<domainName>/core/domain" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_DOMAIN_HPP})
	source_group("<domainName>/core/application/ports/in" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_IN_HPP})
	source_group("<domainName>/core/application/ports/out" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_PORT_OUT_HPP})
	source_group("<domainName>/core/application/services" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_CORE_APP_SERVICE_CPP})
	source_group("<domainName>/adapters/in/web" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_IN_WEB_CPP})
	source_group("<domainName>/adapters/out/persistence" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP})
endif() 