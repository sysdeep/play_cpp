#include <iostream>
#include "imgui.h"
#include "container_window.hpp"
#include "ui/icons/icons.hpp"

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

    auto title = ICON_CONTAINER " Container: " + payload.Name;
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
    ImGui::Spacing();
    drawConfig(payload);
    ImGui::Spacing();
    drawNetworks(payload);
    ImGui::Spacing();
    drawVolumes(payload);

    ImGui::Spacing();

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

    ImGui::Button(ICON_START " Start");
    ImGui::SameLine();
    ImGui::Button(ICON_STOP " Stop");
    ImGui::SameLine();
    ImGui::Button(ICON_KILL " Kill");
    ImGui::SameLine();
    ImGui::Button(ICON_RESTART " Restart");
    ImGui::SameLine();
    ImGui::Button(ICON_PAUSE " Pause");
    ImGui::SameLine();
    ImGui::Button(ICON_RESUME " Resume");
    ImGui::SameLine();
    ImGui::Button(ICON_REMOVE " Remove");

    ImGui::EndGroup();
};

void ContainerWindow::drawConfig(const docker::ContainerModel &model)
{

    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Config");
    ImGui::PopFont();

    ImGui::Spacing();

    if (ImGui::BeginTable("config_table", 2))
    {
        // Image
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Image");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", model.Config.Image.c_str());

        // Entrypoint
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Entrypoint");
        ImGui::TableSetColumnIndex(1);
        for (const auto &e : model.Config.Entrypoint)
        {
            ImGui::Text("%s", e.c_str());
        }

        // Cmd
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Cmd");
        ImGui::TableSetColumnIndex(1);
        for (const auto &e : model.Config.Cmd)
        {
            ImGui::Text("%s", e.c_str());
        }

        // Env
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Env");
        ImGui::TableSetColumnIndex(1);
        for (const auto &env : model.Config.Env)
        {
            ImGui::Text("%s", env.c_str());
        }

        ImGui::EndTable();
    }
};

void ContainerWindow::drawNetworks(const docker::ContainerModel &model)
{
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Networks");
    ImGui::PopFont();

    // TODO: persistent constants
    ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    ImGuiTableColumnFlags column_name_flags = ImGuiTableColumnFlags_DefaultSort |
                                              ImGuiTableColumnFlags_WidthStretch;

    if (ImGui::BeginTable("networks_table", 4, table_flags))
    {

        {
            ImGui::TableSetupColumn("Network", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("IP Address", column_name_flags, 0.8f);
            ImGui::TableSetupColumn("Gateway", column_name_flags, 0.8f);
            ImGui::TableSetupColumn("MAC", column_name_flags, 1.0f);
            ImGui::TableHeadersRow();
        }

        int col = 0;
        for (const auto &network : model.NetworkSettings.Networks)
        {

            ImGui::TableNextRow();

            // Key
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", network.Key.c_str());

            // IPAddress
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", network.IPAddress.c_str());

            // Gateway
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", network.Gateway.c_str());

            // Mac
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", network.MacAddress.c_str());
        }

        ImGui::EndTable();
    }
};

void ContainerWindow::drawVolumes(const docker::ContainerModel &model)
{
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Mounts");
    ImGui::PopFont();

    ImGui::Spacing();

    // TODO: persistent constants
    ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    ImGuiTableColumnFlags column_name_flags = ImGuiTableColumnFlags_DefaultSort |
                                              ImGuiTableColumnFlags_WidthStretch;

    if (ImGui::BeginTable("mounts_table", 3, table_flags))
    {

        {
            ImGui::TableSetupColumn("Type", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Name", column_name_flags, 0.9f);
            ImGui::TableSetupColumn("Path", column_name_flags, 1.0f);
            ImGui::TableHeadersRow();
        }

        int col = 0;
        for (const auto &volume : model.MountVolumes)
        {

            ImGui::TableNextRow();

            // Type
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", volume.Type.c_str());

            // Name
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", volume.Name.c_str());

            // Path
            ImGui::TableSetColumnIndex(col++);
            ImGui::Text("%s", volume.Destination.c_str());
        }

        ImGui::EndTable();
    }
};

docker::ContainerModel ContainerWindow::fetch()
{
    auto container = this->docker_client->containers->get(id);
    std::cout << "got container: " << container.Id << std::endl;

    return container;
}