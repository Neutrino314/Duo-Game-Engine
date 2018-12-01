# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/programming/Duo-Game-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/programming/Duo-Game-Engine

# Include any dependencies generated for this target.
include CMakeFiles/graphics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphics.dir/flags.make

CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o: source/graphics/DUO-Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp

CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp > CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.i

CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp -o CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.s

# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

lib/libgraphics.a: CMakeFiles/graphics.dir/source/graphics/DUO-Graphics.cpp.o
lib/libgraphics.a: CMakeFiles/graphics.dir/build.make
lib/libgraphics.a: CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library lib/libgraphics.a"
	$(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphics.dir/build: lib/libgraphics.a

.PHONY : CMakeFiles/graphics.dir/build

CMakeFiles/graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphics.dir/clean

CMakeFiles/graphics.dir/depend:
	cd /home/alex/programming/Duo-Game-Engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine/CMakeFiles/graphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphics.dir/depend
