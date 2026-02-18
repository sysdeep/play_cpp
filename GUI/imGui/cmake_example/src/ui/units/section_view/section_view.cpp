#include "./section_view.hpp"
#include "imgui.h"

using namespace UI;

SectionView::SectionView(SectionModel *model, SceneNode *parent) : SceneNode{parent} {
    setRect(400.f, 200.f);
    //
    main_supply = new MainSupplyView(model->main_supply, this);
    main_supply->setPos(20, 20);
};

void SectionView::drawEvent(DrawContext *ctx) {
    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    auto cp = ImGui::GetCursorScreenPos();

    // const ImVec2 p = ImGui::GetCursorScreenPos();
    auto colf = ImVec4(0.9f, 1.0f, 0.4f, 0.1f);
    const ImU32 col = ImColor(colf);

    ImVec2 canvas_p0 =
        Helper::VecAdd(ImGui::GetCursorScreenPos(), _local_pos); // ImDrawList API uses screen coordinates!
    ImVec2 canvas_p1 = Helper::VecAdd(canvas_p0, _rect);

    draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
    draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

    // This will catch our interactions
    ImGui::InvisibleButton("section_view", _rect, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
    const bool is_hovered = ImGui::IsItemHovered(); // Hovered
    const bool is_active = ImGui::IsItemActive();   // Held

    ImGui::SetItemTooltip("Section");

    // main supply

    // ImVec2 org_pos = ImGui::GetCursorScreenPos();
    // ImVec2 org_pos = ImGui::GetCursorPos();
    // // при передачи позиции внутрь, она потом замещает глобальные координаты
    // auto main_supply_pos = Helper::VecAdd(canvas_p0, ImVec2{20, 20});
    // auto main_supply_pos = ImVec2(40, 20);
    // ImGui::SetCursorPos(main_supply_pos);

    ImGui::SetCursorScreenPos(cp);

    // main supply ----------------------------------------
    main_supply->draw(ctx);
}