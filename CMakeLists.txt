cmake_minimum_required(VERSION 2.8.12)

set(MY_PROJECT_NAME qtCurveEditor)
PROJECT(${MY_PROJECT_NAME})

set(MY_CMAKE_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/cmake_config)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${MY_CMAKE_CONFIG})
include(utility)

# find opengl and directx
find_package(OpenGL)
if(OPENGL_FOUND)
    message("OPENGL FOUND\n${OPENGL_INCLUDE_DIR}\n" )
else(OPENGL_FOUND)
    # create project failed
    message(FATAL_ERROR "OPENGL NOT FOUND")
endif(OPENGL_FOUND)

########### Find QT5 packages ###########
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#enable all warnings
add_definitions(-Wall)

add_subdirectory(src)

