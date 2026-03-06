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

    drawStatus(payload);
    /*
    Logs TODO
    Inspect TODO
    Stats TODO
    Console TODO
    Attach TODO
    */
    // TOP TODO
    drawDetails();
    drawNetworks();
    drawVolumes();

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

void ContainerWindow::drawStatus(const docker::ContainerModel &model)
{

    // auto &io = ImGui::GetIO();

    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Status");
    ImGui::PopFont();

    ImGui::Spacing();

    if (ImGui::BeginTable("containers_table", 2))
    {
        // ID
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("ID");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", model.Id.c_str());

        // Name
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Name");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", model.Name.c_str());

        // Status
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Status");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", model.State.Status.c_str());

        // IP
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("IP");
        // TODO

        // Created
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Created");
        // TODO

        // Started
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Started");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", model.State.StartedAt.c_str());

        // Restart Count
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Restart Count");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%lu", model.RestartCount);

        ImGui::EndTable();
    }

    /*
    ID	c6a1ced40204582965776da66c70c63da6db9cfd7b48df92862b9d99300002fa
    Name	blissful_chaplygin
    Ip address
    Status	 exited
    Created	2026-02-13 13:50:51
    Start time	2026-02-13 13:50:51
    RestartCount	0
    */

    /*
    Buttons
    */

    ImGui::BeginGroup();

    ImGui::Button("Start");
    ImGui::SameLine();
    ImGui::Button("Stop");
    ImGui::SameLine();
    ImGui::Button("Kill");
    ImGui::SameLine();
    ImGui::Button("Restart");
    ImGui::SameLine();
    ImGui::Button("Pause");
    ImGui::SameLine();
    ImGui::Button("Resume");
    ImGui::SameLine();
    ImGui::Button("Remove");

    ImGui::EndGroup();
};

void ContainerWindow::drawDetails()
{

    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Details");
    ImGui::PopFont();
};

void ContainerWindow::drawNetworks()
{
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Networks");
    ImGui::PopFont();
};

void ContainerWindow::drawVolumes()
{
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Volumes");
    ImGui::PopFont();
};

docker::ContainerModel ContainerWindow::fetch()
{
    auto container = this->docker_client->containers->get(id);
    std::cout << "got container: " << container.Id << std::endl;

    return container;
}