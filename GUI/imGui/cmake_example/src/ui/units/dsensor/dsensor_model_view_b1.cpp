#include "./dsensor_model_view.hpp"
#include "imgui.h"

using namespace UI;

DSensorModelView::DSensorModelView(DSensorModel *model) : model(model) {
    // this->model = model;
    // this->is_visible = true;
}

void DSensorModelView::draw(ImDrawList *draw_list) {
    if (!is_visible)
        return;

    static float sz = 24.0f;
    // static float thickness = 3.0f;
    // static int ngon_sides = 6;
    // static bool circle_segments_override = false;
    // static int circle_segments_override_v = 12;
    // static bool curve_segments_override = false;
    // static int curve_segments_override_v = 8;

    auto colf = this->get_color();

    const ImVec2 p = ImGui::GetCursorScreenPos();
    const ImU32 col = ImColor(colf);
    // const float spacing = 10.0f;
    // const ImDrawFlags corners_tl_br = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight;
    // const float rounding = sz / 5.0f;
    // const int circle_segments = circle_segments_override ? circle_segments_override_v : 0;
    // const int curve_segments = curve_segments_override ? curve_segments_override_v : 0;
    float x = p.x + 80.0f;
    float ix = x; // initial x
    // float ix = 0; // initial x
    float y = p.y + 80.0f;
    float iy = y; // initial y
    // float iy = 0; // initial y
    //
    // draw_list->AddNgonFilled(ImVec2(ix + 40.0f, iy + 40.0f), sz, col, 9);
    // draw_list->AddNgonFilled(ImVec2(ix + 40.0f, iy + 40.0f), sz, col, 9);

    // draw_list->AddCircleFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, circle_segments);
    // x += sz + spacing; // Circle
    // draw_list->AddEllipse(ImVec2(x + sz * 0.5f, y + sz * 0.5f), ImVec2(sz * 0.5f, sz * 0.3f), col, -0.3f,
    //                       circle_segments, th);
    // x += sz + spacing; // Ellipse

    // draw_list->AddNgonFilled(ImVec2(ix + 45.0f, iy + 45.0f), sz * 0.5f,
    //  ImColor(ImGui::ColorConvertU32ToFloat4(0x934499ff)), 9);

    static ImVec2 scrolling(0.0f, 0.0f);

    // Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use
    // IsItemHovered()/IsItemActive()
    ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();    // ImDrawList API uses screen coordinates!
    ImVec2 canvas_sz = ImGui::GetContentRegionAvail(); // Resize canvas to what's available
    if (canvas_sz.x < 50.0f)
        canvas_sz.x = 50.0f;
    if (canvas_sz.y < 50.0f)
        canvas_sz.y = 50.0f;
    ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

    // Draw border and background color
    ImGuiIO &io = ImGui::GetIO();
    // ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
    draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

    // circle
    auto circle_segments = 0;
    draw_list->AddCircleFilled(ImVec2(ix + 40.0f, iy + 40.0f), sz, col, circle_segments);

    // This will catch our interactions
    ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
    const bool is_hovered = ImGui::IsItemHovered();                            // Hovered
    const bool is_active = ImGui::IsItemActive();                              // Held
    const ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Lock scrolled origin
    const ImVec2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

    // Add first and second point
    if (is_hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
        // points.push_back(mouse_pos_in_canvas);
        // points.push_back(mouse_pos_in_canvas);
        // adding_line = true;
    }

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