#include <stdio.h>
#include "imgui.h"
#include "images_page.hpp"
#include <iostream>

ImagesPage::ImagesPage(UIState *state, DockerClient *docker_client) : state(state), docker_client{docker_client}
{

    table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    //  | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    // table_flags |= ImGuiTableFlags_ContextMenuInBody;

    // update data interval
    update_timeout = std::chrono::seconds(2); // ms

    // new async update
    last_update = std::chrono::system_clock::now();

    // TODO: !!! нижен потокобезопасный клиент
    // start
    // this->start_update_task();
    // auto info = this->docker_client->system->info();
    // std::cout << info.ServerVersion << std::endl;
};

void ImagesPage::draw()
{

    this->process_update();
    this->process_draw();
};

void ImagesPage::process_update()
{
    // запуск фонового процесса
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_update);
    if (elapsed > update_timeout)
    {

        // this->start_update_task();
        this->last_update = now;
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
                    this->images = it->get();
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

void ImagesPage::start_update_task()
{
    // std::cout << "start update async" << std::endl;
    auto task_future = std::async(std::launch::async, [this]()
                                  {
                                      auto info = this->docker_client->system->info();
                                      std::cout << info.ServerVersion << std::endl;
                                      //   auto images = this->docker_client->images->get_all();
                                      //   std::cout << images.size() << std::endl;

                                      //   std::this_thread::sleep_for(std::chrono::milliseconds(8000)); // Имитация долгой работы
                                      //   return 42;
                                      return images;
                                      //
                                  });
    // futures.push_back(std::move(task_future));
}

void ImagesPage::process_draw()
{

    // enum ContentsType
    // {
    //     CT_Text,
    //     CT_FillButton
    // };
    // int contents_type = CT_FillButton;

    ImGui::Begin("Images");
    // ImGui::Begin("Another Window",
    //          &show_another_window); // Pass a pointer to our bool variable (the
    //                                 // window will have a closing button that will
    //                                 // clear the bool when clicked)
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Hello from another window!");
    // if (ImGui::Button("Close Me"))
    //     show_another_window = false;

    // 3 - columns count
    if (ImGui::BeginTable("table1", 4, table_flags))
    {
        // Display headers
        {
            ImGui::TableSetupColumn("One");
            ImGui::TableSetupColumn("Two");
            ImGui::TableSetupColumn("Three");
            ImGui::TableHeadersRow();
        }

        for (int row = 0; this->images.size(); row++)
        {
            ImGui::TableNextRow();
            for (int column = 0; column < 3; column++)
            {
                ImGui::TableSetColumnIndex(column);
                ImGui::Text("Cell %d,%d", column, row);

                // char buf[32];
                // sprintf(buf, "Hello %d,%d", column, row);
                // ImGui::TextUnformatted(buf);

                // if (contents_type == CT_Text)
                //     ImGui::TextUnformatted(buf);
                // else if (contents_type == CT_FillButton)
                //     ImGui::Button(buf, ImVec2(-FLT_MIN, 0.0f));
            }

            ImGui::TableSetColumnIndex(3);
            ImGui::PushID(row * 4 + 3);
            ImGui::SmallButton("options");
            if (ImGui::BeginPopupContextItem())
            {
                ImGui::Text("This is the popup for Button(\"..\") in Cell %d,%d", 3, row);
                if (ImGui::Button("Close"))
                    ImGui::CloseCurrentPopup();
                ImGui::EndPopup();
            }
            ImGui::PopID();
        }
        ImGui::EndTable();
    }

    ImGui::End();
}