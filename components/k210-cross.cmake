# 使用 cmake -DCMAKE_TOOLCHAIN_FILE=~/k210-cross.cmake ..
# CMake toolchain file for building ARM software on linux environment 
# this one is important SET(CMAKE_SYSTEM_NAME Linux) 
# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH   /opt/kendryte-toolchain) 
# search for programs in the build host directories 
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER) 
# for libraries and headers in the target directories 
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY) 
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY) 
# specify the cross compiler 
SET(CMAKE_C_COMPILER   /opt/kendryte-toolchain/bin/riscv64-unknown-elf-gcc) 
SET(CMAKE_CXX_COMPILER /opt/kendryte-toolchain/bin/riscv64-unknown-elf-g++) 
SET(CMAKE_STRIP /opt/kendryte-toolchain/bin/riscv64-unknown-elf-strip)

