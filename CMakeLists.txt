cmake_minimum_required(VERSION 3.5)
project(DUO-Engine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -lSDL2 -lSDL2_image -I${PROJECT_SOURCE_DIR}/source/")

set(source_dir "${PROJECT_SOURCE_DIR}/source/")

file (GLOB source_files "${source_dir}/*.cpp")

file(GLOB gameObject_files "${source_dir}gameObject/*.cpp")

file(GLOB graphics_files "${source_dir}graphics/*.cpp")

file(GLOB maths_files "${source_dir}maths/*.cpp")

file(GLOB runtime_files "${source_dir}runtime/*.cpp")

set(LIBRARY_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/lib/")

find_library(SDL "SDL2")

find_library(SDL_image "SDL2_image")

find_library(PTHREAD "pthread")

message(STATUS "${SDL_image}")

add_library(engine_lib STATIC "${gameObject_files};${graphics_files};${maths_files};${runtime_files};")

target_link_libraries(engine_lib ${SDL})

target_link_libraries(engine_lib ${SDL_image})

target_link_libraries(engine_lib ${PTHREAD})

add_executable(output source/main.cpp)

target_link_libraries(output engine_lib)

target_link_libraries(output ${SDL})
