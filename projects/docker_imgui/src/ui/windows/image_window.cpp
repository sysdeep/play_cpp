#include "imgui.h"
#include "image_window.hpp"

using namespace ui;

ImageWindow::ImageWindow(std::string id) : id(id)
{
    std::cout << "image window created" << std::endl;
};

void ImageWindow::draw()
{
    auto title = "Image" + id;
    ImGui::Begin(title.c_str());
    ImGui::End();
};