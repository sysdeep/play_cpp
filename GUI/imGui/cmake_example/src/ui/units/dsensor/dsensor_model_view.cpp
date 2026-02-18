#include "./dsensor_model_view.hpp"
#include "imgui.h"
#include <iostream>
using namespace UI;

DSensorModelView::DSensorModelView(DSensorModel *model, SceneNode *parent) : SceneNode{parent}, model(model) {
    // this->model = model;
    // this->is_visible = true;
    setRect(12.f, 12.f);

    timer = new AniTimer(1000, [this]() {
        //
        // timerST = !timerST;

        //
    });
}

void DSensorModelView::drawEvent(DrawContext *ctx) {
    if (!is_visible)
        return;

    timer->update(ctx);

    // static float sz = 24.0f;

    auto colf = this->get_color();

    const ImVec2 cp = ImGui::GetCursorScreenPos();
    auto pp = parent_pos();
    // std::cout << "pp " << pp.x << " " << pp.y << std::endl;
    auto cpp = Helper::VecAdd(cp, pp);
    // std::cout << "cpp " << cpp.x << " " << cpp.y << std::endl;
    auto p0 = Helper::VecAdd(cpp, _local_pos);
    // std::cout << "p0 " << p0.x << " " << p0.y << std::endl;
    const ImU32 col = ImColor(colf);
    // const float spacing = 10.0f;
    // const ImDrawFlags corners_tl_br = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight;
    // const float rounding = sz / 5.0f;
    // const int circle_segments = circle_segments_override ? circle_segments_override_v : 0;
    // const int curve_segments = curve_segments_override ? curve_segments_override_v : 0;
    // float x = p.x + 80.0f;
    // float ix = x; // initial x
    // // float ix = 0; // initial x
    // float y = p.y + 80.0f;
    // float iy = y; // initial y
    // float iy = 0; // initial y

    // static ImVec2 scrolling(0.0f, 0.0f);

    // Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use
    // IsItemHovered()/IsItemActive()
    // ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();    // ImDrawList API uses screen coordinates!
    // ImVec2 canvas_sz = ImGui::GetContentRegionAvail(); // Resize canvas to what's available
    // if (canvas_sz.x < 50.0f)
    //     canvas_sz.x = 50.0f;
    // if (canvas_sz.y < 50.0f)
    //     canvas_sz.y = 50.0f;
    // ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

    // Draw border and background color
    // ImGuiIO &io = ImGui::GetIO();
    // ImDrawList *draw_list = ImGui::GetWindowDrawList();
    // draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
    // draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

    auto draw_list = ImGui::GetWindowDrawList();

    // circle
    auto circle_segments = 0;
    draw_list->AddCircleFilled(p0, _rect.x / 2, col, circle_segments);

    // This will catch our interactions
    ImGui::InvisibleButton("canvas#dsensor", _rect,
                           ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
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
    ImGui::SetItemTooltip("I am a tooltip");
}

void DSensorModelView::set_visible(bool st) { is_visible = st; };

bool DSensorModelView::visible() { return is_visible; };

ImVec4 DSensorModelView::get_color() {
    // ImVec4 colf = ImGui::ColorConvertU32ToFloat4(0x33445599);

    if (timerST) {
        return ImVec4(0.9f, 0.1f, 0.1f, 0.4f);
    }

    if (this->model->is_blocked) {
        return ImVec4(0.9f, 1.0f, 0.4f, 0.1f);
    }

    if (this->model->is_error) {
        return ImVec4(0.9f, 0.4f, 0.4f, 0.4f);
    }

    if (this->model->logic > 0) {
        return ImVec4(0.6f, 1.0f, 0.4f, 1.0f);
    }

    // normal off
    return ImVec4(0.9f, 1.0f, 0.4f, 1.0f);
};