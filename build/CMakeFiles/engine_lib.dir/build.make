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
CMAKE_BINARY_DIR = /home/alex/programming/Duo-Game-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/engine_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine_lib.dir/flags.make

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o: ../source/gameObject/DUO-GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp > CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.i

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObject.cpp -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.s

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o: ../source/gameObject/DUO-GameObjectComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp > CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.i

CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-GameObjectComponent.cpp -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.s

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o: ../source/gameObject/DUO-Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp > CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.i

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Scene.cpp -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.s

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o: ../source/gameObject/DUO-Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp > CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.i

CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/gameObject/DUO-Utils.cpp -o CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.s

CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o: ../source/graphics/DUO-Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp

CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp > CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.i

CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/graphics/DUO-Graphics.cpp -o CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.s

CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o: ../source/maths/DUO-AABB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/maths/DUO-AABB.cpp

CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/maths/DUO-AABB.cpp > CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.i

CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/maths/DUO-AABB.cpp -o CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.s

CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o: ../source/maths/DUO-Maths.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/maths/DUO-Maths.cpp

CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/maths/DUO-Maths.cpp > CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.i

CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/maths/DUO-Maths.cpp -o CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.s

CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o: ../source/runtime/DUO-Keyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-Keyboard.cpp

CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-Keyboard.cpp > CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.i

CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-Keyboard.cpp -o CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.s

CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o: CMakeFiles/engine_lib.dir/flags.make
CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o: ../source/runtime/DUO-application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o"
	/usr/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o -c /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-application.cpp

CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.i"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-application.cpp > CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.i

CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.s"
	/usr/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/programming/Duo-Game-Engine/source/runtime/DUO-application.cpp -o CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.s

# Object files for target engine_lib
engine_lib_OBJECTS = \
"CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o" \
"CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o" \
"CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o" \
"CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o" \
"CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o" \
"CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o" \
"CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o" \
"CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o" \
"CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o"

# External object files for target engine_lib
engine_lib_EXTERNAL_OBJECTS =

lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObject.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/gameObject/DUO-GameObjectComponent.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/gameObject/DUO-Scene.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/gameObject/DUO-Utils.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/graphics/DUO-Graphics.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/maths/DUO-AABB.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/maths/DUO-Maths.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/runtime/DUO-Keyboard.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/source/runtime/DUO-application.cpp.o
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/build.make
lib/libengine_lib.a: CMakeFiles/engine_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/programming/Duo-Game-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library lib/libengine_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/engine_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine_lib.dir/build: lib/libengine_lib.a

.PHONY : CMakeFiles/engine_lib.dir/build

CMakeFiles/engine_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine_lib.dir/clean

CMakeFiles/engine_lib.dir/depend:
	cd /home/alex/programming/Duo-Game-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine /home/alex/programming/Duo-Game-Engine/build /home/alex/programming/Duo-Game-Engine/build /home/alex/programming/Duo-Game-Engine/build/CMakeFiles/engine_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine_lib.dir/depend

