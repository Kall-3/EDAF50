# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build"

# Include any dependencies generated for this target.
include CMakeFiles/clientserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clientserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clientserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clientserver.dir/flags.make

CMakeFiles/clientserver.dir/src/connection.cc.o: CMakeFiles/clientserver.dir/flags.make
CMakeFiles/clientserver.dir/src/connection.cc.o: /home/Kojjan/Documents/School/EDAF50\ -\ C++\ Programming/project/clientserver/src/connection.cc
CMakeFiles/clientserver.dir/src/connection.cc.o: CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clientserver.dir/src/connection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clientserver.dir/src/connection.cc.o -MF CMakeFiles/clientserver.dir/src/connection.cc.o.d -o CMakeFiles/clientserver.dir/src/connection.cc.o -c "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/connection.cc"

CMakeFiles/clientserver.dir/src/connection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/src/connection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/connection.cc" > CMakeFiles/clientserver.dir/src/connection.cc.i

CMakeFiles/clientserver.dir/src/connection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/src/connection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/connection.cc" -o CMakeFiles/clientserver.dir/src/connection.cc.s

CMakeFiles/clientserver.dir/src/server.cc.o: CMakeFiles/clientserver.dir/flags.make
CMakeFiles/clientserver.dir/src/server.cc.o: /home/Kojjan/Documents/School/EDAF50\ -\ C++\ Programming/project/clientserver/src/server.cc
CMakeFiles/clientserver.dir/src/server.cc.o: CMakeFiles/clientserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/clientserver.dir/src/server.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clientserver.dir/src/server.cc.o -MF CMakeFiles/clientserver.dir/src/server.cc.o.d -o CMakeFiles/clientserver.dir/src/server.cc.o -c "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/server.cc"

CMakeFiles/clientserver.dir/src/server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clientserver.dir/src/server.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/server.cc" > CMakeFiles/clientserver.dir/src/server.cc.i

CMakeFiles/clientserver.dir/src/server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clientserver.dir/src/server.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/src/server.cc" -o CMakeFiles/clientserver.dir/src/server.cc.s

# Object files for target clientserver
clientserver_OBJECTS = \
"CMakeFiles/clientserver.dir/src/connection.cc.o" \
"CMakeFiles/clientserver.dir/src/server.cc.o"

# External object files for target clientserver
clientserver_EXTERNAL_OBJECTS =

libclientserver.a: CMakeFiles/clientserver.dir/src/connection.cc.o
libclientserver.a: CMakeFiles/clientserver.dir/src/server.cc.o
libclientserver.a: CMakeFiles/clientserver.dir/build.make
libclientserver.a: CMakeFiles/clientserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libclientserver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/clientserver.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clientserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clientserver.dir/build: libclientserver.a
.PHONY : CMakeFiles/clientserver.dir/build

CMakeFiles/clientserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clientserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clientserver.dir/clean

CMakeFiles/clientserver.dir/depend:
	cd "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build" "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/project/clientserver/build/CMakeFiles/clientserver.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/clientserver.dir/depend

