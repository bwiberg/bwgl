cmake_minimum_required(VERSION 3.4)
project(bwgl)

option(BWGL_STATIC_BUILD "Build BWGL as a static library." ON)
option(BWGL_ENABLE_GL_UNBIND "Enables glBindBuffer(..., 0) in code." ON)
set(BWGL_OPENGL_HEADER "Opengl.h" CACHE PATH "Include path to \"OpenGL.h\" or similar.")

# find all source and header files
file(GLOB_RECURSE BWGL_SOURCES src/*cpp)
file(GLOB_RECURSE BWGL_HEADERS src/*hpp)

include_directories(src)

# generate CMake library to link executables against
add_definitions(-std=c++11)
add_definitions(-DOPENGL_HEADER=<${BWGL_OPENGL_HEADER}>)
add_definitions(-DENABLE_GL_UNBIND=${BWGL_ENABLE_GL_UNBIND})

# build static- or shared BWGL library
if (BWGL_STATIC_BUILD)
    add_library(bwgl STATIC ${BWGL_SOURCES} ${BWGL_HEADERS})
else (BWGL_STATIC_BUILD)
    add_library(bwgl SHARED ${BWGL_SOURCES} ${BWGL_HEADERS})
endif (BWGL_STATIC_BUILD)