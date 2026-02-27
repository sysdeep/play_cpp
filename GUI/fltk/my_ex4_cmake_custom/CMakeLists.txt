cmake_minimum_required(VERSION 3.10)

# set( CMAKE_VERBOSE_MAKEFILE on )


project(app CXX)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


# ----------------------------------------------------------------------
# Добавляем FLTK как поддиректорию
# ----------------------------------------------------------------------
add_subdirectory(external/fltk)   # <-- внутри fltk уже есть свой CMake

# После выполнения add_subdirectory создаётся цель `fltk` (и соответствующие
# компоненты, такие как `fltk_images`, `fltk_gl`).

  
set(SOURCES 
    src/main.cpp
    src/gui/mnemo/mnemo.cpp
    src/gui/views/lamp/lamp.cpp
    )
 
# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})


# ----------------------------------------------------------------------
# Подключаем заголовки и библиотеки FLTK
# ----------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE 
    fltk 
    # fltk_images 
    # fltk_gl
)

# Если в fltk.cmake объявлены свойства include‑директорий,
# они автоматически подтянутся к вашей цели. Для явного контроля:
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIRS})
