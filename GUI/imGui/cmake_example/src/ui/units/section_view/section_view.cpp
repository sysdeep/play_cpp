#include "./section_view.hpp"
#include "imgui.h"

using namespace UI;

SectionView::SectionView(SectionModel *model) {
    //
    main_supply = new MainSupplyView(model->main_supply);
};

void SectionView::draw() {
    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    float width = 400.0f;
    float height = 200.0f;

    // const ImVec2 p = ImGui::GetCursorScreenPos();
    auto colf = ImVec4(0.9f, 1.0f, 0.4f, 0.1f);
    const ImU32 col = ImColor(colf);

    ImVec2 canvas_p0 = ImGui::GetCursorScreenPos(); // ImDrawList API uses screen coordinates!
    ImVec2 canvas_p1 = ImVec2(canvas_p0.x + width, canvas_p0.y + height);
    ImVec2 rect = ImVec2(width, height);

    draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
    draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

    // This will catch our interactions
    ImGui::InvisibleButton("section_view", rect, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
    const bool is_hovered = ImGui::IsItemHovered(); // Hovered
    const bool is_active = ImGui::IsItemActive();   // Held

    ImGui::SetItemTooltip("Section");

    // ImVec2 org_pos = ImGui::GetCursorScreenPos();
    ImVec2 org_pos = ImGui::GetCursorPos();
    // при передачи позиции внутрь, она потом замещает глобальные координаты
    auto main_supply_pos = ImVec2(canvas_p0.x + 20, canvas_p0.y + 20);
    // auto main_supply_pos = ImVec2(40, 20);
    // ImGui::SetCursorPos(main_supply_pos);
    main_supply->draw(main_supply_pos);
    // ImGui::SetCursorPos(org_pos);
}