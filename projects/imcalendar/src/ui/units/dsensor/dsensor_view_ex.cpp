#include "./dsensor_view_ex.hpp"
#include "imgui.h"
#include <iostream>
// #include <stdlib>

using namespace UI;

DSensorViewEx::DSensorViewEx(DSensorVM *model) {
    this->model = model;
    this->is_visible = true;
}

void DSensorViewEx::draw() {
    // std::cout << "draw" << std::endl;

    if (!this->is_visible)
        return;

    // Handle all undocked floating windows
    // ImGuiViewport *viewport = ImGui::GetMainViewport();
    // ImGui::SetNextWindowPos(viewport->WorkPos);
    // ImGui::SetNextWindowSize(ImHexApi::System::getMainWindowSize() - ImVec2(0,
    // ImGui::GetTextLineHeightWithSpacing())); ImGui::SetNextWindowViewport(viewport->ID);
    // ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0F);
    // ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0F);
    // ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    // const ImGuiViewport *viewport = ImGui::GetMainViewport();
    // ImGui::SetNextWindowPos(viewport->Pos);
    // ImGui::SetNextWindowSize(viewport->Size);
    // ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
    //                                ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize
    //                                | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBringToFrontOnFocus |
    //                                ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
    //
    // // Render main dock space
    // if (ImGui::Begin("ImHexDockSpace", nullptr, windowFlags)) {
    //     // ImGui::PopStyleVar();
    //     ImDrawList *draw_list_g = ImGui::GetWindowDrawList();
    //
    //     static float sz = 36.0f;
    //     static float thickness = 3.0f;
    //     static int ngon_sides = 6;
    //     static bool circle_segments_override = false;
    //     static int circle_segments_override_v = 12;
    //     static bool curve_segments_override = false;
    //     static int curve_segments_override_v = 8;
    //     static ImVec4 colf = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);
    //
    //     const ImVec2 p = ImGui::GetCursorScreenPos();
    //     const ImU32 col = ImColor(colf);
    //     const float spacing = 10.0f;
    //     const ImDrawFlags corners_tl_br = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomRight;
    //     const float rounding = sz / 5.0f;
    //     const int circle_segments = circle_segments_override ? circle_segments_override_v : 0;
    //     const int curve_segments = curve_segments_override ? curve_segments_override_v : 0;
    //     float x = p.x + 4.0f;
    //     float ix = x; // initial x
    //     float y = p.y + 4.0f;
    //     float iy = y; // initial y
    //                   //
    //     draw_list_g->AddNgonFilled(ImVec2(ix + 20.0f, iy + 20.0f), sz * 0.5f, col, 9);
    //
    //     ImGui::End();
    // }

    ImGui::Begin("DSensor Window",
                 &this->is_visible); // Pass a pointer to our bool variable (the
                                     // window will have a closing button that
                                     // will clear the bool when clicked)
    ImGui::Text("Hello from DSensor window!");

    if (ImGui::BeginTabBar("##TabBar")) {

        if (ImGui::BeginTabItem("Primitives")) {

            ImGui::PushItemWidth(-ImGui::GetFontSize() * 15);
            ImDrawList *draw_list = ImGui::GetWindowDrawList();

            ImGui::Text("Примитивы!");

            static float sz = 36.0f;
            static float thickness = 3.0f;
            static int ngon_sides = 6;
            static bool circle_segments_override = false;
            static int circle_segments_override_v = 12;
            static bool curve_segments_override = false;
            static int curve_segments_override_v = 8;
            static ImVec4 colf = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);

            // ImGui::DragFloat("Size", &sz, 0.2f, 2.0f, 100.0f, "%.0f");
            // ImGui::DragFloat("Thickness", &thickness, 0.05f, 1.0f, 8.0f, "%.02f");
            // ImGui::SliderInt("N-gon sides", &ngon_sides, 3, 12);
            // ImGui::Checkbox("##circlesegmentoverride", &circle_segments_override);
            // ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
            // circle_segments_override |=
            // ImGui::SliderInt("Circle segments override", &circle_segments_override_v, 3, 40);
            // ImGui::Checkbox("##curvessegmentoverride", &curve_segments_override);
            // ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
            // curve_segments_override |= ImGui::SliderInt("Curves segments override", &curve_segments_override_v, 3,
            // 40); ImGui::ColorEdit4("Color", &colf.x);

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
            for (int n = 0; n < 2; n++) {
                // First line uses a thickness of 1.0f, second line uses the
                // configurable thickness
                float th = (n == 0) ? 1.0f : thickness;
                draw_list->AddNgon(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, ngon_sides, th);
                x += sz + spacing; // N-gon
                draw_list->AddCircle(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, circle_segments, th);
                x += sz + spacing; // Circle
                draw_list->AddEllipse(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, sz * 0.3f, col, -0.3f,
                                      circle_segments, th);
                x += sz + spacing; // Ellipse
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 0.0f, ImDrawFlags_None, th);
                x += sz + spacing; // Square
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, rounding, ImDrawFlags_None, th);
                x += sz + spacing; // Square with all rounded corners
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, rounding, corners_tl_br, th);
                x += sz + spacing; // Square with two rounded corners
                draw_list->AddTriangle(ImVec2(x + sz * 0.5f, y), ImVec2(x + sz, y + sz - 0.5f),
                                       ImVec2(x, y + sz - 0.5f), col, th);
                x += sz + spacing; // Triangle
                // draw_list->AddTriangle(ImVec2(x+sz*0.2f,y), ImVec2(x,
                // y+sz-0.5f), ImVec2(x+sz*0.4f, y+sz-0.5f), col, th);x+=
                // sz*0.4f + spacing; // Thin triangle
                draw_list->AddLine(ImVec2(x, y), ImVec2(x + sz, y), col, th);
                x += sz + spacing; // Horizontal line (note: drawing a filled
                                   // rectangle will be faster!)
                draw_list->AddLine(ImVec2(x, y), ImVec2(x, y + sz), col, th);
                x += spacing; // Vertical line (note: drawing a filled rectangle
                              // will be faster!)
                draw_list->AddLine(ImVec2(x, y), ImVec2(x + sz, y + sz), col, th);
                x += sz + spacing; // Diagonal line

                // Quadratic Bezier Curve (3 control points)
                ImVec2 cp3[3] = {ImVec2(x, y + sz * 0.6f), ImVec2(x + sz * 0.5f, y - sz * 0.4f),
                                 ImVec2(x + sz, y + sz)};
                draw_list->AddBezierQuadratic(cp3[0], cp3[1], cp3[2], col, th, curve_segments);
                x += sz + spacing;

                // Cubic Bezier Curve (4 control points)
                ImVec2 cp4[4] = {ImVec2(x, y), ImVec2(x + sz * 1.3f, y + sz * 0.3f),
                                 ImVec2(x + sz - sz * 1.3f, y + sz - sz * 0.3f), ImVec2(x + sz, y + sz)};
                draw_list->AddBezierCubic(cp4[0], cp4[1], cp4[2], cp4[3], col, th, curve_segments);

                x = p.x + 4;
                y += sz + spacing;
            }
            draw_list->AddNgonFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, ngon_sides);
            x += sz + spacing; // N-gon
            draw_list->AddCircleFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, circle_segments);
            x += sz + spacing; // Circle
            draw_list->AddEllipseFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, sz * 0.3f, col, -0.3f,
                                        circle_segments);
            x += sz + spacing; // Ellipse
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col);
            x += sz + spacing; // Square
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f);
            x += sz + spacing; // Square with all rounded corners
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f, corners_tl_br);
            x += sz + spacing; // Square with two rounded corners
            draw_list->AddTriangleFilled(ImVec2(x + sz * 0.5f, y), ImVec2(x + sz, y + sz - 0.5f),
                                         ImVec2(x, y + sz - 0.5f), col);
            x += sz + spacing; // Triangle
            // draw_list->AddTriangleFilled(ImVec2(x+sz*0.2f,y), ImVec2(x,
            // y+sz-0.5f), ImVec2(x+sz*0.4f, y+sz-0.5f), col); x += sz*0.4f +
            // spacing; // Thin triangle
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + thickness), col);
            x += sz + spacing; // Horizontal line (faster than AddLine, but only
                               // handle integer thickness)
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + thickness, y + sz), col);
            x += spacing * 2.0f; // Vertical line (faster than AddLine, but only
                                 // handle integer thickness)
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + 1, y + 1), col);
            x += sz; // Pixel (faster than AddLine)
            draw_list->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + sz, y + sz), IM_COL32(0, 0, 0, 255),
                                               IM_COL32(255, 0, 0, 255), IM_COL32(255, 255, 0, 255),
                                               IM_COL32(0, 255, 0, 255));

            y += 40;
            // std::cout << "-----------------" << std::endl;
            // std::cout << "y: " << y << std::endl;   // 554
            // std::cout << "x: " << x << std::endl;   // 484
            // std::cout << "sz: " << sz << std::endl; // 36
            draw_list->AddNgonFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f, col, ngon_sides);

            /* интересно, он появляется по абсолютным координатам и не привязан к окну */
            /* понятно, x является относительным этого окна, при перерисовки он меняется */
            draw_list->AddNgonFilled(ImVec2(510.0f, 510.0f), sz * 0.5f, col, 4);

            /* позиция относительно окна */
            draw_list->AddNgonFilled(ImVec2(ix + 20.0f, iy + 20.0f), sz * 0.5f, col, 5);

            ImGui::PopItemWidth();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    int spacing = 3;
    int sz = 16;
    ImGui::Dummy(ImVec2((sz + spacing) * 11.2f, (sz + spacing) * 3.0f));
    // ImGui::PopItemWidth();
    if (ImGui::Button("Close Me")) {

        this->is_visible = false;
    }

    // std::cout << is_visible << std::endl;

    ImGui::End();
}
