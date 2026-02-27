# Cmake example

В данном примере реализован 2 вариант с подключением fltk как подпроекта.

- склонировать данный проект
- распаковать в external исходники fltk чтобы получилось `external/fltk`
- создать каталог сборки `mkdir build && cd build`
- зпустить `cmake ..`
- запустить сборку `make`

## Руководство от AI

### 1️⃣ Вариант — find_package

#### 1. Сборка и «инсталляция» FLTK в отдельный каталог

```bash
# Предположим, у вас есть каталог с исходниками FLTK:
cd /path/to/your/project
mkdir -p external/fltk_build
cd external/fltk_build

# Сборка (можно указать любую папку‑префикс, куда будут «установлены» файлы)
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=$(pwd)/install \
      -DFLTK_BUILD_EXAMPLES=OFF \
      -DFLTK_BUILD_TEST=OFF \
      ../../fltk   # <-- путь к исходникам FLTK

cmake --build . --target install   # получаем <install>/include, <install>/lib
```

После этого у вас будет структура, например:

```
external/fltk_build/
├─ install/
│  ├─ include/
│  │  └─ FL/            ← заголовки FLTK
│  └─ lib/
│     ├─ libfltk.so
│     ├─ libfltk_images.so
│     └─ … (другие библиотеки)
```

#### 2. CMakeLists.txt вашего проекта

```cmake

cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

# ----------------------------------------------------------------------
# 1️⃣ Указываем путь, где находится установленный FLTK
# ----------------------------------------------------------------------
# Вариант A – добавить в CMAKE_PREFIX_PATH (подходит, если FLTK установлен в <prefix>/)
list(APPEND CMAKE_PREFIX_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/external/fltk_build/install"
)

# Вариант B – явно задать директорию, где находится файл FLTKConfig.cmake
# set(FLTK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/fltk_build/install/lib/cmake/FLTK")

# ----------------------------------------------------------------------
# 2️⃣ Находим FLTK
# ----------------------------------------------------------------------
find_package(FLTK REQUIRED COMPONENTS fltk fltk_images fltk_gl)   # нужные компоненты

if (FLTK_FOUND)
    message(STATUS "FLTK include dirs : ${FLTK_INCLUDE_DIRS}")
    message(STATUS "FLTK libraries    : ${FLTK_LIBRARIES}")
else()
    message(FATAL_ERROR "FLTK not found!")
endif()

# ----------------------------------------------------------------------
# 3️⃣ Ваш исполняемый файл
# ----------------------------------------------------------------------
add_executable(my_app
    src/main.cpp               # ваш код
    src/MyWindow.cpp
    # …
)

# ----------------------------------------------------------------------
# 4️⃣ Подключаем заголовки и библиотеки FLTK
# ----------------------------------------------------------------------
target_include_directories(my_app PRIVATE ${FLTK_INCLUDE_DIRS})
target_link_libraries(my_app PRIVATE ${FLTK_LIBRARIES})

# Если нужны дополнительные объявления (например, отключить некоторые предупреждения)
target_compile_definitions(my_app PRIVATE ${FLTK_DEFINITIONS})

# ----------------------------------------------------------------------
# 5️⃣ Платформенно‑специфические настройки (необязательно)
# ----------------------------------------------------------------------
if (WIN32)
    # На Windows зачастую требуется добавить .dll в папку запуска
    add_custom_command(TARGET my_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${FLTK_LIBRARY_DIR}/fltk.dll"
            $<TARGET_FILE_DIR:my_app>)
endif()
```

#### Что здесь происходит

1 - **CMAKE_PREFIX_PATH** — добавляем путь к «установочному» каталогу FLTK, чтобы `find_package` мог найти `FLTKConfig.cmake`.
2 - **find_package(FLTK REQUIRED COMPONENTS …)** ищет нужные модули (fltk, fltk_images, fltk_gl). Если не найдёт – сборка останавливается.
3 - Переменные **FLTK_INCLUDE_DIRS**, **FLTK_LIBRARIES**, **FLTK_DEFINITIONS** автоматически заполняются. Их добавляем в target_include_directories, target_link_libraries и target_compile_definitions.
4 - На Windows копируем динамические библиотеки рядом с exe (опционально).

### 2️⃣ Вариант — add_subdirectory (подключаем исходники FLTK как субпроект)

Если вы храните исходники FLTK в подпапке вашего репозитория (например, external/fltk), то можно собрать их вместе с вашим проектом:

Дерево проекта

```
MyProject/
├─ CMakeLists.txt          ← главный CMake
├─ src/
│  ├─ main.cpp
│  └─ MyWindow.cpp
└─ external/
   └─ fltk/               ← исходники FLTK (клонирование из git)
```

#### Главный CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyApp LANGUAGES CXX)

# ----------------------------------------------------------------------
# 1️⃣ Добавляем FLTK как поддиректорию
# ----------------------------------------------------------------------
add_subdirectory(external/fltk)   # <-- внутри fltk уже есть свой CMake

# После выполнения add_subdirectory создаётся цель `fltk` (и соответствующие
# компоненты, такие как `fltk_images`, `fltk_gl`).

# ----------------------------------------------------------------------
# 2️⃣ Ваши цели
# ----------------------------------------------------------------------
add_executable(my_app
    src/main.cpp
    src/MyWindow.cpp
)

# ----------------------------------------------------------------------
# 3️⃣ Подключаем заголовки и библиотеки FLTK
# ----------------------------------------------------------------------
target_link_libraries(my_app PRIVATE fltk fltk_images fltk_gl)

# Если в fltk.cmake объявлены свойства include‑директорий,
# они автоматически подтянутся к вашей цели. Для явного контроля:
# target_include_directories(my_app PRIVATE ${FLTK_INCLUDE_DIRS})
```

**Важно**:

- В репозитории FLTK уже есть готовый CMakeLists.txt, который объявляет цель fltk.
- add_subdirectory заставит CMake собрать FLTK в том же билде, что и ваш код, что удобно для CI и упрощает переносимость.
