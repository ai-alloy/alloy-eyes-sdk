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
CMAKE_BINARY_DIR = /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd

# Include any dependencies generated for this target.
include CMakeFiles/lcd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lcd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lcd.dir/flags.make

CMakeFiles/lcd.dir/src/lcd/lcd.c.obj: CMakeFiles/lcd.dir/flags.make
CMakeFiles/lcd.dir/src/lcd/lcd.c.obj: ../../src/lcd/lcd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lcd.dir/src/lcd/lcd.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcd.dir/src/lcd/lcd.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/lcd.c

CMakeFiles/lcd.dir/src/lcd/lcd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcd.dir/src/lcd/lcd.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/lcd.c > CMakeFiles/lcd.dir/src/lcd/lcd.c.i

CMakeFiles/lcd.dir/src/lcd/lcd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcd.dir/src/lcd/lcd.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/lcd.c -o CMakeFiles/lcd.dir/src/lcd/lcd.c.s

CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.requires:

.PHONY : CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.requires

CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.provides: CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.requires
	$(MAKE) -f CMakeFiles/lcd.dir/build.make CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.provides.build
.PHONY : CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.provides

CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.provides.build: CMakeFiles/lcd.dir/src/lcd/lcd.c.obj


CMakeFiles/lcd.dir/src/lcd/main.c.obj: CMakeFiles/lcd.dir/flags.make
CMakeFiles/lcd.dir/src/lcd/main.c.obj: ../../src/lcd/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lcd.dir/src/lcd/main.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcd.dir/src/lcd/main.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/main.c

CMakeFiles/lcd.dir/src/lcd/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcd.dir/src/lcd/main.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/main.c > CMakeFiles/lcd.dir/src/lcd/main.c.i

CMakeFiles/lcd.dir/src/lcd/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcd.dir/src/lcd/main.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/main.c -o CMakeFiles/lcd.dir/src/lcd/main.c.s

CMakeFiles/lcd.dir/src/lcd/main.c.obj.requires:

.PHONY : CMakeFiles/lcd.dir/src/lcd/main.c.obj.requires

CMakeFiles/lcd.dir/src/lcd/main.c.obj.provides: CMakeFiles/lcd.dir/src/lcd/main.c.obj.requires
	$(MAKE) -f CMakeFiles/lcd.dir/build.make CMakeFiles/lcd.dir/src/lcd/main.c.obj.provides.build
.PHONY : CMakeFiles/lcd.dir/src/lcd/main.c.obj.provides

CMakeFiles/lcd.dir/src/lcd/main.c.obj.provides.build: CMakeFiles/lcd.dir/src/lcd/main.c.obj


CMakeFiles/lcd.dir/src/lcd/st7789.c.obj: CMakeFiles/lcd.dir/flags.make
CMakeFiles/lcd.dir/src/lcd/st7789.c.obj: ../../src/lcd/st7789.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lcd.dir/src/lcd/st7789.c.obj"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcd.dir/src/lcd/st7789.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/st7789.c

CMakeFiles/lcd.dir/src/lcd/st7789.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcd.dir/src/lcd/st7789.c.i"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/st7789.c > CMakeFiles/lcd.dir/src/lcd/st7789.c.i

CMakeFiles/lcd.dir/src/lcd/st7789.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcd.dir/src/lcd/st7789.c.s"
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/src/lcd/st7789.c -o CMakeFiles/lcd.dir/src/lcd/st7789.c.s

CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.requires:

.PHONY : CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.requires

CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.provides: CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.requires
	$(MAKE) -f CMakeFiles/lcd.dir/build.make CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.provides.build
.PHONY : CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.provides

CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.provides.build: CMakeFiles/lcd.dir/src/lcd/st7789.c.obj


# Object files for target lcd
lcd_OBJECTS = \
"CMakeFiles/lcd.dir/src/lcd/lcd.c.obj" \
"CMakeFiles/lcd.dir/src/lcd/main.c.obj" \
"CMakeFiles/lcd.dir/src/lcd/st7789.c.obj"

# External object files for target lcd
lcd_EXTERNAL_OBJECTS =

lcd: CMakeFiles/lcd.dir/src/lcd/lcd.c.obj
lcd: CMakeFiles/lcd.dir/src/lcd/main.c.obj
lcd: CMakeFiles/lcd.dir/src/lcd/st7789.c.obj
lcd: CMakeFiles/lcd.dir/build.make
lcd: lib/libkendryte.a
lcd: fat-fs-module/libfat-fs-module.a
lcd: CMakeFiles/lcd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lcd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcd.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating .bin file ..."
	/opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-objcopy --output-format=binary /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/lcd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/lcd.bin

# Rule to build all files generated by this target.
CMakeFiles/lcd.dir/build: lcd

.PHONY : CMakeFiles/lcd.dir/build

CMakeFiles/lcd.dir/requires: CMakeFiles/lcd.dir/src/lcd/lcd.c.obj.requires
CMakeFiles/lcd.dir/requires: CMakeFiles/lcd.dir/src/lcd/main.c.obj.requires
CMakeFiles/lcd.dir/requires: CMakeFiles/lcd.dir/src/lcd/st7789.c.obj.requires

.PHONY : CMakeFiles/lcd.dir/requires

CMakeFiles/lcd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lcd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lcd.dir/clean

CMakeFiles/lcd.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles/lcd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lcd.dir/depend

