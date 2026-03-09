#include "imgui.h"
#include "image_window.hpp"
#include "ui/icons/icons.hpp"

using namespace ui;

ImageWindow::ImageWindow(std::string id,
                         docker::DockerClient *docker_client,
                         WindowHandler *window_handler) : id(id),
                                                          docker_client(docker_client),
                                                          window_handler(window_handler),
                                                          is_running(true)
{
    std::cout << "image window created" << std::endl;
};

void ImageWindow::draw()
{
    auto title = ICON_IMAGE " Image" + id;
    ImGui::Begin(title.c_str(), &is_running);
    ImGui::End();

    if (!is_running)
    {
        window_handler->do_close(this->id);
    }
};