#include "imgui.h"
#include "container_window.hpp"

using namespace ui;

ContainerWindow::ContainerWindow(std::string id) : id(id) {};

void ContainerWindow::draw()
{
    auto title = "Container" + id;
    ImGui::Begin(title.c_str());
    ImGui::End();
};