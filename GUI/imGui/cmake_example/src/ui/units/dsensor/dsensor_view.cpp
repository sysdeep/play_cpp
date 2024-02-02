#include "./dsensor_view.hpp"
#include "imgui.h"

using namespace UI;

DSensorView::DSensorView() {
    // this->model = model;
    this->is_visible = true;
}

void DSensorView::set_light_state(bool st) { is_visible = st; }

void DSensorView::draw(ImDrawList *draw_list) {
    if (!is_visible)
        return;

    static float sz = 36.0f;
    static float thickness = 3.0f;
    static int ngon_sides = 6;
    static bool circle_segments_override = false;
    static int circle_segments_override_v = 12;
    static bool curve_segments_override = false;
    static int curve_segments_override_v = 8;

    ImVec4 colf = ImVec4(0.6f, 1.0f, 0.4f, 1.0f);

    // ImVec4 colf = ImGui::ColorConvertU32ToFloat4(0x33445599);

    const ImVec2 p = ImGui::GetCursorScreenPos();
    const ImU32 col = ImColor(colf);
    const float spacing = 10.0f;
    const ImDrawFlags corners_tl_br = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight;
    const float rounding = sz / 5.0f;
    const int circle_segments = circle_segments_override ? circle_segments_override_v : 0;
    const int curve_segments = curve_segments_override ? curve_segments_override_v : 0;
    float x = p.x + 4.0f;
    float ix = x; // initial x
    float y = p.y + 4.0f;
    float iy = y; // initial y
                  //
    draw_list->AddNgonFilled(ImVec2(ix + 40.0f, iy + 40.0f), sz * 0.5f, col, 9);
    draw_list->AddNgonFilled(ImVec2(ix + 45.0f, iy + 45.0f), sz * 0.5f,
                             ImColor(ImGui::ColorConvertU32ToFloat4(0x934499ff)), 9);
}
