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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code"

# Include any dependencies generated for this target.
include CMakeFiles/mainXMLParser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainXMLParser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainXMLParser.dir/flags.make

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: CMakeFiles/mainXMLParser.dir/flags.make
CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o: mainXMLParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o -c "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/mainXMLParser.cpp"

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/mainXMLParser.cpp" > CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.i

CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/mainXMLParser.cpp" -o CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.s

# Object files for target mainXMLParser
mainXMLParser_OBJECTS = \
"CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o"

# External object files for target mainXMLParser
mainXMLParser_EXTERNAL_OBJECTS =

mainXMLParser: CMakeFiles/mainXMLParser.dir/mainXMLParser.cpp.o
mainXMLParser: CMakeFiles/mainXMLParser.dir/build.make
mainXMLParser: CMakeFiles/mainXMLParser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mainXMLParser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainXMLParser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainXMLParser.dir/build: mainXMLParser

.PHONY : CMakeFiles/mainXMLParser.dir/build

CMakeFiles/mainXMLParser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainXMLParser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainXMLParser.dir/clean

CMakeFiles/mainXMLParser.dir/depend:
	cd "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code" "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code" "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code" "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code" "/home/lucas/ECE0302/Projects/Project3/Starter Code-050cf8cd-9390-45be-b8af-1a002fd849c0/Starter Code/CMakeFiles/mainXMLParser.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mainXMLParser.dir/depend

