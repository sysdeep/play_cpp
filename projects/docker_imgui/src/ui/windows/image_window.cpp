#include <chrono>
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

    fetcher = new AsyncFetcher<docker::ImageModel>([=]()
                                                   {
                                                       //
                                                       return this->docker_client->images->get(id);
                                                       //
                                                   },
                                                   std::chrono::milliseconds(0));

    // start
    fetcher->start();
};

void ImageWindow::draw()
{

    auto payload = fetcher->tick();

    auto title = ICON_IMAGE " Image" + id;
    ImGui::Begin(title.c_str(), &is_running);

    ImGui::Text("Id: %s", payload.Id.c_str());

    ImGui::Separator();
    draw_details(payload);
    ImGui::Separator();
    draw_config(payload);

    ImGui::Spacing();

    if (ImGui::Button("Refresh"))
    {
        fetcher->start();
    }

    ImGui::End();

    if (!is_running)
    {
        window_handler->do_close(this->id);
    }
};

void ImageWindow::draw_details(docker::ImageModel &payload)
{
    ImGui::BeginGroup();
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Details");
    ImGui::PopFont();

    ImGui::Spacing();

    if (ImGui::BeginTable("containers_table", 2))
    {
        // ID
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("ID");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Id.c_str());

        // Names
        bool name_key = false;
        for (auto const &name : payload.RepoTags)
        {
            ImGui::TableNextRow();
            if (!name_key)
            {

                ImGui::TableSetColumnIndex(0);
                ImGui::TextUnformatted("Repo Tags");
                name_key = true;
            }
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%s", name.c_str());
        }
        // ImGui::TableNextRow();
        // ImGui::TableSetColumnIndex(0);
        // ImGui::TextUnformatted("Name");
        // ImGui::TableSetColumnIndex(1);
        // ImGui::Text("%s", model.Name.c_str());

        ImGui::EndTable();
    }

    ImGui::EndGroup();
}

void ImageWindow::draw_config(docker::ImageModel &payload)
{
    ImGui::BeginGroup();
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "Config");
    ImGui::PopFont();

    ImGui::Spacing();

    if (ImGui::BeginTable("containers_table", 2))
    {
        // Cmd
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Cmd");
        ImGui::TableSetColumnIndex(1);
        for (auto const &cmd_part : payload.Config.Cmd)
        {
            ImGui::Text("%s", cmd_part.c_str());
        }

        // Cmd
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Entrypoint");
        ImGui::TableSetColumnIndex(1);
        for (auto const &e_part : payload.Config.Entrypoint)
        {
            ImGui::Text("%s", e_part.c_str());
        }

        ImGui::EndTable();
    }

    ImGui::EndGroup();
}