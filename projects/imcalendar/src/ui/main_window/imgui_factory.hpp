#pragma once
#include <GLFW/glfw3.h>

namespace UI
{
    class ImGuiFactory
    {
    public:
        ImGuiFactory();

        GLFWwindow *init();
        void shutdown(GLFWwindow *window);
    };
}