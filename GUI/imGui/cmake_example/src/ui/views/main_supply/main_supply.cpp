

#include "./main_supply.hpp"
#include "ui/core/scene_node.hpp"
#include <iostream>

Views::MainSupply::MainSupply(SceneNode *parent) : SceneNode{parent} {
    //
    setRect(48.f, 64.f);
};

void Views::MainSupply::drawEvent(DrawContext *ctx) {

    // std::cout << "ms pos: x - " << _local_pos.x << " y - " << _local_pos.y << std::endl;

    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    // ImGui::SetCursorScreenPos(pos);
    auto current_pos = ImGui::GetCursorScreenPos();
    // ImGui::SetCursorScreenPos(ImVec2(current_pos.x + _pos.x, current_pos.y + _pos.y));

    // const ImVec2 p = ImGui::GetCursorScreenPos();
    auto colf = ImVec4(0.9f, 1.0f, 0.4f, 0.1f);
    const ImU32 col = ImColor(colf);

    // Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use
    // IsItemHovered()/IsItemActive()
    // ImVec2 canvas_p0 = ImGui::GetCursorScreenPos(); // ImDrawList API uses screen coordinates!
    // ImVec2 canvas_sz = ImGui::GetContentRegionAvail(); // Resize canvas to what's available
    // if (canvas_sz.x < 50.0f)
    //     canvas_sz.x = 50.0f;
    // if (canvas_sz.y < 50.0f)
    //     canvas_sz.y = 50.0f;

    auto p1 = Helper::VecAdd(current_pos, _local_pos);
    auto p2 = Helper::VecAdd(p1, _rect);
    ImGui::SetCursorScreenPos(p1);

    // brush
    draw_list->AddRectFilled(p1, p2, IM_COL32(163, 101, 62, 255), 3.0f);
    // pen
    // draw_list->AddRect(p1, p2, IM_COL32(255, 255, 255, 255), 3.0f);

    // This will catch our interactions
    ImGui::InvisibleButton("canvas", _rect, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
    // const bool is_hovered = ImGui::IsItemHovered(); // Hovered
    // const bool is_active = ImGui::IsItemActive();   // Held
    // const ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Lock scrolled origin
    // const ImVec2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

    // // Add first and second point
    // if (is_hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
    //     // points.push_back(mouse_pos_in_canvas);
    //     // points.push_back(mouse_pos_in_canvas);
    //     // adding_line = true;
    // }

    // try context menu - not working...
    // // 22
    // ImGui::OpenPopupOnItemClick("my popup", ImGuiPopupFlags_MouseButtonRight);

    // // 11
    // static float value = 0.5f;
    // if (ImGui::BeginPopupContextItem("my popup")) {
    //     if (ImGui::Selectable("Set to zero"))
    //         value = 0.0f;
    //     if (ImGui::Selectable("Set to PI"))
    //         value = 3.1415f;
    //     ImGui::SetNextItemWidth(-FLT_MIN);
    //     ImGui::DragFloat("##Value", &value, 0.1f, 0.0f, 0.0f);
    //     ImGui::EndPopup();
    // }

    // прикрепляется к вышестоящему виджету - кнопке
    ImGui::SetItemTooltip("Main supply");
}