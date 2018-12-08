cmake_minimum_required(VERSION 3.5)
project(Editor-Engine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -lSDL2 -lSDL2_image -I${PROJECT_SOURCE_DIR}/DUO-Core/source/ -I${PROJECT_SOURCE_DIR}/")

set(engine_source_dir "${PROJECT_SOURCE_DIR}/DUO-Core/source/")

file (GLOB source_files "${engine_source_dir}/*.cpp")

file(GLOB gameObject_files "${engine_source_dir}gameObject/*.cpp")

file(GLOB graphics_files "${engine_source_dir}graphics/*.cpp")

file(GLOB maths_files "${engine_source_dir}maths/*.cpp")

file(GLOB runtime_files "${engine_source_dir}runtime/*.cpp")

set(LIBRARY_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/DUO-Core/lib/")

find_library(SDL "SDL2")

find_library(SDL_image "SDL2_image")

find_library(PTHREAD "pthread")

message(STATUS "${SDL_image}")

add_library(engine_lib SHARED "${gameObject_files};${graphics_files};${maths_files};${runtime_files};")

target_link_libraries(engine_lib ${SDL})

target_link_libraries(engine_lib ${SDL_image})

target_link_libraries(engine_lib ${PTHREAD})

set(editor_source_dir "${PROJECT_SOURCE_DIR}/Editor/src/")

file(GLOB editor_CLI_files "${editor_source_dir}CLI/*.cpp")

file(GLOB editor_Saving_files "${editor_source_dir}Saving/*.cpp")

add_executable(Editor_exec "${editor_CLI_files};${editor_Saving_files};${editor_source_dir}main.cpp;")

target_link_libraries(Editor_exec ${SDL})

target_link_libraries(Editor_exec ${SDL_image})

target_link_libraries(Editor_exec ${PTHREAD})

target_link_libraries(Editor_exec engine_lib)