cmake_minimum_required(VERSION 3.16)
project(docker_imgui LANGUAGES CXX)


# NOTE: gcc 12 - only 17 standard
# Set the C++ standard to 17
set(CMAKE_CXX_STANDARD 17)
# Ensure the compiler is forced to use C++20, or configuration fails
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_VERBOSE_MAKEFILE 1)
# set(APP_VERSION_MAJOR 1)
# set(APP_VERSION_MINOR 0)

set(APP_TARGET app)

# NOTE: for
# including(https://stackoverflow.com/questions/61206703/is-there-includepath-option-in-clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp
    src/application/application.cpp
    src/ui/main_window/main_window.cpp
    src/ui/main_window/imgui_factory.cpp
    src/ui/main_window/main_menu.cpp
    src/ui/main_nav/main_nav.cpp
    src/ui/pages/images/images_page.cpp
    src/ui/pages/containers/containers_page.cpp
    src/ui/pages/about/about_page.cpp
    src/ui/pages/system_info/system_info_page.cpp
    src/ui/frames/images/images_frame.cpp
    src/ui/utils/humanize.cpp
    src/ui/content/content_frame.cpp
    src/ui/content/content_window.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/src/)


include_directories(vendors/imgui)
include_directories(vendors/imgui/backends)

# imgui backend
set(IMGUI_BACKEND_SOURCES 
    vendors/imgui/backends/imgui_impl_glfw.cpp
    vendors/imgui/backends/imgui_impl_opengl3.cpp)
add_library(imgui_backend STATIC ${IMGUI_BACKEND_SOURCES})

set(IMGUI_SOURCES
    vendors/imgui/imgui.cpp vendors/imgui/imgui_demo.cpp
    vendors/imgui/imgui_draw.cpp vendors/imgui/imgui_widgets.cpp
    vendors/imgui/imgui_tables.cpp
    vendors/imgui/misc/cpp/imgui_stdlib.cpp
    )

add_library(imgui STATIC ${IMGUI_SOURCES})

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})


# Find the CURL package
find_package(CURL REQUIRED)

find_package(RapidJSON CONFIG REQUIRED)
# include_directories(${RAPIDJSON_INCLUDE_DIRS})


add_subdirectory(docker_client)
include_directories(${PROJECT_SOURCE_DIR}/docker_client/)

add_executable(${APP_TARGET} ${SOURCES})

target_link_libraries(${APP_TARGET} PRIVATE
    imgui 
    imgui_backend
    docker_client

    glfw
  ${OPENGL_LIBRARIES}
    #   ${EXTRA_LIBS}

    CURL::libcurl
    
    # RapidJSON::rapidjson
    # rapidjson

  # for error undefined reference to symbol 'dlclose@@GLIBC_2.2.5'
  ${CMAKE_DL_LIBS}
)



