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

    history_fetcher = new AsyncFetcher<std::vector<docker::ImageHistoryModel>>([=]()
                                                                               {
                                                                                   //
                                                                                   return this->docker_client->images->get_history(id);
                                                                                   //
                                                                               },
                                                                               std::chrono::milliseconds(0));

    // start
    fetcher->start();
    history_fetcher->start();
};

void ImageWindow::draw()
{

    auto payload = fetcher->tick();
    auto payload_history = history_fetcher->tick();

    std::string image_title{};
    if (payload.RepoTags.size() > 0)
    {
        image_title = payload.RepoTags[0]; // tag name
    }
    else
    {
        image_title = payload.Id.substr(0, 12); // short id
    }

    auto title = ICON_IMAGE " Image: " + image_title;
    ImGui::Begin(title.c_str(), &is_running);

    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
    if (ImGui::BeginTabBar("ImageWindowTabBar", tab_bar_flags))
    {
        if (ImGui::BeginTabItem("Details"))
        {
            // const ImGuiID child_id = ImGui::GetID((void *)(intptr_t)pp);
            const ImGuiID child_id = 1;
            ImGuiChildFlags flags =
                ImGuiChildFlags_AlwaysUseWindowPadding;
            ImGui::BeginChild(child_id, ImVec2(0, 0), flags);
            ImGui::BeginGroup();
            draw_details(payload);
            ImGui::Separator();
            draw_config(payload);
            ImGui::EndGroup();
            ImGui::EndChild();

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("History"))
        {
            const ImGuiID child_id = 2;
            ImGuiChildFlags flags =
                ImGuiChildFlags_AlwaysUseWindowPadding;
            ImGui::BeginChild(child_id, ImVec2(0, 0), flags);
            draw_history(payload_history);
            ImGui::EndChild();

            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::Separator();

    ImGui::Spacing();

    if (ImGui::Button("Refresh"))
    {
        fetcher->start();
    }

    // Check if the window is focused and the Escape key is pressed
    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) && ImGui::IsKeyPressed(ImGuiKey_Escape))
    {
        is_running = false; // Set the visibility state to false to close the window
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

    // ImGuiTableFlags flags = ImGuiTableFlags_RowBg;
    if (ImGui::BeginTable("containers_table", 2))
    {
        ImGui::TableSetupColumn("key", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("value", ImGuiTableColumnFlags_WidthStretch);
        // no draw headers
        // ImGui::TableHeadersRow();

        // ID
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("ID");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Id.c_str());

        // Created
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Created");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Created.c_str());

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

        // Size
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Size");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%lu", payload.Size);

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

        // Entrypoint
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Entrypoint");
        ImGui::TableSetColumnIndex(1);
        for (auto const &e_part : payload.Config.Entrypoint)
        {
            ImGui::Text("%s", e_part.c_str());
        }

        // Env
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("Env");
        ImGui::TableSetColumnIndex(1);
        for (auto const &e_part : payload.Config.Env)
        {
            ImGui::Text("%s", e_part.c_str());
        }

        // StopSignal
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("StopSignal");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Config.StopSignal.c_str());

        // User
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("User");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Config.User.c_str());

        // WorkingDir
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::TextUnformatted("WorkingDir");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%s", payload.Config.WorkingDir.c_str());

        ImGui::EndTable();
    }

    ImGui::EndGroup();
}

void ImageWindow::draw_history(const std::vector<docker::ImageHistoryModel> &payload)
{

    ImGui::BeginGroup();
    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.8f);
    ImGui::Text("%s", "History");
    ImGui::PopFont();

    ImGui::Spacing();

    if (ImGui::BeginTable("history_table", 1))
    {
        for (const auto &item : payload)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", item.CreatedBy.c_str());
        }

        ImGui::EndTable();
    }

    ImGui::Text("History: %zu", payload.size());

    ImGui::EndGroup();
}