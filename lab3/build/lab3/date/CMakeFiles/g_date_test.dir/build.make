# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build"

# Include any dependencies generated for this target.
include lab3/date/CMakeFiles/g_date_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lab3/date/CMakeFiles/g_date_test.dir/compiler_depend.make

# Include the progress variables for this target.
include lab3/date/CMakeFiles/g_date_test.dir/progress.make

# Include the compile flags for this target's objects.
include lab3/date/CMakeFiles/g_date_test.dir/flags.make

lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o: lab3/date/CMakeFiles/g_date_test.dir/flags.make
lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o: /home/Kojjan/Documents/School/EDAF50\ -\ C++\ Programming/lab3/lab3/date/g_date_test.cc
lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o: lab3/date/CMakeFiles/g_date_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o -MF CMakeFiles/g_date_test.dir/g_date_test.cc.o.d -o CMakeFiles/g_date_test.dir/g_date_test.cc.o -c "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/g_date_test.cc"

lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/g_date_test.dir/g_date_test.cc.i"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/g_date_test.cc" > CMakeFiles/g_date_test.dir/g_date_test.cc.i

lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/g_date_test.dir/g_date_test.cc.s"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/g_date_test.cc" -o CMakeFiles/g_date_test.dir/g_date_test.cc.s

lab3/date/CMakeFiles/g_date_test.dir/date.cc.o: lab3/date/CMakeFiles/g_date_test.dir/flags.make
lab3/date/CMakeFiles/g_date_test.dir/date.cc.o: /home/Kojjan/Documents/School/EDAF50\ -\ C++\ Programming/lab3/lab3/date/date.cc
lab3/date/CMakeFiles/g_date_test.dir/date.cc.o: lab3/date/CMakeFiles/g_date_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lab3/date/CMakeFiles/g_date_test.dir/date.cc.o"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lab3/date/CMakeFiles/g_date_test.dir/date.cc.o -MF CMakeFiles/g_date_test.dir/date.cc.o.d -o CMakeFiles/g_date_test.dir/date.cc.o -c "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/date.cc"

lab3/date/CMakeFiles/g_date_test.dir/date.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/g_date_test.dir/date.cc.i"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/date.cc" > CMakeFiles/g_date_test.dir/date.cc.i

lab3/date/CMakeFiles/g_date_test.dir/date.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/g_date_test.dir/date.cc.s"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date/date.cc" -o CMakeFiles/g_date_test.dir/date.cc.s

# Object files for target g_date_test
g_date_test_OBJECTS = \
"CMakeFiles/g_date_test.dir/g_date_test.cc.o" \
"CMakeFiles/g_date_test.dir/date.cc.o"

# External object files for target g_date_test
g_date_test_EXTERNAL_OBJECTS =

lab3/date/g_date_test: lab3/date/CMakeFiles/g_date_test.dir/g_date_test.cc.o
lab3/date/g_date_test: lab3/date/CMakeFiles/g_date_test.dir/date.cc.o
lab3/date/g_date_test: lab3/date/CMakeFiles/g_date_test.dir/build.make
lab3/date/g_date_test: lib/libgtest_main.a
lab3/date/g_date_test: lib/libgtest.a
lab3/date/g_date_test: lab3/date/CMakeFiles/g_date_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable g_date_test"
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/g_date_test.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && /usr/bin/cmake -D TEST_TARGET=g_date_test -D "TEST_EXECUTABLE=/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=g_date_test_TESTS -D "CTEST_FILE=/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/g_date_test[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
lab3/date/CMakeFiles/g_date_test.dir/build: lab3/date/g_date_test
.PHONY : lab3/date/CMakeFiles/g_date_test.dir/build

lab3/date/CMakeFiles/g_date_test.dir/clean:
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" && $(CMAKE_COMMAND) -P CMakeFiles/g_date_test.dir/cmake_clean.cmake
.PHONY : lab3/date/CMakeFiles/g_date_test.dir/clean

lab3/date/CMakeFiles/g_date_test.dir/depend:
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/lab3/date" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/date/CMakeFiles/g_date_test.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : lab3/date/CMakeFiles/g_date_test.dir/depend
