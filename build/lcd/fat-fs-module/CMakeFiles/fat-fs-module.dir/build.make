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
include fat-fs-module/CMakeFiles/fat-fs-module.dir/depend.make

# Include the progress variables for this target.
include fat-fs-module/CMakeFiles/fat-fs-module.dir/progress.make

# Include the compile flags for this target's objects.
include fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj: fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make
fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj: ../../fat-fs-module/lib/ff.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat-fs-module.dir/lib/ff.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ff.c

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat-fs-module.dir/lib/ff.c.i"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ff.c > CMakeFiles/fat-fs-module.dir/lib/ff.c.i

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat-fs-module.dir/lib/ff.c.s"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ff.c -o CMakeFiles/fat-fs-module.dir/lib/ff.c.s

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.requires:

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.provides: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.requires
	$(MAKE) -f fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.provides.build
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.provides

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.provides.build: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj


fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj: fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make
fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj: ../../fat-fs-module/lib/diskio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/diskio.c

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat-fs-module.dir/lib/diskio.c.i"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/diskio.c > CMakeFiles/fat-fs-module.dir/lib/diskio.c.i

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat-fs-module.dir/lib/diskio.c.s"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/diskio.c -o CMakeFiles/fat-fs-module.dir/lib/diskio.c.s

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.requires:

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.provides: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.requires
	$(MAKE) -f fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.provides.build
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.provides

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.provides.build: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj


fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj: fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make
fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj: ../../fat-fs-module/lib/sdcard.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/sdcard.c

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat-fs-module.dir/lib/sdcard.c.i"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/sdcard.c > CMakeFiles/fat-fs-module.dir/lib/sdcard.c.i

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat-fs-module.dir/lib/sdcard.c.s"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/sdcard.c -o CMakeFiles/fat-fs-module.dir/lib/sdcard.c.s

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.requires:

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.provides: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.requires
	$(MAKE) -f fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.provides.build
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.provides

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.provides.build: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj


fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj: fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make
fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj: ../../fat-fs-module/lib/w25qxx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/w25qxx.c

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.i"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/w25qxx.c > CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.i

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.s"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/w25qxx.c -o CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.s

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.requires:

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.provides: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.requires
	$(MAKE) -f fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.provides.build
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.provides

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.provides.build: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj


fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj: fat-fs-module/CMakeFiles/fat-fs-module.dir/flags.make
fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj: ../../fat-fs-module/lib/ccsbcs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj   -c /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ccsbcs.c

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.i"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ccsbcs.c > CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.i

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.s"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && /opt/my-kendryte-toolchain/bin/riscv64-unknown-elf-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module/lib/ccsbcs.c -o CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.s

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.requires:

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.provides: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.requires
	$(MAKE) -f fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.provides.build
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.provides

fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.provides.build: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj


# Object files for target fat-fs-module
fat__fs__module_OBJECTS = \
"CMakeFiles/fat-fs-module.dir/lib/ff.c.obj" \
"CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj" \
"CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj" \
"CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj" \
"CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj"

# External object files for target fat-fs-module
fat__fs__module_EXTERNAL_OBJECTS =

fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/build.make
fat-fs-module/libfat-fs-module.a: fat-fs-module/CMakeFiles/fat-fs-module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libfat-fs-module.a"
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && $(CMAKE_COMMAND) -P CMakeFiles/fat-fs-module.dir/cmake_clean_target.cmake
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fat-fs-module.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fat-fs-module/CMakeFiles/fat-fs-module.dir/build: fat-fs-module/libfat-fs-module.a

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/build

fat-fs-module/CMakeFiles/fat-fs-module.dir/requires: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ff.c.obj.requires
fat-fs-module/CMakeFiles/fat-fs-module.dir/requires: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/diskio.c.obj.requires
fat-fs-module/CMakeFiles/fat-fs-module.dir/requires: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/sdcard.c.obj.requires
fat-fs-module/CMakeFiles/fat-fs-module.dir/requires: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/w25qxx.c.obj.requires
fat-fs-module/CMakeFiles/fat-fs-module.dir/requires: fat-fs-module/CMakeFiles/fat-fs-module.dir/lib/ccsbcs.c.obj.requires

.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/requires

fat-fs-module/CMakeFiles/fat-fs-module.dir/clean:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module && $(CMAKE_COMMAND) -P CMakeFiles/fat-fs-module.dir/cmake_clean.cmake
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/clean

fat-fs-module/CMakeFiles/fat-fs-module.dir/depend:
	cd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/fat-fs-module /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module /home/tration/work/kendryte/xb-k210/sdk/alloy-eyes-sdk/build/lcd/fat-fs-module/CMakeFiles/fat-fs-module.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fat-fs-module/CMakeFiles/fat-fs-module.dir/depend

