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
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world

# Include any dependencies generated for this target.
include CMakeFiles/hello_world.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_world.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_world.dir/flags.make

CMakeFiles/hello_world.dir/src/hello_world/main.c.obj: CMakeFiles/hello_world.dir/flags.make
CMakeFiles/hello_world.dir/src/hello_world/main.c.obj: ../../src/hello_world/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hello_world.dir/src/hello_world/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello_world.dir/src/hello_world/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/hello_world/main.c

CMakeFiles/hello_world.dir/src/hello_world/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello_world.dir/src/hello_world/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/hello_world/main.c > CMakeFiles/hello_world.dir/src/hello_world/main.c.i

CMakeFiles/hello_world.dir/src/hello_world/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello_world.dir/src/hello_world/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/hello_world/main.c -o CMakeFiles/hello_world.dir/src/hello_world/main.c.s

CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.requires:

.PHONY : CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.requires

CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.provides: CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.requires
	$(MAKE) -f CMakeFiles/hello_world.dir/build.make CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.provides.build
.PHONY : CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.provides

CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.provides.build: CMakeFiles/hello_world.dir/src/hello_world/main.c.obj


# Object files for target hello_world
hello_world_OBJECTS = \
"CMakeFiles/hello_world.dir/src/hello_world/main.c.obj"

# External object files for target hello_world
hello_world_EXTERNAL_OBJECTS =

hello_world: CMakeFiles/hello_world.dir/src/hello_world/main.c.obj
hello_world: CMakeFiles/hello_world.dir/build.make
hello_world: lib/libkendryte.a
hello_world: fat-fs-module/libfat-fs-module.a
hello_world: CMakeFiles/hello_world.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hello_world"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_world.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world/hello_world /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world/hello_world.bin

# Rule to build all files generated by this target.
CMakeFiles/hello_world.dir/build: hello_world

.PHONY : CMakeFiles/hello_world.dir/build

CMakeFiles/hello_world.dir/requires: CMakeFiles/hello_world.dir/src/hello_world/main.c.obj.requires

.PHONY : CMakeFiles/hello_world.dir/requires

CMakeFiles/hello_world.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_world.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_world.dir/clean

CMakeFiles/hello_world.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/hello_world/CMakeFiles/hello_world.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_world.dir/depend
