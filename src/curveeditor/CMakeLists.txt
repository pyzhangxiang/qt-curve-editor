include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(headers)
set(cpps)
set(uis)
set(qrcs)
set(qthmocs)
set(qtuimocs)
set(qrcmocs)
file(GLOB_RECURSE headers *.h)
file(GLOB_RECURSE cpps *.cpp)
file(GLOB_RECURSE uis *.ui)
file(GLOB_RECURSE qrcs *.rc)
set(sources ${headers} ${cpps})
source_group_by_dir(sources)

doQtClassMoc(headers qthmocs)
doQtUiMoc(uis qtuimocs)
addQtResources(qrcs qrcmocs)
#QT4_WRAP_UI(qtuimocs ${uis})


compileWithQt()

#Here we instruct to build sample executable from all the source files
ADD_EXECUTABLE(${MYPROJECTNAME} ${sources} ${qthmocs} ${qtuimocs} ${qrcmocs})

#last thing that we need to do is to tell CMake what libraries our executable needs
#Luckily FIND_PACKAGE prepared QT_LIBRARIES variable for us
#TARGET_LINK_LIBRARIES(HelloWorld ${QT_LIBRARIES})
linkWithQt(${MYPROJECTNAME})

#message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
#copyDirectory(${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_SOURCE_DIR}/build/resources)
