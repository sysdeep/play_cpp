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

if(SFML_FOUND)
    target_link_libraries(app PRIVATE sfml-graphics sfml-window sfml-system)
endif()