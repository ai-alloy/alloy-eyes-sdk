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
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm

# Include any dependencies generated for this target.
include CMakeFiles/play_pcm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/play_pcm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/play_pcm.dir/flags.make

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj: CMakeFiles/play_pcm.dir/flags.make
CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj: ../../src/play_pcm/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/play_pcm/main.c

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/play_pcm.dir/src/play_pcm/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/play_pcm/main.c > CMakeFiles/play_pcm.dir/src/play_pcm/main.c.i

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/play_pcm.dir/src/play_pcm/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/play_pcm/main.c -o CMakeFiles/play_pcm.dir/src/play_pcm/main.c.s

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.requires:

.PHONY : CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.requires

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.provides: CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.requires
	$(MAKE) -f CMakeFiles/play_pcm.dir/build.make CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.provides.build
.PHONY : CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.provides

CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.provides.build: CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj


# Object files for target play_pcm
play_pcm_OBJECTS = \
"CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj"

# External object files for target play_pcm
play_pcm_EXTERNAL_OBJECTS =

play_pcm: CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj
play_pcm: CMakeFiles/play_pcm.dir/build.make
play_pcm: lib/libkendryte.a
play_pcm: fat-fs-module/libfat-fs-module.a
play_pcm: CMakeFiles/play_pcm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable play_pcm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/play_pcm.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm/play_pcm /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm/play_pcm.bin

# Rule to build all files generated by this target.
CMakeFiles/play_pcm.dir/build: play_pcm

.PHONY : CMakeFiles/play_pcm.dir/build

CMakeFiles/play_pcm.dir/requires: CMakeFiles/play_pcm.dir/src/play_pcm/main.c.obj.requires

.PHONY : CMakeFiles/play_pcm.dir/requires

CMakeFiles/play_pcm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/play_pcm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/play_pcm.dir/clean

CMakeFiles/play_pcm.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/play_pcm/CMakeFiles/play_pcm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/play_pcm.dir/depend
