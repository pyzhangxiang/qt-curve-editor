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

doQtClassMoc(headers qthmocs)
doQtUiMoc(uis qtuimocs)
compileWithQt()

add_executable(${MY_PROJECT_NAME} ${sources} ${qthmocs} ${qtuimocs})
target_link_libraries(${MY_PROJECT_NAME} ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

