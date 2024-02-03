# ImGui cmake application template

Пример проекта с использованием cmake

Проект содержит часть архитектуры из ms3-GUI

## Install dev

```bash
libglfw3-dev
```

## Настройка среды

**iostream** - на com не видны стандартные либы, хотя на kasper всё хорошо

добавление этой строки перед запуском nvim решает проблему

```bash
export CPLUS_INCLUDE_PATH=/usr/include/c++/11:/usr/include/x86_64-linux-gnu/c++/11

```

## ImGui info

```cpp
// Dear ImGui: standalone example application for GLFW + OpenGL 3, using
// programmable pipeline (GLFW is a cross-platform general purpose library for
// handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation,
// etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/
// folder).
// - Introduction, links and more at the top of imgui.cpp


```

https://github.com/morizotter/imgui-opengl-glfw-glew-cmake-demo/tree/master
