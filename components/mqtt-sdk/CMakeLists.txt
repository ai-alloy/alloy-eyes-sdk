#project(maix_drivers)

# create driver library
# add_definitions(OSTYPE Linux)
FILE(GLOB_RECURSE LIB_SRC
        "${CMAKE_CURRENT_LIST_DIR}/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/*.c"
        )

FILE(GLOB_RECURSE ASSEMBLY_FILES
        "${CMAKE_CURRENT_LIST_DIR}/*.s"
        "${CMAKE_CURRENT_LIST_DIR}/*.S"
        )

include_directories(${CMAKE_CURRENT_LIST_DIR}/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/paho.mqtt.embedded-c-1.0.0/MQTTClient/src)

SET_PROPERTY(SOURCE ${ASSEMBLY_FILES} PROPERTY LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${ASSEMBLY_FILES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp -D __riscv64")

ADD_LIBRARY(mqtt-sdk ${LIB_SRC})
SET_TARGET_PROPERTIES(mqtt-sdk PROPERTIES LINKER_LANGUAGE C)
