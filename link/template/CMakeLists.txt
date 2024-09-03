project(ProjectName)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package(SQLite3 REQUIRED)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_IN_HPP
	<domainName>-<targetName>/core/application/ports/in/link-<domainName>-<targetName>.input-port.h
	<domainName>-<targetName>/core/application/ports/in/get-<domainName>-<targetName>s.input-port.h
	<domainName>-<targetName>/core/application/ports/in/unlink-<domainName>-<targetName>.input-port.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_OUT_HPP
	<domainName>-<targetName>/core/application/ports/out/<domainName>-<targetName>-repository.ouput-port.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_HPP
	<domainName>-<targetName>/core/application/services/link-<domainName>-<targetName>.service.h
	<domainName>-<targetName>/core/application/services/get-<domainName>-<targetName>s.service.h
	<domainName>-<targetName>/core/application/services/unlink-<domainName>-<targetName>.service.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_CPP
	<domainName>-<targetName>/core/application/services/link-<domainName>-<targetName>.service.cpp
	<domainName>-<targetName>/core/application/services/get-<domainName>-<targetName>s.service.cpp
	<domainName>-<targetName>/core/application/services/unlink-<domainName>-<targetName>.service.cpp
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_HPP
	<domainName>-<targetName>/adapters/in/web/get-<domainName>-<targetName>s.controller.h
	<domainName>-<targetName>/adapters/in/web/link-<domainName>-<targetName>.controller.h
	<domainName>-<targetName>/adapters/in/web/unlink-<domainName>-<targetName>.controller.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_CPP
	<domainName>-<targetName>/adapters/in/web/get-<domainName>-<targetName>s.controller.cpp
	<domainName>-<targetName>/adapters/in/web/link-<domainName>-<targetName>.controller.cpp
	<domainName>-<targetName>/adapters/in/web/unlink-<domainName>-<targetName>.controller.cpp
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP
	<domainName>-<targetName>/adapters/out/persistence/<domainName>-<targetName>.repository.in-memory.h
)

set(${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP
	<domainName>-<targetName>/adapters/out/persistence/<domainName>-<targetName>.repository.in-memory.cpp
)

set(${PROJECT_NAME}_SRC 
	main.cpp
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_CPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_CPP}
)

set(${PROJECT_NAME}_HDR
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_IN_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_OUT_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_HPP}
	${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_DOMAIN_HPP}
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
	source_group("<domainName>-<targetName>/core/application/ports/in" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_IN_HPP})
	source_group("<domainName>-<targetName>/core/application/ports/out" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_PORT_OUT_HPP})
	source_group("<domainName>-<targetName>/core/application/services" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_CORE_APP_SERVICE_CPP})
	source_group("<domainName>-<targetName>/adapters/in/web" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_IN_WEB_CPP})
	source_group("<domainName>-<targetName>/adapters/out/persistence" FILES ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_HPP} ${${PROJECT_NAME}_<DOMAIN_NAME>_<TARGET_NAME>_ADAPTERS_OUT_PERSISTENCE_CPP})
endif() 