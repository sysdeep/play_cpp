cmake_minimum_required(VERSION 3.16)

project(docker_client LANGUAGES CXX)
set(APP_TARGET docker_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# find_package(Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt5 REQUIRED COMPONENTS Core)

include_directories(${PROJECT_SOURCE_DIR})




add_library(${APP_TARGET} STATIC
  docker_client.cpp
  session/session.cpp
  entites/images.cpp
  entites/containers.cpp
  entites/system.cpp
  models/system_info.cpp
)


# target_compile_definitions(${APP_TARGET} PRIVATE CORE_LIBRARY)

# target_include_directories(${APP_TARGET} PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#     $<INSTALL_INTERFACE:>
# )
