
# DO NOT MODIFY THIS FILE, IT WILL BE OVERRIDE!!!

# [section] Head
##### include(reset) #####
### reset basic var
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# set(CMAKE_SYSTEM "Generic")
set(CMAKE_SYSTEM_NAME "Generic")

# set(CMAKE_HOST_SYSTEM "Generic")
# set(CMAKE_HOST_SYSTEM_NAME "Generic")
#
set(CMAKE_CROSSCOMPILING TRUE)
# set(CMAKE_C_COMPILER_FORCED TRUE)
# set(CMAKE_CXX_COMPILER_FORCED TRUE)
# set(CMAKE_ASM_COMPILER_FORCED TRUE)
#

set(SOURCE_FILES "")
set(LDFLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_SHARED_LINKER_FLAGS "")
set(CMAKE_MODULE_LINKER_FLAGS "")


cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME "face_gui_demo")
# [/section] Head

# [section] Init
##### include(macros) #####
macro(header_directories parent)
    file(GLOB_RECURSE newList ${parent}/*.h)
    set(dir_list "")
    foreach (file_path ${newList})
        get_filename_component(dir_path ${file_path} DIRECTORY)
        set(dir_list ${dir_list} ${dir_path})
    endforeach ()
    list(REMOVE_DUPLICATES dir_list)

    include_directories(${dir_list})
endmacro()

string(SUBSTRING ${CMAKE_BINARY_DIR} 0 1 CMAKE_BINARY_DIR_L)
string(TOUPPER ${CMAKE_BINARY_DIR_L} CMAKE_BINARY_DIR_L)
string(SUBSTRING ${CMAKE_BINARY_DIR} 1 -1 CMAKE_BINARY_DIR_R)
set(CMAKE_BINARY_DIRX "${CMAKE_BINARY_DIR_L}${CMAKE_BINARY_DIR_R}")

macro(add_source_file)
    list(APPEND SOURCE_FILES ${ARGN})
    set("SOURCE_FILES_${PROJECT_NAME}" "${SOURCE_FILES}" CACHE STRING "Dump files to compile for '${PROJECT_NAME}'. Not used by program.")
endmacro()

macro(add_source_files)
    file(GLOB_RECURSE newlist ${ARGN})

    foreach (filepath ${newlist})
        string(FIND ${filepath} ${CMAKE_BINARY_DIRX} found1)
        string(FIND ${filepath} "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries" found2)
        if ((NOT found1 EQUAL 0) AND (NOT found2 EQUAL 0))
            list(APPEND SOURCE_FILES ${filepath})
        endif ()
    endforeach ()
    set("SOURCE_FILES_${PROJECT_NAME}" "${SOURCE_FILES}" CACHE STRING "Dump files to compile for '${PROJECT_NAME}'. Not used by program.")
endmacro()

function(JOIN VALUES GLUE OUTPUT)
    string(REGEX REPLACE "([^\\]|^);" "\\1${GLUE}" _TMP_STR "${VALUES}")
    string(REGEX REPLACE "[\\](.)" "\\1" _TMP_STR "${_TMP_STR}") #fixes escaping
    set(${OUTPUT} "${_TMP_STR}" PARENT_SCOPE)
endfunction()

function(removeDuplicateSubstring stringIn stringOut)
    separate_arguments(stringIn)
    list(REMOVE_DUPLICATES stringIn)
    string(REPLACE ";" " " stringIn "${stringIn}")
    set(${stringOut} "${stringIn}" PARENT_SCOPE)
endfunction()

macro(add_compile_flags WHERE)
    JOIN("${ARGN}" " " STRING_ARGS)
    if (${WHERE} STREQUAL C)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${STRING_ARGS}")

    elseif (${WHERE} STREQUAL CXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${STRING_ARGS}")

    elseif (${WHERE} STREQUAL LD)
        set(LDFLAGS "${LDFLAGS} ${STRING_ARGS}")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${STRING_ARGS}")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${STRING_ARGS}")
        set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${STRING_ARGS}")

    elseif (${WHERE} STREQUAL BOTH)
        add_compile_flags(C ${ARGN})
        add_compile_flags(CXX ${ARGN})

    elseif (${WHERE} STREQUAL ALL)
        add_compile_flags(C ${ARGN})
        add_compile_flags(CXX ${ARGN})
        add_compile_flags(LD ${ARGN})

    else ()
        message(FATAL_ERROR "add_compile_flags - only support: C, CXX, BOTH, LD, ALL")
    endif ()
endmacro()


##### include(coreFlags) #####
#add_compile_flags(LD -nostartfiles -Wl,--gc-sections)
add_compile_flags(ALL -mcmodel=medany)


##### include(ideSettings) #####
# set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
else()
    if((NOT CMAKE_BUILD_TYPE STREQUAL "Debug") AND (NOT CMAKE_BUILD_TYPE STREQUAL "Release"))
        message(FATAL_ERROR "CMAKE_BUILD_TYPE must either be Debug or Release instead of ${CMAKE_BUILD_TYPE}")
    endif()
endif()
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Build type options are: Debug Release RelWithDebInfo MinSizeRel")

## - Debug & Release
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DDEBUG=1)
endif()

## definitions in macros
add_definitions(-DCONFIG_LOG_LEVEL=LOG_INFO -DCONFIG_LOG_ENABLE -D__riscv64)
if(DEFINED KENDRYTE_IDE)
	set(CMAKE_COLOR_MAKEFILE FALSE)
else()
	add_definitions(-DCONFIG_LOG_COLORS)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE CACHE INTERNAL "must set to true, never edit or IDEs will not work")


##### include(toolchain) #####
if (WIN32)
    set(BINARY_EXTENSION ".exe")
else ()
    set(BINARY_EXTENSION "")
endif ()

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_LINKER "ld")
set(CMAKE_AR "ar")
set(CMAKE_OBJCOPY "objcopy")
set(CMAKE_SIZE "size")
set(CMAKE_OBJDUMP "objdump")
set(CMAKE_RANLIB "ranlib")
set(CMAKE_NM "nm")
set(CMAKE_STRIP "strip")
set(CMAKE_C_COMPILER_AR "gcc-ar")
set(CMAKE_C_COMPILER_RANLIB "gcc-ranlib")
set(CMAKE_CXX_COMPILER_AR "gcc-ar")
set(CMAKE_CXX_COMPILER_RANLIB "gcc-ranlib")

set(CMAKE_TOOLCHAIN_PREFIX "riscv64-unknown-elf-" CACHE INTERNAL "this const is defined by toolchain")
set(CMAKE_EXECUTABLE_FORMAT "ELF" CACHE INTERNAL "this const is defined by toolchain")

foreach(CMD CMAKE_C_COMPILER CMAKE_CXX_COMPILER CMAKE_LINKER CMAKE_AR CMAKE_OBJCOPY CMAKE_SIZE CMAKE_OBJDUMP CMAKE_RANLIB CMAKE_NM CMAKE_STRIP CMAKE_C_COMPILER_AR CMAKE_C_COMPILER_RANLIB CMAKE_CXX_COMPILER_AR CMAKE_CXX_COMPILER_RANLIB)
	set(${CMD} "${CMAKE_TOOLCHAIN_PREFIX}${${CMD}}${BINARY_EXTENSION}" CACHE FILEPATH "the path of ${CMD}" FORCE)
endforeach()

execute_process(COMMAND ${CMAKE_C_COMPILER} -print-file-name=crtbegin.o OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CRTBEGIN_OBJ)
execute_process(COMMAND ${CMAKE_C_COMPILER} -print-file-name=crtend.o OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CRTEND_OBJ)
execute_process(COMMAND ${CMAKE_C_COMPILER} -print-file-name=crti.o OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CRTI_OBJ)
execute_process(COMMAND ${CMAKE_C_COMPILER} -print-file-name=crtn.o OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CRTN_OBJ)

set(CMAKE_C_LINK_EXECUTABLE
       "<CMAKE_C_COMPILER> -o <TARGET> <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> \"${CRTI_OBJ}\" \"${CRTBEGIN_OBJ}\" <OBJECTS> \"${CRTEND_OBJ}\" \"${CRTN_OBJ}\" <LINK_LIBRARIES>"
       CACHE STRING "CMAKE_C_LINK_EXECUTABLE"
       )

set(CMAKE_CXX_LINK_EXECUTABLE
       "<CMAKE_CXX_COMPILER> -o <TARGET> <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> \"${CRTI_OBJ}\" \"${CRTBEGIN_OBJ}\" <OBJECTS> \"${CRTEND_OBJ}\" \"${CRTN_OBJ}\" <LINK_LIBRARIES>"
       CACHE STRING "CMAKE_CXX_LINK_EXECUTABLE"
       )


# debug mode disabled
# [/section] Init

# [section] Project
##### include(fix9985) #####
### http://www.cmake.org/Bug/view.php?id=9985
string(REPLACE "-rdynamic" "" _C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS}")
string(REPLACE "-rdynamic" "" _CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS}")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${_C_FLAGS}")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${_CXX_FLAGS}")


message("======== PROJECT:${PROJECT_NAME} ========")
project(${PROJECT_NAME})

## [section] Header
### from project local
include_directories(
  "${CMAKE_CURRENT_LIST_DIR}/src/"
  "${CMAKE_CURRENT_LIST_DIR}/components/"
  "${CMAKE_CURRENT_LIST_DIR}/components/fat-fs-module/lib"
  "${CMAKE_CURRENT_LIST_DIR}/components/rapidjson-sdk/rapidjson-1.1.0/include"
  "${CMAKE_CURRENT_LIST_DIR}/components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src"
  "${CMAKE_CURRENT_LIST_DIR}/components/facesdk"
  "${CMAKE_CURRENT_LIST_DIR}/src/face_gui_demo"
  "${CMAKE_CURRENT_LIST_DIR}/src/face_gui_demo/lvgl"
)### from ide
include_directories("${CMAKE_CURRENT_LIST_DIR}/config")
## from project public
include_directories(
  "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/lib/bsp/include"
  "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/lib/drivers/include"
  "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/lib/utils/include"
  "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/third_party/xtl/include"
  "${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/lib/nncase/include"
)
## [/section] Header
## [section] Source
## add source from config json (144 files matched)
add_source_file(src/face_gui_demo/demo_gui.c)
add_source_file(src/face_gui_demo/face_dvp.c)
add_source_file(src/face_gui_demo/face_fea_crud.c)
add_source_file(src/face_gui_demo/face_time.c)
add_source_file(src/face_gui_demo/face_mode.c)
add_source_file(src/face_gui_demo/gc0308.c)
add_source_file(src/face_gui_demo/gui_task.c)
add_source_file(src/face_gui_demo/k210rtc.c)
add_source_file(src/face_gui_demo/lcd.c)
add_source_file(src/face_gui_demo/main.c)
add_source_file(src/face_gui_demo/motor.c)
add_source_file(src/face_gui_demo/st7789.c)
add_source_file(src/face_gui_demo/tp_driver.c)
add_source_file(components/fat-fs-module/lib/ccsbcs.c)
add_source_file(components/fat-fs-module/lib/diskio.c)
add_source_file(components/fat-fs-module/lib/ff.c)
add_source_file(components/fat-fs-module/lib/sdcard.c)
add_source_file(components/fat-fs-module/lib/w25qxx.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTConnectClient.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTDeserializePublish.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTConnectServer.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTFormat.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTPacket.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTSerializePublish.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTSubscribeClient.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTSubscribeServer.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTUnsubscribeClient.c)
add_source_file(components/mqtt-sdk/paho.mqtt.embedded-c-1.0.0/MQTTPacket/src/MQTTUnsubscribeServer.c)
add_source_file(src/face_gui_demo/lvgl/lv_porting/lv_port_disp_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_porting/lv_port_fs_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_porting/lv_port_indev_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_group.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_indev.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_lang.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_obj.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_refr.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_style.c)
add_source_file(src/face_gui_demo/lvgl/lv_core/lv_vdb.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_arc.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_img.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_label.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_line.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_rbasic.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_rect.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_triangle.c)
add_source_file(src/face_gui_demo/lvgl/lv_draw/lv_draw_vbasic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/bell.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/bell_press.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/big_pic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/chin.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/blacklist_pic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/chinese.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/delete.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/delete_all.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/del_per.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/download.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/left_press.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/face_rec.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/left_btn.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_builtin.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_10.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_10_cyrillic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_10_latin_sup.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_20.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_20_cyrillic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_20_latin_sup.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_30.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_30_latin_sup.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_40.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_30_cyrillic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_40_latin_sup.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_dejavu_40_cyrillic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_monospace_8.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_symbol_10.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_symbol_20.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_symbol_40.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/one_config.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/lv_font_symbol_30.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/ota_pic.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/right_btn.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/right_press.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/set_button.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/upload.c)
add_source_file(src/face_gui_demo/lvgl/lv_fonts/wifi_pic.c)
add_source_file(src/face_gui_demo/lvgl/lv_hal/lv_hal_disp.c)
add_source_file(src/face_gui_demo/lvgl/lv_hal/lv_hal_indev.c)
add_source_file(src/face_gui_demo/lvgl/lv_hal/lv_hal_tick.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_anim.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_area.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_circ.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_color.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_font.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_gc.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_fs.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_ll.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_log.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_mem.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_math.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_task.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_txt.c)
add_source_file(src/face_gui_demo/lvgl/lv_misc/lv_ufs.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_arc.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_bar.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_btn.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_btnm.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_calendar.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_canvas.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_cb.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_chart.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_cont.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_ddlist.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_gauge.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_imgbtn.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_img.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_kb.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_label.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_led.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_line.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_list.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_lmeter.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_mbox.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_objx_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_page.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_preload.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_roller.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_slider.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_spinbox.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_sw.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_ta.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_table.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_tabview.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_tileview.c)
add_source_file(src/face_gui_demo/lvgl/lv_objx/lv_win.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_alien.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_default.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_material.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_mono.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_nemo.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_night.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_templ.c)
add_source_file(src/face_gui_demo/lvgl/lv_themes/lv_theme_zen.c)
## [/section] Source
# [/section] Project

# [section] Custom

# [/section] Custom
# [section] Target
## final create face_gui_demo executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE "PROJECT_PATH=${CMAKE_CURRENT_LIST_DIR}/")
### [section] Custom2

### [/section] Custom2
# debug mode disabled
## set properties
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE "C")
## set definitions
add_compile_definitions(TCB_SPAN_NO_EXCEPTIONS)
add_compile_definitions(TCB_SPAN_NO_CONTRACT_CHECKING)
add_compile_definitions(NNCASE_TARGET=k210)
add_compile_definitions(KENDRYTE_SDK_TYPE=1)
add_compile_definitions(KENDRYTE_SDK_TYPE_STANDALONE=1)
add_compile_definitions(KENDRYTE_SDK_TYPE_FREERTOS=2)
add_compile_definitions(KENDRYTE_SDK_RELEASE_DATE=0)
add_compile_definitions(HAVE_CCONFIG_H)
add_compile_definitions(RT_USING_NEWLIB)
add_compile_definitions(HAVE_SYS_SELECT_H)
add_compile_definitions(HAVE_SIGVAL)
add_compile_definitions(HAVE_SIGEVENT)
add_compile_definitions(HAVE_SIGINFO)
add_compile_definitions(CONFIG_LOG_COLORS)
add_compile_definitions(CONFIG_LOG_ENABLE)
add_compile_definitions(FPGA_PLL)
add_compile_definitions(__riscv64)
# [/section] Target

# [section] Dependency
cmake_policy(SET CMP0079 NEW)
## root project will include all dependency
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}//kendryte_libraries/kendryte_standalone-sdk" "kendryte_standalone-sdk")
## add simple folder dependency
# [/section] Dependency


# [section] C/C++ compiler flags

##### flags from config json #####
message("config flags for ${PROJECT_NAME}")
set(FLAGS_FOR_C
  "-std=gnu11"
  "-Wno-pointer-to-int-cast"
  "-Wno-old-style-declaration"
  "-mcmodel=medany"
  "-mabi=lp64f"
  "-march=rv64imafc"
  "-ffunction-sections"
  "-fdata-sections"
  "-fstrict-volatile-bitfields"
  "-fno-zero-initialized-in-bss"
  "-Os"
  "-Wall"
  "-Werror=all"
  "-Wno-error=unused-function"
  "-Wno-error=missing-braces"
  "-Wno-error=tautological-compare"
  "-Wno-error=unused-variable"
  "-Wno-error=format="
  "-Wno-error=pointer-sign"
  "-ffast-math"
  "-fno-math-errno"
  "-fsingle-precision-constant"
  "-ffloat-store"
  "-Wno-error=unused-but-set-variable"
  "-Wno-error=sign-compare"
)
set(FLAGS_FOR_CXX
  "-std=gnu++17"
  "-mcmodel=medany"
  "-mabi=lp64f"
  "-march=rv64imafc"
  "-ffunction-sections"
  "-fdata-sections"
  "-fstrict-volatile-bitfields"
  "-fno-zero-initialized-in-bss"
  "-Os"
  "-Wall"
  "-Werror=all"
  "-Wno-error=unused-function"
  "-Wno-error=missing-braces"
  "-Wno-error=tautological-compare"
  "-Wno-error=unused-variable"
  "-Wno-error=format="
  "-Wno-error=pointer-sign"
  "-ffast-math"
  "-fno-math-errno"
  "-fsingle-precision-constant"
  "-ffloat-store"
  "-Wno-error=unused-but-set-variable"
  "-Wno-error=sign-compare"
)
target_compile_options(${PROJECT_NAME} PRIVATE
	$<$<COMPILE_LANGUAGE:C>:${FLAGS_FOR_C}>
	$<$<COMPILE_LANGUAGE:CXX>:${FLAGS_FOR_CXX}>
)
target_link_options(${PROJECT_NAME} PUBLIC
	"-march=rv64imafc"
	"-mabi=lp64f"
	"-nostartfiles"
	"-Wl,--gc-sections"
	"-Wl,-static"
	"-Wl,-EL"
	"-Wl,--no-relax"
	"-Wl,--gc-sections,-Map=rtthread.map,-cref,-u,_start"
	"-nostartfiles"
	"-static"
	"-Wl,--gc-sections"
	"-Wl,-static"
	"-Wl,-EL"
	"-Wl,--no-relax"
	"-T"
	"${CMAKE_CURRENT_LIST_DIR}/kendryte_libraries/kendryte_standalone-sdk/lds/kendryte.ld"
	"-nostartfiles"
	"-Wl,--gc-sections"
)
target_link_libraries(${PROJECT_NAME} PUBLIC -Wl,--start-group
	"${CMAKE_CURRENT_LIST_DIR}//components/facesdk/libfacesdk.a"
	## -> face_gui_demo: face_gui_demo
	##	not link component
	"gcc"
	"m"
	"c"
	## -> kendryte/standalone-sdk: kendryte_standalone-sdk
	"-Wl,--whole-archive"
	"kendryte_standalone-sdk"
	"-Wl,--no-whole-archive"
-Wl,--end-group)

# [/section] C/C++ compiler flags

# [section] Finish
##### include(afterProject) #####
removeDuplicateSubstring("${CMAKE_C_FLAGS}" CMAKE_C_FLAGS)
removeDuplicateSubstring("${CMAKE_CXX_FLAGS}" CMAKE_CXX_FLAGS)


##### include(fix9985) #####
### http://www.cmake.org/Bug/view.php?id=9985
string(REPLACE "-rdynamic" "" _C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS}")
string(REPLACE "-rdynamic" "" _CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS}")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${_C_FLAGS}")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${_CXX_FLAGS}")


##### include(flash) #####
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} --output-format=binary ${CMAKE_BINARY_DIR}/${PROJECT_NAME}${SUFFIX} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin
        DEPENDS ${PROJECT_NAME}
        COMMENT "Generating .bin file ...")


# [/section] Finish

# [section] Dump Setting
##### include(dumpConfig) #####
set(CMAKE_SYSTEM_NAME "Generic")

message("")
message("Project: ${PROJECT_NAME}")
message("  LIST_FILE=${CMAKE_PARENT_LIST_FILE}")
message("  TOOLCHAIN=${TOOLCHAIN}")
message("  KENDRYTE_IDE=${KENDRYTE_IDE}")
message("  BUILDING_SDK=${BUILDING_SDK}")
message("  _CMAKE_TOOLCHAIN_PREFIX=${_CMAKE_TOOLCHAIN_PREFIX}")
message("  _CMAKE_TOOLCHAIN_LOCATION=${_CMAKE_TOOLCHAIN_LOCATION}")


message("")
message("  CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
message("  CMAKE_C_COMPILER=${CMAKE_C_COMPILER}")
message("  CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}")
message("  CMAKE_LINKER=${CMAKE_LINKER}")
message("  CMAKE_OBJCOPY=${CMAKE_OBJCOPY}")
message("  CMAKE_OBJDUMP=${CMAKE_OBJDUMP}")
message("  CMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}")

message("")
message("  CMAKE_C_FLAGS=${CMAKE_C_FLAGS}")
message("  CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
message("  LDFLAGS=${LDFLAGS}")
message("  LINK_FLAGS=${LINK_FLAGS}")
message("  CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

message("Makefile created.")
message("")
message("")



# [/section] Dump Setting
