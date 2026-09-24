add_library(PAUL)
set_target_properties(PAUL PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

target_sources(PAUL
	PRIVATE
		library.cpp
	PUBLIC FILE_SET HEADERS
		BASE_DIRS include
	PRIVATE FILE_SET private_headers
		TYPE HEADERS
		BASE_DIRS
)

if (SKBUILD)
	set(Python_FIND_UNVERSIONEND_NAMES FIRST)
	find_package(Python REQUIRED COMPONENTS Interpreter Development.SABIModule Development.Module)
	find_package(nanobind CONFIG REQUIRED)

	nanobind_add_module(paul STABLE_ABI NB_STATIC)
	target_sources(paul
		PRIVATE
			pythonWrapper.cpp
	)
	target_link_libraries(paul PRIVATE PAUL)

	install(TARGETS paul LIBRARY DESTINATION paul)
endif ()