cmake_minimum_required(VERSION 3.5)
project(Editor-Engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -lSDL2 -lSDL2_image -I${PROJECT_SOURCE_DIR}/DUO-Core/source/ -I${PROJECT_SOURCE_DIR}/Editor/src/ -W")

set(engine_source_dir "${PROJECT_SOURCE_DIR}/DUO-Core/source/")

file (GLOB source_files "${engine_source_dir}/*.cpp")

file(GLOB gameObject_files "${engine_source_dir}gameObject/*.cpp")

file(GLOB graphics_files "${engine_source_dir}graphics/*.cpp")

file(GLOB maths_files "${engine_source_dir}maths/*.cpp")

file(GLOB runtime_files "${engine_source_dir}runtime/*.cpp")

file(GLOB util_files "${engine_source_dir}utils/*.cpp")

file(GLOB yaml_files "${engine_source_dir}yaml/*.cpp")

file(GLOB layer_files "${engine_source_dir}layers/*.cpp")

set(LIBRARY_OUTPUT_PATH  "${CMAKE_BINARY_DIR}/DUO-Core/lib/")

find_library(SDL "SDL2")

find_library(SDL_image "SDL2_image")

find_library(SDL_TTF "SDL2_ttf")

find_library(PTHREAD "pthread")

find_library(DLFCN "dlfcn")

add_library(engine_lib SHARED "${gameObject_files};${graphics_files};${maths_files};${runtime_files};${util_files};${yaml_files};${layer_files};")

target_link_libraries(engine_lib ${SDL})

target_link_libraries(engine_lib ${SDL_image})

target_link_libraries(engine_lib ${SDL_TTF})

target_link_libraries(engine_lib ${PTHREAD})

target_link_libraries(engine_lib ${PTHREAD})

target_link_libraries(engine_lib ${Boost_LIBRARIES})

set(editor_source_dir "${PROJECT_SOURCE_DIR}/Editor/src/")

file(GLOB editor_scripting_files "${editor_source_dir}scripting/component/*.cpp")

file(GLOB UI_files "${editor_source_dir}UI/*.cpp")

file(GLOB editor_assetManager_files "${editor_source_dir}assetManager/*.cpp")

file(GLOB editor_project_files "${editor_source_dir}project/*.cpp")

add_executable(output "${editor_CLI_files};${editor_source_dir}main.cpp;${editor_assetManager_files};${editor_project_files};${editor_scripting_files};${UI_files};")

target_link_libraries(output ${SDL})

target_link_libraries(output ${SDL_image})

target_link_libraries(output ${PTHREAD})

target_link_libraries(output engine_lib)