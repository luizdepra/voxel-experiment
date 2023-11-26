cmake_minimum_required(VERSION 3.7)

project(VoxelExperiment)

find_package(OpenGL REQUIRED)

set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)
set(VOXEL_SRC src/main.cpp)

set(SDL_SHARED OFF CACHE BOOL "" FORCE)

add_subdirectory(${VENDOR_DIR}/sdl2)

add_executable(voxel ${VOXEL_SRC})
target_include_directories(voxel PRIVATE ${VENDOR_DIR}/sdl2/include)
target_link_libraries(voxel SDL2-static SDL2main ${OPENGL_LIBRARY})
