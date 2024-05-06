cmake_minimum_required(VERSION 3.14)

# Project definitions
project(news-client-server-library
  VERSION 1.0
  DESCRIPTION "Client/Server library"
  LANGUAGES CXX
)

# Enforce C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler and linker options
set(COMPILER_FLAGS_COMMON "-Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wno-switch" CACHE STRING "Common compiler flags for all builds")

set(CXX_FLAGS_COMMON "${COMPILER_FLAGS_COMMON}" CACHE STRING "C++ compiler flags for all builds")

set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} ${CXX_FLAGS_COMMON}")

# Default to RelWithDebInfo build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

# Output compiler commands, used by some editors
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project root directory for disk database
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})
add_compile_definitions(PROJECT_ROOT="${PROJECT_ROOT}")

# Setting up the library
include_directories(src)
add_subdirectory(src)
add_subdirectory(bin)

SET(database_include_dirs
         $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
SET(clientserver_include_dirs
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROJECT_BINARY_DIR}/src
)

# ##################### Build type, etc ########################

# # we default to Release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

# # output build type and compiler flags
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Print summary of configuration
set(MSG_CMAKE_SUMMARY "CMake Summary")

# CMake version numbers
string(APPEND MSG_CMAKE_SUMMARY "\n\
   |-- Version Information --\n\
   |   |-- Installed on build platform:        ${CMAKE_VERSION}\n\
   |   `-- Required to generate build system:  ${CMAKE_MINIMUM_REQUIRED_VERSION}\n\
   |"
)

# Build type and according compiler flags
string(APPEND MSG_CMAKE_SUMMARY "\n\
   `-- Build Information --\n\
       |-- Type: ${CMAKE_BUILD_TYPE}\n\
       `-- C++ flags\n\
           `-- Release:\n\
                 ${CMAKE_CXX_FLAGS_RELEASE}\n\
")

message(STATUS "${MSG_CMAKE_SUMMARY}")
