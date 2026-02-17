cmake_minimum_required(VERSION 3.12)
project(app CXX)

# Set C++ standard (SFML 3 requires C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If using Windows and static libraries, define SFML_STATIC
# set(SFML_STATIC_LIBRARIES TRUE)
# target_compile_definitions(MySFMLProject PRIVATE SFML_STATIC)

# Find SFML package
# You may need to set CMAKE_PREFIX_PATH to <sfml-install-path> if find_package fails
# set(CMAKE_PREFIX_PATH "C:/SDKs/SFML") 
find_package(SFML REQUIRED COMPONENTS graphics window system audio network)
# find_package(SFML REQUIRED components graphics window system)
# find_package(SFML COMPONENTS graphics window system REQUIRED)

# Add your executable target
add_executable(app 
    src/main.cpp
    src/ui/core/update_ctx.hpp src/ui/core/update_ctx.cpp
    src/ui/core/ani_timer.hpp src/ui/core/ani_timer.cpp
    src/views/lamp_view.hpp src/views/lamp_view.cpp

    src/ui/scene_node/scene_node.hpp src/ui/scene_node/scene_node.cpp
    src/ui/views/lamp.hpp src/ui/views/lamp.cpp
    src/ui/views/main_supply.hpp src/ui/views/main_supply.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}src)

# Link SFML libraries to your target
# target_link_libraries(MyApp PRIVATE SFML::graphics SFML::window SFML::system SFML::audio SFML::network)
# target_link_libraries(MyApp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# target_compile_features(MyApp PRIVATE cxx_std_17)
# target_link_libraries(MyApp PRIVATE SFML::Graphics)

set(IMGUI_SOURCES
    vendors/imgui/imgui.cpp vendors/imgui/imgui_demo.cpp
    vendors/imgui/imgui_draw.cpp vendors/imgui/imgui_widgets.cpp
    vendors/imgui/imgui_tables.cpp)

# set(BACKEND_SOURCES vendors/imgui/backends/imgui_impl_glfw.cpp
                    # vendors/imgui/backends/imgui_impl_opengl3.cpp)

# add_library(backend STATIC ${BACKEND_SOURCES})

add_library(imgui STATIC ${IMGUI_SOURCES})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(vendors/imgui)



include_directories(vendors/imgui-sfml)
# add_library(imgui STATIC ${IMGUI_SOURCES})
add_library(ImGui-SFML STATIC
  vendors/imgui-sfml/imgui-SFML.cpp vendors/imgui-sfml/imgui-SFML.h
  
)

# можно и так... add_executable(${APP_TARGET} ${SOURCES} ${IMGUI_SOURCES}
# ${BACKEND_SOURCES})
# target_include_directories(${APP_TARGET} PRIVATE src)
# target_include_directories(${APP_TARGET} PRIVATE vendors/imgui) # Include the
                                                                # IMGUI headers
# target_include_directories(${APP_TARGET} PRIVATE vendors/imgui/backends
# )# Include the IMGUI headers

# glfw
# find_package(glfw3 REQUIRED)
# include_directories(${GLFW_INCLUDE_DIRS})
# link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})


# find_package(ImGui-SFML REQUIRED)
# target_link_libraries(my_target PRIVATE ImGui-SFML::ImGui-SFML)


if(SFML_FOUND)
    target_link_libraries(app PRIVATE 
    sfml-graphics sfml-window sfml-system 
    imgui 
    # backend 
    # glfw 
    # GL
    OpenGL::GL
    ImGui-SFML)
endif()