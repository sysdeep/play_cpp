#QtCreatorLinuxExample


imgui version - 1.83
backend - glwf - opengl3

поместить исходники библиотек в libs

- backends
- gl3w
- glfw
- imgui


в pro файле добавить пути

```
INCLUDEPATH += $$PWD/libs/imgui
INCLUDEPATH += $$PWD/libs/backends
INCLUDEPATH += $$PWD/libs/glfw/include
INCLUDEPATH += $$PWD/libs/gl3w
```

добавить опции системных библиотек

```
LIBS += -lGL `pkg-config --static --libs glfw3`

unix: CONFIG += link_pkgconfig
```

в самой среде добавить все C файлы в проект

```
SOURCES += \
        libs/backends/imgui_impl_glfw.cpp \
        libs/backends/imgui_impl_opengl3.cpp \
        libs/gl3w/GL/gl3w.c \
        libs/imgui/imgui.cpp \
        libs/imgui/imgui_demo.cpp \
        libs/imgui/imgui_draw.cpp \
        libs/imgui/imgui_tables.cpp \
        libs/imgui/imgui_widgets.cpp \
        src/main.cpp
```
