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
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor

# Include any dependencies generated for this target.
include CMakeFiles/motor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motor.dir/flags.make

CMakeFiles/motor.dir/src/motor/motor.c.obj: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/motor/motor.c.obj: ../../src/motor/motor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/motor.dir/src/motor/motor.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/motor.dir/src/motor/motor.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/motor.c

CMakeFiles/motor.dir/src/motor/motor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/motor.dir/src/motor/motor.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/motor.c > CMakeFiles/motor.dir/src/motor/motor.c.i

CMakeFiles/motor.dir/src/motor/motor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/motor.dir/src/motor/motor.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/motor.c -o CMakeFiles/motor.dir/src/motor/motor.c.s

CMakeFiles/motor.dir/src/motor/motor.c.obj.requires:

.PHONY : CMakeFiles/motor.dir/src/motor/motor.c.obj.requires

CMakeFiles/motor.dir/src/motor/motor.c.obj.provides: CMakeFiles/motor.dir/src/motor/motor.c.obj.requires
	$(MAKE) -f CMakeFiles/motor.dir/build.make CMakeFiles/motor.dir/src/motor/motor.c.obj.provides.build
.PHONY : CMakeFiles/motor.dir/src/motor/motor.c.obj.provides

CMakeFiles/motor.dir/src/motor/motor.c.obj.provides.build: CMakeFiles/motor.dir/src/motor/motor.c.obj


CMakeFiles/motor.dir/src/motor/main.c.obj: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/motor/main.c.obj: ../../src/motor/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/motor.dir/src/motor/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/motor.dir/src/motor/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/main.c

CMakeFiles/motor.dir/src/motor/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/motor.dir/src/motor/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/main.c > CMakeFiles/motor.dir/src/motor/main.c.i

CMakeFiles/motor.dir/src/motor/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/motor.dir/src/motor/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/motor/main.c -o CMakeFiles/motor.dir/src/motor/main.c.s

CMakeFiles/motor.dir/src/motor/main.c.obj.requires:

.PHONY : CMakeFiles/motor.dir/src/motor/main.c.obj.requires

CMakeFiles/motor.dir/src/motor/main.c.obj.provides: CMakeFiles/motor.dir/src/motor/main.c.obj.requires
	$(MAKE) -f CMakeFiles/motor.dir/build.make CMakeFiles/motor.dir/src/motor/main.c.obj.provides.build
.PHONY : CMakeFiles/motor.dir/src/motor/main.c.obj.provides

CMakeFiles/motor.dir/src/motor/main.c.obj.provides.build: CMakeFiles/motor.dir/src/motor/main.c.obj


# Object files for target motor
motor_OBJECTS = \
"CMakeFiles/motor.dir/src/motor/motor.c.obj" \
"CMakeFiles/motor.dir/src/motor/main.c.obj"

# External object files for target motor
motor_EXTERNAL_OBJECTS =

motor: CMakeFiles/motor.dir/src/motor/motor.c.obj
motor: CMakeFiles/motor.dir/src/motor/main.c.obj
motor: CMakeFiles/motor.dir/build.make
motor: lib/libkendryte.a
motor: fat-fs-module/libfat-fs-module.a
motor: CMakeFiles/motor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable motor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motor.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/motor /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/motor.bin

# Rule to build all files generated by this target.
CMakeFiles/motor.dir/build: motor

.PHONY : CMakeFiles/motor.dir/build

CMakeFiles/motor.dir/requires: CMakeFiles/motor.dir/src/motor/motor.c.obj.requires
CMakeFiles/motor.dir/requires: CMakeFiles/motor.dir/src/motor/main.c.obj.requires

.PHONY : CMakeFiles/motor.dir/requires

CMakeFiles/motor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motor.dir/clean

CMakeFiles/motor.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/motor/CMakeFiles/motor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motor.dir/depend
