#include <stdio.h>
#include "imgui.h"
#include "images_page.hpp"

ImagesPage::ImagesPage()
{

    table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
    //  | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    // table_flags |= ImGuiTableFlags_ContextMenuInBody;
};

void ImagesPage::draw()
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

        for (int row = 0; row < 5; row++)
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
};