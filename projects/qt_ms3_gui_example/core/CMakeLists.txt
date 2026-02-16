cmake_minimum_required(VERSION 3.16)

project(core LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(core STATIC
  core.cpp
  core.h
  lib/service_locator.hpp
  bootstrap/bootstrap.cpp
  services/glog/glog.cpp services/glog/glog.hpp services/glog/iglog.hpp
  services/user/user.cpp services/user/user.hpp services/user/iuser.hpp
  widgets/speciallabel.h widgets/speciallabel.cpp
  gui/views/sensor_view.h gui/views/sensor_view.cpp
  gui/views/vibrator_view.h gui/views/vibrator_view.cpp
  widgets/date_time_widget.hpp widgets/date_time_widget.cpp
  nui/units/dsensor/dsensor_unit.hpp nui/units/dsensor/dsensor_unit.cpp 
  nui/units/dsensor/dsensor_interface.hpp 
  nui/units/dsensor/dsensor_ctrl.hpp
  nui/units/dsensor/dsensor_ctrl.cpp
)

target_link_libraries(core PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(core PRIVATE Qt5::Widgets)
target_link_libraries(core PRIVATE Qt5::Core)

target_compile_definitions(core PRIVATE CORE_LIBRARY)

target_include_directories(core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>
)
