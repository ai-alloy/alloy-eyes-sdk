#project(maix_drivers)

# create driver library
# add_definitions(OSTYPE Linux)
FILE(GLOB_RECURSE LIB_SRC
		"${CMAKE_CURRENT_LIST_DIR}/jsoncpp/include/*.h"
	    "${CMAKE_CURRENT_LIST_DIR}/jsoncpp/src/lib_json/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/jsoncpp/src/lib_json/*.cpp"
        )

FILE(GLOB_RECURSE ASSEMBLY_FILES
        )
include_directories(${CMAKE_CURRENT_LIST_DIR}/jsoncpp/include)

SET_PROPERTY(SOURCE ${ASSEMBLY_FILES} PROPERTY LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${ASSEMBLY_FILES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp -D __riscv64")

ADD_LIBRARY(jsoncpp ${LIB_SRC})
SET_TARGET_PROPERTIES(jsoncpp PROPERTIES LINKER_LANGUAGE C)
