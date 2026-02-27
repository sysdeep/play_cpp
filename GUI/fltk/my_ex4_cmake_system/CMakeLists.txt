cmake_minimum_required(VERSION 3.10)

project(app CXX)
# set( CMAKE_VERBOSE_MAKEFILE on )
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(FLTK REQUIRED CONFIG)
  
set(SOURCES 
    src/main.cpp
    src/gui/mnemo/mnemo.cpp
    src/gui/views/lamp/lamp.cpp
    )
 
# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE fltk::fltk)

