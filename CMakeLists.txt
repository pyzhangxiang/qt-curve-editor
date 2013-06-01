cmake_minimum_required(VERSION 2.8)

set(MY_PROJECT_NAME qtCurveEditor)
PROJECT(${MY_PROJECT_NAME})

set(MY_CMAKE_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/cmake_config)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${MY_CMAKE_CONFIG})
include(qt_support)
include(utility)

# find opengl and directx
find_package(OpenGL)
if(OPENGL_FOUND)
    message("OPENGL FOUND\n${OPENGL_INCLUDE_DIR}\n" )
else(OPENGL_FOUND)
    # create project failed
    message(FATAL_ERROR "OPENGL NOT FOUND")
endif(OPENGL_FOUND)

#enable all warnings
add_definitions(-Wall)

add_subdirectory(src)

