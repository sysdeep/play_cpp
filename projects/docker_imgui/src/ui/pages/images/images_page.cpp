#include <stdio.h>
#include <iostream>
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
#include "images_page.hpp"
#include "ui/icons/fa4.hpp"
#include "ui/utils/humanize.hpp"

ImagesPage::ImagesPage(UIState *state, docker::DockerClient *docker_client) : state(state), docker_client{docker_client}
{

    table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    //  | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    // table_flags |= ImGuiTableFlags_ContextMenuInBody;

    // update data interval
    update_timeout = std::chrono::seconds(2); // ms

    // new async update
    last_update = std::chrono::system_clock::now();

    // TODO: !!! нужен потокобезопасный клиент
    // start
    this->start_update_task();
    // auto info = this->docker_client->system->info();
    // std::cout << info.ServerVersion << std::endl;
};

void ImagesPage::draw()
{

    if (!state->images_window)
    {
        return;
    }

    // TODO: сделать систему определения что окно появилось -> обновить содержимое
    this->process_update();
    this->process_draw();
};

void ImagesPage::process_update()
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
                    std::cout << "future status - ready, update images and erase" << std::endl;
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
    std::cout << "start update images async" << std::endl;
    auto task_future = std::async(std::launch::async, [this]()
                                  {
                                      //   auto info = this->docker_client->system->info();
                                      //   std::cout << info.ServerVersion << std::endl;
                                      auto images = this->docker_client->images->get_all();
                                      std::cout << "got images: " << images.size() << std::endl;

                                      //   std::this_thread::sleep_for(std::chrono::milliseconds(8000)); // Имитация долгой работы
                                      //   return 42;
                                      return images;
                                      //
                                  });
    futures.push_back(std::move(task_future));
}

void ImagesPage::process_draw()
{

    // enum ContentsType
    // {
    //     CT_Text,
    //     CT_FillButton
    // };
    // int contents_type = CT_FillButton;

    ImGui::Begin(ICON_FA_ODNOKLASSNIKI " "
                                       "Images");
    // ImGui::Begin("Another Window",
    //          &show_another_window); // Pass a pointer to our bool variable (the
    //                                 // window will have a closing button that will
    //                                 // clear the bool when clicked)

    int images_count = this->images.size();
    ImGui::Text("total: %d", images_count);
    ImGui::Text("futures: %ld", this->futures.size());

    // filter ---------------------------------------------
    ImGui::PushItemWidth(250.f);
    ImGui::InputText("filter", &this->filterStr);
    ImGui::SameLine();
    if (ImGui::Button("Clear"))
    {
        this->filterStr.clear();
    }

    // ImGui::InputText("filter id", &this->filterStr);
    // ImGui::SameLine();
    // if (ImGui::Button("Clear"))
    // {
    //     this->filterStr.clear();
    // }

    ImGui::PopItemWidth();

    // commands -------------------------------------------
    if (ImGui::Button(ICON_FA_REFRESH " Обновить"))
    {
        this->start_update_task();
    }

    // table ----------------------------------------------
    // 3 - columns count
    if (ImGui::BeginTable("table1", 5, table_flags))
    {

        // ImGui::TableSetupColumn(0, );
        // std::cout << "flags: " << column_name_flags << std::endl;
        // Display headers
        {
            ImGui::TableSetupColumn("Name", column_name_flags, 1.0f);
            // ImGui::TableSetupColumn("Name");
            ImGui::TableSetupColumn("Id", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Containers", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Size", column_name_flags, 0.5f);
            ImGui::TableSetupColumn("Created", column_name_flags, 0.5f);
            ImGui::TableHeadersRow();
        }

        // std::cout << "rows to draw: " << images_count << std::endl;
        for (int row = 0; row < images_count; ++row)
        {

            // dublicate names
            auto names = this->images[row].RepoTags;
            if (names.size() == 0)
            {
                names.push_back(std::string("---"));
            }

            for (const auto name : names)
            {

                // filter
                if (this->filterStr.size() > 0)
                {
                    if (name.find(this->filterStr) == std::string::npos)
                    {
                        continue;
                    }
                }

                // std::cout << "row: " << row << std::endl;
                ImGui::TableNextRow();

                // Name
                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", name.c_str());

                // ID
                // auto Style = ImGui::GetStyle();
                ImGui::PushFont(state->fontMono, 18.f);
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", ui::Humanize::formatImageID(this->images[row].Id).c_str());
                ImGui::PopFont();

                // containers
                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%lu", this->images[row].Containers);

                // size
                ImGui::TableSetColumnIndex(3);
                // ImGui::Text("%lu", this->images[row].Size);
                ImGui::PushFont(state->fontMono, 18.f);
                ImGui::Text("%s", ui::Humanize::toSize(this->images[row].Size).c_str());
                ImGui::PopFont();

                // created
                ImGui::TableSetColumnIndex(4);
                ImGui::Text("%lu", this->images[row].Created);
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

    ImGui::End();
}