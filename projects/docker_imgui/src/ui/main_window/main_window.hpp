#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include "imgui_factory.hpp"
#include "ui/pages/images/images_page.hpp"
#include "ui/pages/about/about_page.hpp"
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"
#include "main_menu.hpp"
#include "docker_client.hpp"

class MainWindow
{
public:
    MainWindow(DockerClient *docker_client);

    void start_loop();

private:
    GLFWwindow *window;
    ImGuiFactory *factory;

    void _setup_fonts();

    UIState *state;
    // components
    std::vector<DrawablePage *> pages;
    MainMenu *main_menu;
    // ImagesPage *images_page;
};