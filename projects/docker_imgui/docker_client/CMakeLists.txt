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
  sections/images.cpp
  sections/containers.cpp
  sections/system.cpp
  models/system_info.cpp
  models/container_list_model.hpp
  models/image_list_model.hpp
  parser/parser_utils.cpp
  parser/containers_list_parser.cpp
  parser/container_parser.cpp
  parser/images_list_parser.cpp
  parser/image_parser.cpp
)


# target_compile_definitions(${APP_TARGET} PRIVATE CORE_LIBRARY)

# target_include_directories(${APP_TARGET} PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#     $<INSTALL_INTERFACE:>
# )
