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
CMAKE_SOURCE_DIR = /home/alazca/development/126/lab03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alazca/development/126/lab03/build

# Include any dependencies generated for this target.
include CMakeFiles/a.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/a.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.dir/flags.make

CMakeFiles/a.dir/lab-3-cmpe126.cpp.o: CMakeFiles/a.dir/flags.make
CMakeFiles/a.dir/lab-3-cmpe126.cpp.o: /home/alazca/development/126/lab03/lab-3-cmpe126.cpp
CMakeFiles/a.dir/lab-3-cmpe126.cpp.o: CMakeFiles/a.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alazca/development/126/lab03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.dir/lab-3-cmpe126.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.dir/lab-3-cmpe126.cpp.o -MF CMakeFiles/a.dir/lab-3-cmpe126.cpp.o.d -o CMakeFiles/a.dir/lab-3-cmpe126.cpp.o -c /home/alazca/development/126/lab03/lab-3-cmpe126.cpp

CMakeFiles/a.dir/lab-3-cmpe126.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/a.dir/lab-3-cmpe126.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alazca/development/126/lab03/lab-3-cmpe126.cpp > CMakeFiles/a.dir/lab-3-cmpe126.cpp.i

CMakeFiles/a.dir/lab-3-cmpe126.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/a.dir/lab-3-cmpe126.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alazca/development/126/lab03/lab-3-cmpe126.cpp -o CMakeFiles/a.dir/lab-3-cmpe126.cpp.s

# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/lab-3-cmpe126.cpp.o"

# External object files for target a
a_EXTERNAL_OBJECTS =

a : CMakeFiles/a.dir/lab-3-cmpe126.cpp.o
a : CMakeFiles/a.dir/build.make
a : CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/alazca/development/126/lab03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.dir/build: a
.PHONY : CMakeFiles/a.dir/build

CMakeFiles/a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.dir/clean

CMakeFiles/a.dir/depend:
	cd /home/alazca/development/126/lab03/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alazca/development/126/lab03 /home/alazca/development/126/lab03 /home/alazca/development/126/lab03/build /home/alazca/development/126/lab03/build /home/alazca/development/126/lab03/build/CMakeFiles/a.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/a.dir/depend

