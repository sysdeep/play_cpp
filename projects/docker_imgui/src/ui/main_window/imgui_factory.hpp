#pragma once
#include <GLFW/glfw3.h>

class ImGuiFactory
{
public:
    ImGuiFactory();

    GLFWwindow *init();
    void shutdown(GLFWwindow *window);
};