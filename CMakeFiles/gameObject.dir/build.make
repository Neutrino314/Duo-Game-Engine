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
include CMakeFiles/gameObject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameObject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameObject.dir/flags.make

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o: CMakeFiles/gameObject.dir/flags.make
CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o: source/gameObject/DUO-GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp > CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.i

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp -o CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.s

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o: CMakeFiles/gameObject.dir/flags.make
CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o: source/gameObject/DUO-GameObjectComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp > CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.i

CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp -o CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.s

CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o: CMakeFiles/gameObject.dir/flags.make
CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o: source/gameObject/DUO-Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp

CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp > CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.i

CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp -o CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.s

CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o: CMakeFiles/gameObject.dir/flags.make
CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o: source/gameObject/DUO-Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp

CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp > CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.i

CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp -o CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.s

# Object files for target gameObject
gameObject_OBJECTS = \
"CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o" \
"CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o" \
"CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o" \
"CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o"

# External object files for target gameObject
gameObject_EXTERNAL_OBJECTS =

lib/libgameObject.a: CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObject.cpp.o
lib/libgameObject.a: CMakeFiles/gameObject.dir/source/gameObject/DUO-GameObjectComponent.cpp.o
lib/libgameObject.a: CMakeFiles/gameObject.dir/source/gameObject/DUO-Scene.cpp.o
lib/libgameObject.a: CMakeFiles/gameObject.dir/source/gameObject/DUO-Utils.cpp.o
lib/libgameObject.a: CMakeFiles/gameObject.dir/build.make
lib/libgameObject.a: CMakeFiles/gameObject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/programming/Duo-Game-Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library lib/libgameObject.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gameObject.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameObject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameObject.dir/build: lib/libgameObject.a

.PHONY : CMakeFiles/gameObject.dir/build

CMakeFiles/gameObject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameObject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameObject.dir/clean

CMakeFiles/gameObject.dir/depend:
	cd /home/alex/programming/Duo-Game-Engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine/CMakeFiles/gameObject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameObject.dir/depend

