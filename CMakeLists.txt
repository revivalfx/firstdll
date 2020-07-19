cmake_minimum_required(VERSION 3.18)
project(firstdll)
include (GenerateExportHeader)

set (VERSION_MAJOR_1)
set (VERSION_MINOR_0)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(TOOLCHAIN_PREFIX /usr/bin/x86_64-w64-mingw32)
SET (LIB_TYPE SHARED)
# set compiler
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}-gcc-win32)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++-win32)
set(CMAKE_RC_COMPILER  ${TOOLCHAIN_PREFIX}-windres)

# target environment on the build host system
#   set 1st to dir with the cross compiler's C/C++ headers/libs
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_PREFIX})

# modify default behavior of FIND_XXX() commands to
# search for headers/libs in the target environment and
# search for programs in the build host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#file (GLOB SOURCES "src/*.cpp")

#Flags used by the linker during the creation of shared libraries
# during all build types.
set(CMAKE_SHARED_LINKER_FLAGS "-shared -o shared_lib.dll -Wl,--out-implib,libshared_lib.a") 
set(CMAKE_CXX_FLAGS "-o shared_lib.o")

set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
# use emulator for `try_run` calls
set(CMAKE_CROSSCOMPILING_EMULATOR wine64)

add_library(shared_lib.dll SHARED shared_lib.cpp shared_lib.h)
set_target_properties(shared_lib.dll PROPERTIES
        PREFIX ""
        SUFFIX ""
        LINK_FLAGS "-Wl,--add-stdcall-alias"
        POSITION_INDEPENDENT_CODE 0 # this is to avoid MinGW warning; 
        # MinGW generates position-independent-code for DLL by default
)

#set(SOURCE shared_lib.cpp)
add_library(shared_lib ${LIB_TYPE} shared_lib.cpp)
GENERATE_EXPORT_HEADER(shared_lib 
             BASE_NAME shared_lib 
             EXPORT_MACRO_NAME shared_lib_EXPORT
             EXPORT_FILE_NAME shared_lib_Export.h
             STATIC_DEFINE shared_lib_BUILT_AS_STATIC
)
#add_executable(${PROJECT_NAME} ${SOURCE})

