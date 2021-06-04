TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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



INCLUDEPATH += $$PWD/libs/imgui
INCLUDEPATH += $$PWD/libs/backends
INCLUDEPATH += $$PWD/libs/glfw/include
INCLUDEPATH += $$PWD/libs/gl3w




LIBS += -lGL `pkg-config --static --libs glfw3`

unix: CONFIG += link_pkgconfig
#unix: PKGCONFIG += sqlite3
