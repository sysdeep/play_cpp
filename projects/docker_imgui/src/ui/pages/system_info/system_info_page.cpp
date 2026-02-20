#include "system_info_page.hpp"
#include "imgui.h"
#include <iostream>
#include <future>

int calculateValue()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Имитация долгой работы
    return 42;
}

SystemInfoPage::SystemInfoPage(UIState *state, DockerClient *docker_client) : state{state}, docker_client{docker_client}
{
    //
    // system_info = docker_client->system->info();

    // new async update
    last_update = std::chrono::system_clock::now();
}

void SystemInfoPage::draw()
{
    if (!state->system_info_window)
        return;

    // обновление данных
    this->process_update();

    // рисование
    this->process_draw();
}

void SystemInfoPage::process_update()
{
    // запуск фонового процесса
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_update);
    if (elapsed.count() > 2000)
    {
        std::cout << "start update async" << std::endl;
        this->last_update = now;
        // update_result = std::async(std::launch::async, calculateValue);
        auto task_future = std::async(std::launch::async, [this]()
                                      {
                                          auto info = this->docker_client->system->info();

                                          //   std::this_thread::sleep_for(std::chrono::milliseconds(8000)); // Имитация долгой работы
                                          //   return 42;
                                          return info;
                                          //
                                      });
        futures.push_back(std::move(task_future));
    }

    // обработка футур
    if (!futures.empty())
    {

        for (auto it = futures.begin(); it != futures.end();)
        {

            if (it->valid())
            {
                auto future_status = it->wait_for(std::chrono::seconds(0));
                if (future_status == std::future_status::ready)
                {
                    // std::cout << "future status - ready, update system_info and erase" << std::endl;
                    this->system_info = it->get();
                    // remove element from vector
                    futures.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
    }
}

void SystemInfoPage::process_draw()
{
    ImGui::Begin("System info");
    // ImGui::Begin("Another Window",
    //          &show_another_window); // Pass a pointer to our bool variable (the
    //                                 // window will have a closing button that will
    //                                 // clear the bool when clicked)
    ImGui::Text("Docker ImGui example");

    ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

    if (ImGui::BeginTable("system_info_main_stats", 2, table_flags))
    {
        // Display headers
        {
            ImGui::TableSetupColumn("param");
            ImGui::TableSetupColumn("value");
            ImGui::TableHeadersRow();
        }

        // containers
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Containers");

        ImGui::TableSetColumnIndex(1);
        // ImGui::Text("%d", system_info.Containers);
        ImGui::Text("%d", system_info.Containers);

        // ContainersRunning
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersRunning");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", system_info.ContainersRunning);

        // ContainersPaused
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersPaused");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", system_info.ContainersPaused);

        // ContainersStopped
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersStopped");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", system_info.ContainersStopped);

        // Images
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Images");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", system_info.Images);
    }
    ImGui::EndTable();

    ImGui::End();
}