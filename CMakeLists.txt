cmake_minimum_required(VERSION 3.4)
project(bwgl)

option(BWGL_STATIC_BUILD "Build BWGL as a static library." ON)
option(BWGL_ENABLE_GL_UNBIND "Enables glBindBuffer(..., 0) in code." ON)

### Find OpenGL and include that ###
find_package(OPENGL)
if (NOT ${OPENGL_FOUND})
    message(FATAL_ERROR "OpenGL not found.")
endif(NOT ${OPENGL_FOUND})
if (APPLE)
    set(OPENGL_INCLUDE_DIR ${OPENGL_INCLUDE_DIR}/Headers)
endif(APPLE)
include_directories(${OPENGL_INCLUDE_DIR})

# find all source, header and inline files
file(GLOB_RECURSE BWGL_SOURCES src/*cpp)
file(GLOB_RECURSE BWGL_HEADERS src/*hpp)

include_directories(src)

add_definitions(-std=c++11)
add_definitions(-DENABLE_GL_UNBIND=${BWGL_ENABLE_GL_UNBIND})

# build static- or shared BWGL library
if (BWGL_STATIC_BUILD)
    add_library(bwgl STATIC ${BWGL_SOURCES} ${BWGL_HEADERS})
else (BWGL_STATIC_BUILD)
    add_library(bwgl SHARED ${BWGL_SOURCES} ${BWGL_HEADERS})
endif (BWGL_STATIC_BUILD)

target_link_libraries(bwgl ${OPENGL_LIBRARIES})

##### Export include directory to parent scope ####

##### Export include directory to parent scope ####
set(BWGL_EXTRA_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR} PARENT_SCOPE)