cmake_minimum_required (VERSION 3.5)
project (Lab1)
set (CMAKE_CXX_STANDARD 11)

# set build type to DEBUG
# set (CMAKE_BUILD_TYPE Debug)

# add the library to the include file search path
include_directories ("${PROJECT_SOURCE_DIR}/liblab1")

add_subdirectory(liblab1) 

# set compiler and linker flags
# add_compile_options("-O0")
#add_compile_options("-fsanitize=address")

# add the executables
add_executable(TestList ltest.cc)
add_executable(TestCoding test_coding.cc)

# link libraries
target_link_libraries(TestList LibLab1)
target_link_libraries(TestCoding LibLab1)

# import libraries for debuging
link_libraries("-fsanitize=address")

# use generator expressions to set flags in debug builds with address sanitizer
add_compile_options($<$<CONFIG:Debug>:-O0>)

# set compiler and linker flags to enable the relevant sanitizer
target_compile_options(TestList PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(TestList  $<$<CONFIG:Debug>:-fsanitize=address>)

target_compile_options(TestCoding PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(TestCoding  $<$<CONFIG:Debug>:-fsanitize=address>)

##################### Optional features below this line ############

# The version number. This is not needed but included
# to show how information can be passed from CMakeLists.txt
# to the program.
set (Simple_VERSION_MAJOR 1)
set (Simple_VERSION_MINOR 0)

