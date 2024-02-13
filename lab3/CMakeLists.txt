cmake_minimum_required(VERSION 3.3...3.6)
project(Lab3
    VERSION 0.0.1
    DESCRIPTION "Lab3 in c++ programming with unit testing."
    LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)
add_subdirectory(lab3)
