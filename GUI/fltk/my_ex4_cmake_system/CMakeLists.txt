cmake_minimum_required(VERSION 3.10)

project(app CXX)
# set( CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(FLTK REQUIRED CONFIG COMPONENTS fltk fltk_images fltk_gl)

if (FLTK_FOUND)
    message(STATUS "FLTK include dirs : ${FLTK_INCLUDE_DIRS}")
    message(STATUS "FLTK libraries    : ${FLTK_LIBRARIES}")
else()
    message(FATAL_ERROR "FLTK not found!")
endif()
  
set(SOURCES 
    src/main.cpp
    src/gui/mnemo/mnemo.cpp
    src/gui/views/lamp/lamp.cpp
    )
 
# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${FLTK_LIBRARIES})
