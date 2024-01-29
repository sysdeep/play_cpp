#include "./dsensor_view.h"
#include "imgui.h"
#include <iostream>
// #include <stdlib>

DSensorView::DSensorView(DSensorVM *model) {
  this->model = model;
  this->is_visible = true;
}

void DSensorView::draw() {
  std::cout << "draw" << std::endl;

  if (!this->is_visible)
    return;

  ImGui::Begin("DSensor Window",
               &this->is_visible); // Pass a pointer to our bool variable (the
                                   // window will have a closing button that
                                   // will clear the bool when clicked)
  ImGui::Text("Hello from DSensor window!");

  // TODO: не выводится
  ImDrawList *draw_list = ImGui::GetWindowDrawList();

  int x = 30;
  int y = 40;
  int sz = 16;
  static ImVec4 colf = ImVec4(1.0f, 0.8f, 0.4f, 1.0f);
  const ImU32 col = ImColor(colf);
  int circle_segments = 10;

  draw_list->AddCircleFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz * 0.5f,
                             col, circle_segments);

  draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + 1, y + 1), col);
  x += sz; // Pixel (faster than AddLine)
  // x += sz + spacing;  // Circle
  int spacing = 3;
  ImGui::Dummy(ImVec2((sz + spacing) * 11.2f, (sz + spacing) * 3.0f));
  // ImGui::PopItemWidth();
  if (ImGui::Button("Close Me")) {

    this->is_visible = false;
  }

  std::cout << is_visible << std::endl;

  ImGui::End();
}
