#project(maix_drivers)

# create driver library


FILE(GLOB_RECURSE LIB_SRC
        "${CMAKE_CURRENT_LIST_DIR}/*.h"
        "${CMAKE_CURRENT_LIST_DIR}/*.hpp"
        "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/*.s"
        "${CMAKE_CURRENT_LIST_DIR}/*.S"
        )


#FILE(GLOB_RECURSE LIB_SRC
#		"${CMAKE_CURRENT_LIST_DIR}/*.h"
#        "${CMAKE_CURRENT_LIST_DIR}/lvgl/*.h"
		
#        "${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_core/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_core/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_draw/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_draw/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_fonts/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_fonts/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_hal/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_hal/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_misc/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_misc/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_objx/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_objx/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_porting/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_porting/*.c"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_themes/*.h"
#		"${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_themes/*.c"
#       "${CMAKE_CURRENT_LIST_DIR}/*.c"
#        )

FILE(GLOB_RECURSE ASSEMBLY_FILES
        "${CMAKE_CURRENT_LIST_DIR}/*.s"
        "${CMAKE_CURRENT_LIST_DIR}/*.S"
        )

include_directories(
		${CMAKE_CURRENT_LIST_DIR} 
		${CMAKE_CURRENT_LIST_DIR}/lvgl
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_core 
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_draw 
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_fonts
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_hal
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_misc
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_objx
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_porting
		${CMAKE_CURRENT_LIST_DIR}/lvgl/lv_themes
		)

SET_PROPERTY(SOURCE ${ASSEMBLY_FILES} PROPERTY LANGUAGE C)
SET_SOURCE_FILES_PROPERTIES(${ASSEMBLY_FILES} PROPERTIES COMPILE_FLAGS "-x assembler-with-cpp -D __riscv64")

ADD_LIBRARY(littlevgl-gui-module
        ${LIB_SRC}
        )
SET_TARGET_PROPERTIES(littlevgl-gui-module PROPERTIES LINKER_LANGUAGE C)
