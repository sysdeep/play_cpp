#include <iostream>
#include "imgui.h"
#include "container_window.hpp"

using namespace ui;

ContainerWindow::ContainerWindow(std::string id, docker::DockerClient *docker_client) : id(id),
                                                                                        docker_client(docker_client)
{

    fetcher = new AsyncFetcher<docker::ContainerModel>([=]()
                                                       {
                                                           //
                                                           return this->fetch();
                                                           //
                                                       },
                                                       std::chrono::milliseconds(0));

    // start
    fetcher->start();
};

void ContainerWindow::draw()
{

    auto payload = fetcher->tick();

    auto title = "Container" + id;
    ImGui::Begin(title.c_str());

    ImGui::Separator();
    ImGui::Text("model id: %s", payload.Id.c_str());
    ImGui::Text("Path id: %s", payload.Path.c_str());
    ImGui::Separator();

    if (ImGui::Button("Refresh"))
    {
        fetcher->start();
    }
    ImGui::End();
};

docker::ContainerModel ContainerWindow::fetch()
{
    auto container = this->docker_client->containers->get(id);
    std::cout << "got container: " << container.Id << std::endl;

    return container;
}