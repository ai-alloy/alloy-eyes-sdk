# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc

# Include any dependencies generated for this target.
include CMakeFiles/rtc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rtc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rtc.dir/flags.make

CMakeFiles/rtc.dir/src/rtc/main.c.obj: CMakeFiles/rtc.dir/flags.make
CMakeFiles/rtc.dir/src/rtc/main.c.obj: ../../src/rtc/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rtc.dir/src/rtc/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtc.dir/src/rtc/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/rtc/main.c

CMakeFiles/rtc.dir/src/rtc/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtc.dir/src/rtc/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/rtc/main.c > CMakeFiles/rtc.dir/src/rtc/main.c.i

CMakeFiles/rtc.dir/src/rtc/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtc.dir/src/rtc/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/rtc/main.c -o CMakeFiles/rtc.dir/src/rtc/main.c.s

CMakeFiles/rtc.dir/src/rtc/main.c.obj.requires:

.PHONY : CMakeFiles/rtc.dir/src/rtc/main.c.obj.requires

CMakeFiles/rtc.dir/src/rtc/main.c.obj.provides: CMakeFiles/rtc.dir/src/rtc/main.c.obj.requires
	$(MAKE) -f CMakeFiles/rtc.dir/build.make CMakeFiles/rtc.dir/src/rtc/main.c.obj.provides.build
.PHONY : CMakeFiles/rtc.dir/src/rtc/main.c.obj.provides

CMakeFiles/rtc.dir/src/rtc/main.c.obj.provides.build: CMakeFiles/rtc.dir/src/rtc/main.c.obj


# Object files for target rtc
rtc_OBJECTS = \
"CMakeFiles/rtc.dir/src/rtc/main.c.obj"

# External object files for target rtc
rtc_EXTERNAL_OBJECTS =

rtc: CMakeFiles/rtc.dir/src/rtc/main.c.obj
rtc: CMakeFiles/rtc.dir/build.make
rtc: lib/libkendryte.a
rtc: fat-fs-module/libfat-fs-module.a
rtc: CMakeFiles/rtc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rtc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtc.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc/rtc /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc/rtc.bin

# Rule to build all files generated by this target.
CMakeFiles/rtc.dir/build: rtc

.PHONY : CMakeFiles/rtc.dir/build

CMakeFiles/rtc.dir/requires: CMakeFiles/rtc.dir/src/rtc/main.c.obj.requires

.PHONY : CMakeFiles/rtc.dir/requires

CMakeFiles/rtc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rtc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rtc.dir/clean

CMakeFiles/rtc.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/rtc/CMakeFiles/rtc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rtc.dir/depend

