# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ivam/HW/Dijkstra-HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivam/HW/Dijkstra-HW2/build

# Include any dependencies generated for this target.
include CMakeFiles/PA1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PA1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA1.dir/flags.make

CMakeFiles/PA1.dir/src/GridGraph.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/GridGraph.cpp.o: ../src/GridGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivam/HW/Dijkstra-HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA1.dir/src/GridGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA1.dir/src/GridGraph.cpp.o -c /home/ivam/HW/Dijkstra-HW2/src/GridGraph.cpp

CMakeFiles/PA1.dir/src/GridGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/GridGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivam/HW/Dijkstra-HW2/src/GridGraph.cpp > CMakeFiles/PA1.dir/src/GridGraph.cpp.i

CMakeFiles/PA1.dir/src/GridGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/GridGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivam/HW/Dijkstra-HW2/src/GridGraph.cpp -o CMakeFiles/PA1.dir/src/GridGraph.cpp.s

CMakeFiles/PA1.dir/src/GridGraph.cpp.o.requires:

.PHONY : CMakeFiles/PA1.dir/src/GridGraph.cpp.o.requires

CMakeFiles/PA1.dir/src/GridGraph.cpp.o.provides: CMakeFiles/PA1.dir/src/GridGraph.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA1.dir/build.make CMakeFiles/PA1.dir/src/GridGraph.cpp.o.provides.build
.PHONY : CMakeFiles/PA1.dir/src/GridGraph.cpp.o.provides

CMakeFiles/PA1.dir/src/GridGraph.cpp.o.provides.build: CMakeFiles/PA1.dir/src/GridGraph.cpp.o


CMakeFiles/PA1.dir/src/heap.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/heap.cpp.o: ../src/heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivam/HW/Dijkstra-HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PA1.dir/src/heap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA1.dir/src/heap.cpp.o -c /home/ivam/HW/Dijkstra-HW2/src/heap.cpp

CMakeFiles/PA1.dir/src/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/heap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivam/HW/Dijkstra-HW2/src/heap.cpp > CMakeFiles/PA1.dir/src/heap.cpp.i

CMakeFiles/PA1.dir/src/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/heap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivam/HW/Dijkstra-HW2/src/heap.cpp -o CMakeFiles/PA1.dir/src/heap.cpp.s

CMakeFiles/PA1.dir/src/heap.cpp.o.requires:

.PHONY : CMakeFiles/PA1.dir/src/heap.cpp.o.requires

CMakeFiles/PA1.dir/src/heap.cpp.o.provides: CMakeFiles/PA1.dir/src/heap.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA1.dir/build.make CMakeFiles/PA1.dir/src/heap.cpp.o.provides.build
.PHONY : CMakeFiles/PA1.dir/src/heap.cpp.o.provides

CMakeFiles/PA1.dir/src/heap.cpp.o.provides.build: CMakeFiles/PA1.dir/src/heap.cpp.o


CMakeFiles/PA1.dir/src/main.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivam/HW/Dijkstra-HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PA1.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA1.dir/src/main.cpp.o -c /home/ivam/HW/Dijkstra-HW2/src/main.cpp

CMakeFiles/PA1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivam/HW/Dijkstra-HW2/src/main.cpp > CMakeFiles/PA1.dir/src/main.cpp.i

CMakeFiles/PA1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivam/HW/Dijkstra-HW2/src/main.cpp -o CMakeFiles/PA1.dir/src/main.cpp.s

CMakeFiles/PA1.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/PA1.dir/src/main.cpp.o.requires

CMakeFiles/PA1.dir/src/main.cpp.o.provides: CMakeFiles/PA1.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA1.dir/build.make CMakeFiles/PA1.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/PA1.dir/src/main.cpp.o.provides

CMakeFiles/PA1.dir/src/main.cpp.o.provides.build: CMakeFiles/PA1.dir/src/main.cpp.o


CMakeFiles/PA1.dir/src/parser.cpp.o: CMakeFiles/PA1.dir/flags.make
CMakeFiles/PA1.dir/src/parser.cpp.o: ../src/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivam/HW/Dijkstra-HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PA1.dir/src/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA1.dir/src/parser.cpp.o -c /home/ivam/HW/Dijkstra-HW2/src/parser.cpp

CMakeFiles/PA1.dir/src/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA1.dir/src/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivam/HW/Dijkstra-HW2/src/parser.cpp > CMakeFiles/PA1.dir/src/parser.cpp.i

CMakeFiles/PA1.dir/src/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA1.dir/src/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivam/HW/Dijkstra-HW2/src/parser.cpp -o CMakeFiles/PA1.dir/src/parser.cpp.s

CMakeFiles/PA1.dir/src/parser.cpp.o.requires:

.PHONY : CMakeFiles/PA1.dir/src/parser.cpp.o.requires

CMakeFiles/PA1.dir/src/parser.cpp.o.provides: CMakeFiles/PA1.dir/src/parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA1.dir/build.make CMakeFiles/PA1.dir/src/parser.cpp.o.provides.build
.PHONY : CMakeFiles/PA1.dir/src/parser.cpp.o.provides

CMakeFiles/PA1.dir/src/parser.cpp.o.provides.build: CMakeFiles/PA1.dir/src/parser.cpp.o


# Object files for target PA1
PA1_OBJECTS = \
"CMakeFiles/PA1.dir/src/GridGraph.cpp.o" \
"CMakeFiles/PA1.dir/src/heap.cpp.o" \
"CMakeFiles/PA1.dir/src/main.cpp.o" \
"CMakeFiles/PA1.dir/src/parser.cpp.o"

# External object files for target PA1
PA1_EXTERNAL_OBJECTS =

PA1: CMakeFiles/PA1.dir/src/GridGraph.cpp.o
PA1: CMakeFiles/PA1.dir/src/heap.cpp.o
PA1: CMakeFiles/PA1.dir/src/main.cpp.o
PA1: CMakeFiles/PA1.dir/src/parser.cpp.o
PA1: CMakeFiles/PA1.dir/build.make
PA1: CMakeFiles/PA1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivam/HW/Dijkstra-HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PA1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA1.dir/build: PA1

.PHONY : CMakeFiles/PA1.dir/build

CMakeFiles/PA1.dir/requires: CMakeFiles/PA1.dir/src/GridGraph.cpp.o.requires
CMakeFiles/PA1.dir/requires: CMakeFiles/PA1.dir/src/heap.cpp.o.requires
CMakeFiles/PA1.dir/requires: CMakeFiles/PA1.dir/src/main.cpp.o.requires
CMakeFiles/PA1.dir/requires: CMakeFiles/PA1.dir/src/parser.cpp.o.requires

.PHONY : CMakeFiles/PA1.dir/requires

CMakeFiles/PA1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA1.dir/clean

CMakeFiles/PA1.dir/depend:
	cd /home/ivam/HW/Dijkstra-HW2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivam/HW/Dijkstra-HW2 /home/ivam/HW/Dijkstra-HW2 /home/ivam/HW/Dijkstra-HW2/build /home/ivam/HW/Dijkstra-HW2/build /home/ivam/HW/Dijkstra-HW2/build/CMakeFiles/PA1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA1.dir/depend

