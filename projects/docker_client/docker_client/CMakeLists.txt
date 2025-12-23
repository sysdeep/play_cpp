cmake_minimum_required(VERSION 3.14)
project(docker_client)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

set(APP_TARGET app)

# NOTE: for
# including(https://stackoverflow.com/questions/61206703/is-there-includepath-option-in-clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp
    src/client/client.cpp
    src/client/containers.cpp
    src/client/images.cpp
  
    src/client/models/docker_version.cpp
    src/client/session/session.cpp
    src/client/session/params_builder.cpp



    # 3th
    src/ddd/docker.cpp
)

# add_library(backend STATIC ${BACKEND_SOURCES})

# add_library(imgui STATIC ${IMGUI_SOURCES})

include_directories(${PROJECT_SOURCE_DIR})
# include_directories(vendors/imgui)

add_executable(${APP_TARGET} ${SOURCES})
# target_link_libraries(${APP_TARGET} imgui backend)

# можно и так... add_executable(${APP_TARGET} ${SOURCES} ${IMGUI_SOURCES}
# ${BACKEND_SOURCES})
target_include_directories(${APP_TARGET} PRIVATE src)
target_include_directories(${APP_TARGET} PRIVATE vendors/nlohmann/single_include) 

# target_include_directories(${APP_TARGET} PRIVATE vendors/imgui) # Include the
#                                                                 # IMGUI headers
# target_include_directories(${APP_TARGET} PRIVATE vendors/imgui/backends
# )# Include the IMGUI headers

# NOT WORKING
# https://github.com/twanas/spdlog-cmake/blob/master/CMakeLists.txt
# add_subdirectory(vendors/spdlog)
# find_package(spdlog)

# find_package(spdlog REQUIRED)
find_package(RapidJSON REQUIRED)

# Link your executable to the found include directories
target_include_directories(app PRIVATE ${RAPIDJSON_INCLUDE_DIRS})


# Find the CURL package
find_package(CURL REQUIRED)


target_link_libraries(
  app
  # ${APP_TARGET}
  # glfw
  # ${OPENGL_LIBRARIES}
  # ${GLEW_LIBRARIES}
  # ${EXTRA_LIBS}
  PRIVATE CURL::libcurl
  # RapidJSON
  # for error undefined reference to symbol 'dlclose@@GLIBC_2.2.5'
  ${CMAKE_DL_LIBS}
  
  # spdlog::spdlog
  )
