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
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer

# Include any dependencies generated for this target.
include CMakeFiles/timer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timer.dir/flags.make

CMakeFiles/timer.dir/src/timer/main.c.obj: CMakeFiles/timer.dir/flags.make
CMakeFiles/timer.dir/src/timer/main.c.obj: ../../src/timer/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/timer.dir/src/timer/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timer.dir/src/timer/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/timer/main.c

CMakeFiles/timer.dir/src/timer/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timer.dir/src/timer/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/timer/main.c > CMakeFiles/timer.dir/src/timer/main.c.i

CMakeFiles/timer.dir/src/timer/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timer.dir/src/timer/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/timer/main.c -o CMakeFiles/timer.dir/src/timer/main.c.s

CMakeFiles/timer.dir/src/timer/main.c.obj.requires:

.PHONY : CMakeFiles/timer.dir/src/timer/main.c.obj.requires

CMakeFiles/timer.dir/src/timer/main.c.obj.provides: CMakeFiles/timer.dir/src/timer/main.c.obj.requires
	$(MAKE) -f CMakeFiles/timer.dir/build.make CMakeFiles/timer.dir/src/timer/main.c.obj.provides.build
.PHONY : CMakeFiles/timer.dir/src/timer/main.c.obj.provides

CMakeFiles/timer.dir/src/timer/main.c.obj.provides.build: CMakeFiles/timer.dir/src/timer/main.c.obj


# Object files for target timer
timer_OBJECTS = \
"CMakeFiles/timer.dir/src/timer/main.c.obj"

# External object files for target timer
timer_EXTERNAL_OBJECTS =

timer: CMakeFiles/timer.dir/src/timer/main.c.obj
timer: CMakeFiles/timer.dir/build.make
timer: lib/libkendryte.a
timer: fat-fs-module/libfat-fs-module.a
timer: CMakeFiles/timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timer.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer/timer /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer/timer.bin

# Rule to build all files generated by this target.
CMakeFiles/timer.dir/build: timer

.PHONY : CMakeFiles/timer.dir/build

CMakeFiles/timer.dir/requires: CMakeFiles/timer.dir/src/timer/main.c.obj.requires

.PHONY : CMakeFiles/timer.dir/requires

CMakeFiles/timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/timer.dir/clean

CMakeFiles/timer.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/timer/CMakeFiles/timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/timer.dir/depend

