cmake_minimum_required(VERSION 3.14)
project(imgui-opengl-glfw-cmake-demo)

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
    src/application/application.cpp
    # LOGIC
    src/logic/core/attr.cpp
    src/logic/core/base_model.cpp
    src/logic/core/model_publisher.cpp
    src/logic/models/dsensor.cpp
    src/logic/project/project.cpp
    # UI
    src/ui/main_window.cpp
    src/ui/scene.cpp
    src/ui/main_menu.cpp
    src/ui/demo/demo_modal/demo_modal.cpp
    src/ui/gmodals/modals/base_gmodal.cpp
    src/ui/gmodals/modals/dsensor_gmodal.cpp
    src/ui/gmodals/frames/dsensor.cpp
    src/ui/units/dsensor/dsensor_demo.cpp
    src/ui/units/dsensor/dsensor_view.cpp
    src/ui/units/dsensor/dsensor_proto.cpp
    src/ui/units/dsensor/dsensor_view_ex.cpp)

set(IMGUI_SOURCES
    vendors/imgui/imgui.cpp vendors/imgui/imgui_demo.cpp
    vendors/imgui/imgui_draw.cpp vendors/imgui/imgui_widgets.cpp
    vendors/imgui/imgui_tables.cpp)

set(BACKEND_SOURCES vendors/imgui/backends/imgui_impl_glfw.cpp
                    vendors/imgui/backends/imgui_impl_opengl3.cpp)

add_library(backend STATIC ${BACKEND_SOURCES})

add_library(imgui STATIC ${IMGUI_SOURCES})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(vendors/imgui)

add_executable(${APP_TARGET} ${SOURCES})
target_link_libraries(${APP_TARGET} imgui backend)

# можно и так... add_executable(${APP_TARGET} ${SOURCES} ${IMGUI_SOURCES}
# ${BACKEND_SOURCES})
target_include_directories(${APP_TARGET} PRIVATE src)
target_include_directories(${APP_TARGET} PRIVATE vendors/imgui) # Include the
                                                                # IMGUI headers
target_include_directories(${APP_TARGET} PRIVATE vendors/imgui/backends
)# Include the IMGUI headers

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew find_package(GLEW REQUIRED) include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(
  ${APP_TARGET}
  glfw
  ${OPENGL_LIBRARIES}
  # ${GLEW_LIBRARIES}
  ${EXTRA_LIBS}
  # for error undefined reference to symbol 'dlclose@@GLIBC_2.2.5'
  ${CMAKE_DL_LIBS})
