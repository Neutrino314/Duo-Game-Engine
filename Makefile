# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alex/programming/Duo-Game-Engine/CMakeFiles /home/alex/programming/Duo-Game-Engine/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alex/programming/Duo-Game-Engine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Editor_exec

# Build rule for target.
Editor_exec: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Editor_exec
.PHONY : Editor_exec

# fast build rule for target.
Editor_exec/fast:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/build
.PHONY : Editor_exec/fast

#=============================================================================
# Target rules for targets named engine_lib

# Build rule for target.
engine_lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 engine_lib
.PHONY : engine_lib

# fast build rule for target.
engine_lib/fast:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/build
.PHONY : engine_lib/fast

DUO-Core/source/gameObject/DUO-GameObject.o: DUO-Core/source/gameObject/DUO-GameObject.cpp.o

.PHONY : DUO-Core/source/gameObject/DUO-GameObject.o

# target to build an object file
DUO-Core/source/gameObject/DUO-GameObject.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObject.cpp.o
.PHONY : DUO-Core/source/gameObject/DUO-GameObject.cpp.o

DUO-Core/source/gameObject/DUO-GameObject.i: DUO-Core/source/gameObject/DUO-GameObject.cpp.i

.PHONY : DUO-Core/source/gameObject/DUO-GameObject.i

# target to preprocess a source file
DUO-Core/source/gameObject/DUO-GameObject.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObject.cpp.i
.PHONY : DUO-Core/source/gameObject/DUO-GameObject.cpp.i

DUO-Core/source/gameObject/DUO-GameObject.s: DUO-Core/source/gameObject/DUO-GameObject.cpp.s

.PHONY : DUO-Core/source/gameObject/DUO-GameObject.s

# target to generate assembly for a file
DUO-Core/source/gameObject/DUO-GameObject.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObject.cpp.s
.PHONY : DUO-Core/source/gameObject/DUO-GameObject.cpp.s

DUO-Core/source/gameObject/DUO-GameObjectComponent.o: DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.o

.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.o

# target to build an object file
DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.o
.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.o

DUO-Core/source/gameObject/DUO-GameObjectComponent.i: DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.i

.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.i

# target to preprocess a source file
DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.i
.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.i

DUO-Core/source/gameObject/DUO-GameObjectComponent.s: DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.s

.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.s

# target to generate assembly for a file
DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.s
.PHONY : DUO-Core/source/gameObject/DUO-GameObjectComponent.cpp.s

DUO-Core/source/gameObject/DUO-Scene.o: DUO-Core/source/gameObject/DUO-Scene.cpp.o

.PHONY : DUO-Core/source/gameObject/DUO-Scene.o

# target to build an object file
DUO-Core/source/gameObject/DUO-Scene.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Scene.cpp.o
.PHONY : DUO-Core/source/gameObject/DUO-Scene.cpp.o

DUO-Core/source/gameObject/DUO-Scene.i: DUO-Core/source/gameObject/DUO-Scene.cpp.i

.PHONY : DUO-Core/source/gameObject/DUO-Scene.i

# target to preprocess a source file
DUO-Core/source/gameObject/DUO-Scene.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Scene.cpp.i
.PHONY : DUO-Core/source/gameObject/DUO-Scene.cpp.i

DUO-Core/source/gameObject/DUO-Scene.s: DUO-Core/source/gameObject/DUO-Scene.cpp.s

.PHONY : DUO-Core/source/gameObject/DUO-Scene.s

# target to generate assembly for a file
DUO-Core/source/gameObject/DUO-Scene.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Scene.cpp.s
.PHONY : DUO-Core/source/gameObject/DUO-Scene.cpp.s

DUO-Core/source/gameObject/DUO-Utils.o: DUO-Core/source/gameObject/DUO-Utils.cpp.o

.PHONY : DUO-Core/source/gameObject/DUO-Utils.o

# target to build an object file
DUO-Core/source/gameObject/DUO-Utils.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Utils.cpp.o
.PHONY : DUO-Core/source/gameObject/DUO-Utils.cpp.o

DUO-Core/source/gameObject/DUO-Utils.i: DUO-Core/source/gameObject/DUO-Utils.cpp.i

.PHONY : DUO-Core/source/gameObject/DUO-Utils.i

# target to preprocess a source file
DUO-Core/source/gameObject/DUO-Utils.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Utils.cpp.i
.PHONY : DUO-Core/source/gameObject/DUO-Utils.cpp.i

DUO-Core/source/gameObject/DUO-Utils.s: DUO-Core/source/gameObject/DUO-Utils.cpp.s

.PHONY : DUO-Core/source/gameObject/DUO-Utils.s

# target to generate assembly for a file
DUO-Core/source/gameObject/DUO-Utils.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/gameObject/DUO-Utils.cpp.s
.PHONY : DUO-Core/source/gameObject/DUO-Utils.cpp.s

DUO-Core/source/graphics/DUO-Graphics.o: DUO-Core/source/graphics/DUO-Graphics.cpp.o

.PHONY : DUO-Core/source/graphics/DUO-Graphics.o

# target to build an object file
DUO-Core/source/graphics/DUO-Graphics.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/graphics/DUO-Graphics.cpp.o
.PHONY : DUO-Core/source/graphics/DUO-Graphics.cpp.o

DUO-Core/source/graphics/DUO-Graphics.i: DUO-Core/source/graphics/DUO-Graphics.cpp.i

.PHONY : DUO-Core/source/graphics/DUO-Graphics.i

# target to preprocess a source file
DUO-Core/source/graphics/DUO-Graphics.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/graphics/DUO-Graphics.cpp.i
.PHONY : DUO-Core/source/graphics/DUO-Graphics.cpp.i

DUO-Core/source/graphics/DUO-Graphics.s: DUO-Core/source/graphics/DUO-Graphics.cpp.s

.PHONY : DUO-Core/source/graphics/DUO-Graphics.s

# target to generate assembly for a file
DUO-Core/source/graphics/DUO-Graphics.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/graphics/DUO-Graphics.cpp.s
.PHONY : DUO-Core/source/graphics/DUO-Graphics.cpp.s

DUO-Core/source/maths/DUO-AABB.o: DUO-Core/source/maths/DUO-AABB.cpp.o

.PHONY : DUO-Core/source/maths/DUO-AABB.o

# target to build an object file
DUO-Core/source/maths/DUO-AABB.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-AABB.cpp.o
.PHONY : DUO-Core/source/maths/DUO-AABB.cpp.o

DUO-Core/source/maths/DUO-AABB.i: DUO-Core/source/maths/DUO-AABB.cpp.i

.PHONY : DUO-Core/source/maths/DUO-AABB.i

# target to preprocess a source file
DUO-Core/source/maths/DUO-AABB.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-AABB.cpp.i
.PHONY : DUO-Core/source/maths/DUO-AABB.cpp.i

DUO-Core/source/maths/DUO-AABB.s: DUO-Core/source/maths/DUO-AABB.cpp.s

.PHONY : DUO-Core/source/maths/DUO-AABB.s

# target to generate assembly for a file
DUO-Core/source/maths/DUO-AABB.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-AABB.cpp.s
.PHONY : DUO-Core/source/maths/DUO-AABB.cpp.s

DUO-Core/source/maths/DUO-Maths.o: DUO-Core/source/maths/DUO-Maths.cpp.o

.PHONY : DUO-Core/source/maths/DUO-Maths.o

# target to build an object file
DUO-Core/source/maths/DUO-Maths.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Maths.cpp.o
.PHONY : DUO-Core/source/maths/DUO-Maths.cpp.o

DUO-Core/source/maths/DUO-Maths.i: DUO-Core/source/maths/DUO-Maths.cpp.i

.PHONY : DUO-Core/source/maths/DUO-Maths.i

# target to preprocess a source file
DUO-Core/source/maths/DUO-Maths.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Maths.cpp.i
.PHONY : DUO-Core/source/maths/DUO-Maths.cpp.i

DUO-Core/source/maths/DUO-Maths.s: DUO-Core/source/maths/DUO-Maths.cpp.s

.PHONY : DUO-Core/source/maths/DUO-Maths.s

# target to generate assembly for a file
DUO-Core/source/maths/DUO-Maths.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Maths.cpp.s
.PHONY : DUO-Core/source/maths/DUO-Maths.cpp.s

DUO-Core/source/maths/DUO-Vector2.o: DUO-Core/source/maths/DUO-Vector2.cpp.o

.PHONY : DUO-Core/source/maths/DUO-Vector2.o

# target to build an object file
DUO-Core/source/maths/DUO-Vector2.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Vector2.cpp.o
.PHONY : DUO-Core/source/maths/DUO-Vector2.cpp.o

DUO-Core/source/maths/DUO-Vector2.i: DUO-Core/source/maths/DUO-Vector2.cpp.i

.PHONY : DUO-Core/source/maths/DUO-Vector2.i

# target to preprocess a source file
DUO-Core/source/maths/DUO-Vector2.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Vector2.cpp.i
.PHONY : DUO-Core/source/maths/DUO-Vector2.cpp.i

DUO-Core/source/maths/DUO-Vector2.s: DUO-Core/source/maths/DUO-Vector2.cpp.s

.PHONY : DUO-Core/source/maths/DUO-Vector2.s

# target to generate assembly for a file
DUO-Core/source/maths/DUO-Vector2.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/maths/DUO-Vector2.cpp.s
.PHONY : DUO-Core/source/maths/DUO-Vector2.cpp.s

DUO-Core/source/runtime/DUO-Keyboard.o: DUO-Core/source/runtime/DUO-Keyboard.cpp.o

.PHONY : DUO-Core/source/runtime/DUO-Keyboard.o

# target to build an object file
DUO-Core/source/runtime/DUO-Keyboard.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-Keyboard.cpp.o
.PHONY : DUO-Core/source/runtime/DUO-Keyboard.cpp.o

DUO-Core/source/runtime/DUO-Keyboard.i: DUO-Core/source/runtime/DUO-Keyboard.cpp.i

.PHONY : DUO-Core/source/runtime/DUO-Keyboard.i

# target to preprocess a source file
DUO-Core/source/runtime/DUO-Keyboard.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-Keyboard.cpp.i
.PHONY : DUO-Core/source/runtime/DUO-Keyboard.cpp.i

DUO-Core/source/runtime/DUO-Keyboard.s: DUO-Core/source/runtime/DUO-Keyboard.cpp.s

.PHONY : DUO-Core/source/runtime/DUO-Keyboard.s

# target to generate assembly for a file
DUO-Core/source/runtime/DUO-Keyboard.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-Keyboard.cpp.s
.PHONY : DUO-Core/source/runtime/DUO-Keyboard.cpp.s

DUO-Core/source/runtime/DUO-application.o: DUO-Core/source/runtime/DUO-application.cpp.o

.PHONY : DUO-Core/source/runtime/DUO-application.o

# target to build an object file
DUO-Core/source/runtime/DUO-application.cpp.o:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-application.cpp.o
.PHONY : DUO-Core/source/runtime/DUO-application.cpp.o

DUO-Core/source/runtime/DUO-application.i: DUO-Core/source/runtime/DUO-application.cpp.i

.PHONY : DUO-Core/source/runtime/DUO-application.i

# target to preprocess a source file
DUO-Core/source/runtime/DUO-application.cpp.i:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-application.cpp.i
.PHONY : DUO-Core/source/runtime/DUO-application.cpp.i

DUO-Core/source/runtime/DUO-application.s: DUO-Core/source/runtime/DUO-application.cpp.s

.PHONY : DUO-Core/source/runtime/DUO-application.s

# target to generate assembly for a file
DUO-Core/source/runtime/DUO-application.cpp.s:
	$(MAKE) -f CMakeFiles/engine_lib.dir/build.make CMakeFiles/engine_lib.dir/DUO-Core/source/runtime/DUO-application.cpp.s
.PHONY : DUO-Core/source/runtime/DUO-application.cpp.s

Editor/src/CLI/sceneEditor.o: Editor/src/CLI/sceneEditor.cpp.o

.PHONY : Editor/src/CLI/sceneEditor.o

# target to build an object file
Editor/src/CLI/sceneEditor.cpp.o:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/CLI/sceneEditor.cpp.o
.PHONY : Editor/src/CLI/sceneEditor.cpp.o

Editor/src/CLI/sceneEditor.i: Editor/src/CLI/sceneEditor.cpp.i

.PHONY : Editor/src/CLI/sceneEditor.i

# target to preprocess a source file
Editor/src/CLI/sceneEditor.cpp.i:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/CLI/sceneEditor.cpp.i
.PHONY : Editor/src/CLI/sceneEditor.cpp.i

Editor/src/CLI/sceneEditor.s: Editor/src/CLI/sceneEditor.cpp.s

.PHONY : Editor/src/CLI/sceneEditor.s

# target to generate assembly for a file
Editor/src/CLI/sceneEditor.cpp.s:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/CLI/sceneEditor.cpp.s
.PHONY : Editor/src/CLI/sceneEditor.cpp.s

Editor/src/main.o: Editor/src/main.cpp.o

.PHONY : Editor/src/main.o

# target to build an object file
Editor/src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/main.cpp.o
.PHONY : Editor/src/main.cpp.o

Editor/src/main.i: Editor/src/main.cpp.i

.PHONY : Editor/src/main.i

# target to preprocess a source file
Editor/src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/main.cpp.i
.PHONY : Editor/src/main.cpp.i

Editor/src/main.s: Editor/src/main.cpp.s

.PHONY : Editor/src/main.s

# target to generate assembly for a file
Editor/src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Editor_exec.dir/build.make CMakeFiles/Editor_exec.dir/Editor/src/main.cpp.s
.PHONY : Editor/src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Editor_exec"
	@echo "... engine_lib"
	@echo "... DUO-Core/source/gameObject/DUO-GameObject.o"
	@echo "... DUO-Core/source/gameObject/DUO-GameObject.i"
	@echo "... DUO-Core/source/gameObject/DUO-GameObject.s"
	@echo "... DUO-Core/source/gameObject/DUO-GameObjectComponent.o"
	@echo "... DUO-Core/source/gameObject/DUO-GameObjectComponent.i"
	@echo "... DUO-Core/source/gameObject/DUO-GameObjectComponent.s"
	@echo "... DUO-Core/source/gameObject/DUO-Scene.o"
	@echo "... DUO-Core/source/gameObject/DUO-Scene.i"
	@echo "... DUO-Core/source/gameObject/DUO-Scene.s"
	@echo "... DUO-Core/source/gameObject/DUO-Utils.o"
	@echo "... DUO-Core/source/gameObject/DUO-Utils.i"
	@echo "... DUO-Core/source/gameObject/DUO-Utils.s"
	@echo "... DUO-Core/source/graphics/DUO-Graphics.o"
	@echo "... DUO-Core/source/graphics/DUO-Graphics.i"
	@echo "... DUO-Core/source/graphics/DUO-Graphics.s"
	@echo "... DUO-Core/source/maths/DUO-AABB.o"
	@echo "... DUO-Core/source/maths/DUO-AABB.i"
	@echo "... DUO-Core/source/maths/DUO-AABB.s"
	@echo "... DUO-Core/source/maths/DUO-Maths.o"
	@echo "... DUO-Core/source/maths/DUO-Maths.i"
	@echo "... DUO-Core/source/maths/DUO-Maths.s"
	@echo "... DUO-Core/source/maths/DUO-Vector2.o"
	@echo "... DUO-Core/source/maths/DUO-Vector2.i"
	@echo "... DUO-Core/source/maths/DUO-Vector2.s"
	@echo "... DUO-Core/source/runtime/DUO-Keyboard.o"
	@echo "... DUO-Core/source/runtime/DUO-Keyboard.i"
	@echo "... DUO-Core/source/runtime/DUO-Keyboard.s"
	@echo "... DUO-Core/source/runtime/DUO-application.o"
	@echo "... DUO-Core/source/runtime/DUO-application.i"
	@echo "... DUO-Core/source/runtime/DUO-application.s"
	@echo "... Editor/src/CLI/sceneEditor.o"
	@echo "... Editor/src/CLI/sceneEditor.i"
	@echo "... Editor/src/CLI/sceneEditor.s"
	@echo "... Editor/src/main.o"
	@echo "... Editor/src/main.i"
	@echo "... Editor/src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

