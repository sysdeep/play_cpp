#include <iostream>
#include "containers_frame.hpp"
#include "imgui.h"
#include "ui/icons/icons.hpp"
#include "ui/utils/humanize.hpp"

using namespace ui;

ContainersFrame::ContainersFrame(UIState *uiState, docker::DockerClient *docker_client) : uiState(uiState),
                                                                                          docker_client(docker_client)
{

    // new async update
    last_update = std::chrono::system_clock::now();

    // start
    this->start_update_task();
}

FrameMeta ContainersFrame::getMeta()
{
    return FrameMeta{ContainersFrame::title};
}

void ContainersFrame::draw()
{
    if (!uiState->containers_window)
        return;

    this->process_update();
    this->process_draw();
}

void ContainersFrame::process_draw()
{

    int containers_count = this->containers.size();

    ImGui::Text("total: %d", containers_count);
    ImGui::Text("futures: %ld", this->futures.size());

    // commands -------------------------------------------
    if (ImGui::Button(ICON_REFRESH " Обновить"))
    {
        this->start_update_task();
    }

    // table ----------------------------------------------
    // 3 - columns count
    if (ImGui::BeginTable("containers_table", 6, table_flags))
    {

        // ImGui::TableSetupColumn(0, );
        // std::cout << "flags: " << column_name_flags << std::endl;
        // Display headers
        {
            ImGui::TableSetupColumn("Name", column_name_flags, 1.0f);
            ImGui::TableSetupColumn("Id", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("State", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Status", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Image", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Created", column_name_flags, 0.5f);
            ImGui::TableHeadersRow();
        }

        // std::cout << "rows to draw: " << images_count << std::endl;
        for (int row = 0; row < containers_count; ++row)
        {

            // dublicate names
            auto names = this->containers[row].Names;
            if (names.size() == 0)
            {
                names.push_back(std::string("---"));
            }

            int ni = 1;
            for (const auto name : names)
            {

                // filter
                // if (this->filterStr.size() > 0)
                // {
                //     if (name.find(this->filterStr) == std::string::npos)
                //     {
                //         continue;
                //     }
                // }

                // std::cout << "row: " << row << std::endl;
                ImGui::TableNextRow();

                // Name
                ImGui::TableSetColumnIndex(0);
                ImGui::PushID((row * 3 + 3) * ni++);
                if (ImGui::SmallButton("..."))
                {
                    std::cout << "do open: " << name << std::endl;
                    this->uiState->show_container(this->containers[row].Id);
                }
                ImGui::PopID();
                ImGui::SameLine();
                ImGui::Text("%s", name.c_str());

                // ID
                // auto Style = ImGui::GetStyle();
                // ImGui::PushFont(state->fontMono, 18.f);
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", ui::Humanize::formatImageID(this->containers[row].Id).c_str());
                // ImGui::PopFont();

                // state
                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", this->containers[row].State.c_str());

                // satus
                ImGui::TableSetColumnIndex(3);
                ImGui::Text("%s", this->containers[row].Status.c_str());

                // image
                ImGui::TableSetColumnIndex(4);
                ImGui::Text("%s", this->containers[row].Image.c_str());

                // // size
                // ImGui::TableSetColumnIndex(3);
                // // ImGui::Text("%lu", this->images[row].Size);
                // ImGui::PushFont(state->fontMono, 18.f);
                // ImGui::Text("%s", ui::Humanize::toSize(this->images[row].Size).c_str());
                // ImGui::PopFont();

                // created
                ImGui::TableSetColumnIndex(5);
                ImGui::Text("%lu", this->containers[row].Created);
            }

            // for (int column = 0; column < 3; column++)
            // {
            //     ImGui::TableSetColumnIndex(column);
            //     ImGui::Text("Cell %d,%d", column, row);

            //     // char buf[32];
            //     // sprintf(buf, "Hello %d,%d", column, row);
            //     // ImGui::TextUnformatted(buf);

            //     // if (contents_type == CT_Text)
            //     //     ImGui::TextUnformatted(buf);
            //     // else if (contents_type == CT_FillButton)
            //     //     ImGui::Button(buf, ImVec2(-FLT_MIN, 0.0f));
            // }

            // ImGui::TableSetColumnIndex(3);
            // ImGui::PushID(row * 4 + 3);
            // ImGui::SmallButton("options");
            // if (ImGui::BeginPopupContextItem())
            // {
            //     ImGui::Text("This is the popup for Button(\"..\") in Cell %d,%d", 3, row);
            //     if (ImGui::Button("Close"))
            //         ImGui::CloseCurrentPopup();
            //     ImGui::EndPopup();
            // }
            // ImGui::PopID();
        }
        ImGui::EndTable();
    }
}

void ContainersFrame::process_update()
{
    // запуск фонового процесса
    // auto now = std::chrono::system_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_update);
    // if (elapsed > update_timeout)
    // {

    //     this->start_update_task();
    //     this->last_update = now;
    // }

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
                    std::cout << "future status - ready, update containers and erase" << std::endl;
                    this->containers = it->get();
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

void ContainersFrame::start_update_task()
{
    std::cout << "start update containers async" << std::endl;
    auto task_future = std::async(std::launch::async, [this]()
                                  {
                                      //   auto info = this->docker_client->system->info();
                                      //   std::cout << info.ServerVersion << std::endl;
                                      auto containers = this->docker_client->containers->get_all();
                                      std::cout << "got containers: " << containers.size() << std::endl;

                                      //   std::this_thread::sleep_for(std::chrono::milliseconds(8000)); // Имитация долгой работы
                                      //   return 42;
                                      return containers;
                                      //
                                  });
    futures.push_back(std::move(task_future));
}
