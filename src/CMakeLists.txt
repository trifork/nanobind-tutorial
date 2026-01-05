add_library(PAUL)

target_sources(PAUL
	PRIVATE
		library.cpp
	PUBLIC FILE_SET HEADERS
		BASE_DIRS include
	PRIVATE FILE_SET private_headers
		TYPE HEADERS
		BASE_DIRS
)