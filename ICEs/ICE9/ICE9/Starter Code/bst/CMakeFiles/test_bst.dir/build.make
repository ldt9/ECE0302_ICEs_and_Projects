# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst"

# Include any dependencies generated for this target.
include CMakeFiles/test_bst.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_bst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_bst.dir/flags.make

CMakeFiles/test_bst.dir/test_bst.cpp.o: CMakeFiles/test_bst.dir/flags.make
CMakeFiles/test_bst.dir/test_bst.cpp.o: test_bst.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_bst.dir/test_bst.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_bst.dir/test_bst.cpp.o -c "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/test_bst.cpp"

CMakeFiles/test_bst.dir/test_bst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_bst.dir/test_bst.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/test_bst.cpp" > CMakeFiles/test_bst.dir/test_bst.cpp.i

CMakeFiles/test_bst.dir/test_bst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_bst.dir/test_bst.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/test_bst.cpp" -o CMakeFiles/test_bst.dir/test_bst.cpp.s

# Object files for target test_bst
test_bst_OBJECTS = \
"CMakeFiles/test_bst.dir/test_bst.cpp.o"

# External object files for target test_bst
test_bst_EXTERNAL_OBJECTS =

test_bst: CMakeFiles/test_bst.dir/test_bst.cpp.o
test_bst: CMakeFiles/test_bst.dir/build.make
test_bst: CMakeFiles/test_bst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_bst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_bst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_bst.dir/build: test_bst

.PHONY : CMakeFiles/test_bst.dir/build

CMakeFiles/test_bst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_bst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_bst.dir/clean

CMakeFiles/test_bst.dir/depend:
	cd "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst" "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst" "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst" "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst" "/home/lucas/ECE0302/ICEs/ICE9/ICE9/Starter Code/bst/CMakeFiles/test_bst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_bst.dir/depend

