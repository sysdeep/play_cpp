#include "imgui.h"
#include "containers_table.hpp"
#include "ui/utils/humanize.hpp"

using namespace ui;
ContainersTable::ContainersTable(ContainersTableHandler *handler) : handler(handler) {}

void ContainersTable::draw(std::vector<docker::ContainerListModel> &containers)
{
    int containers_count = containers.size();

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
            auto names = containers[row].Names;
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
                    // std::cout << "do open: " << name << std::endl;
                    this->handler->on_container_toggled(containers[row].Id);
                }
                ImGui::PopID();
                ImGui::SameLine();
                ImGui::Text("%s", name.c_str());

                // ID
                // auto Style = ImGui::GetStyle();
                // ImGui::PushFont(state->fontMono, 18.f);
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", ui::Humanize::formatImageID(containers[row].Id).c_str());
                // ImGui::PopFont();

                // state
                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", containers[row].State.c_str());

                // satus
                ImGui::TableSetColumnIndex(3);
                ImGui::Text("%s", containers[row].Status.c_str());

                // image
                ImGui::TableSetColumnIndex(4);
                ImGui::Text("%s", containers[row].Image.c_str());

                // // size
                // ImGui::TableSetColumnIndex(3);
                // // ImGui::Text("%lu", this->images[row].Size);
                // ImGui::PushFont(state->fontMono, 18.f);
                // ImGui::Text("%s", ui::Humanize::toSize(this->images[row].Size).c_str());
                // ImGui::PopFont();

                // created
                ImGui::TableSetColumnIndex(5);
                ImGui::Text("%lu", containers[row].Created);
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