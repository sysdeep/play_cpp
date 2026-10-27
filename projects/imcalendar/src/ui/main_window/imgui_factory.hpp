#pragma once
#include <GLFW/glfw3.h>

namespace UI
{
    class ImGuiFactory
    {
    public:
        ImGuiFactory();

        GLFWwindow *init(int width, int height, const char *title);
        void shutdown(GLFWwindow *window);
    };
}