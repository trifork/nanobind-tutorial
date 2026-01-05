cmake_minimum_required(VERSION 4.0)
project(PAUL)

option(BUILD_TESTS "Enable tests")

set(CMAKE_CXX_STANDARD 23)


add_subdirectory(src)

if (${BUILD_TESTS})
	include(CTest)
	find_package(Catch2 REQUIRED)
	add_subdirectory(test)
endif ()