include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(headers)
set(cpps)
set(uis)
set(qtmocs)
set(qtuimocs)

file(GLOB_RECURSE headers *.h)
file(GLOB_RECURSE cpps *.cpp)
file(GLOB_RECURSE uis *.ui)

set(sources ${headers} ${cpps})
source_group_by_dir(sources)

#qt5_wrap_cpp(qtmocs ${headers})
qt5_wrap_ui(qtuimocs ${uis})

add_executable(${MY_PROJECT_NAME} ${sources} ${qtuimocs})
target_link_libraries(${MY_PROJECT_NAME} ${OPENGL_LIBRARIES})
QT5_USE_MODULES(${MY_PROJECT_NAME} Core Gui OpenGL Widgets)

