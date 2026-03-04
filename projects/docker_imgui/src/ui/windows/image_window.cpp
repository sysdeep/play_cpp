#include "imgui.h"
#include "image_window.hpp"

using namespace ui;

ImageWindow::ImageWindow(std::string id) : id(id) {};

void ImageWindow::draw()
{
    auto title = "Image" + id;
    ImGui::Begin(title.c_str());
    ImGui::End();
};