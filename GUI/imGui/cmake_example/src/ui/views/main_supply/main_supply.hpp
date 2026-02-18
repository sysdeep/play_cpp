#pragma once
#include "imgui.h"
#include "ui/core/draw_context.hpp"
#include "ui/core/scene_node.hpp"

namespace Views {

class MainSupply : public UI::SceneNode {
  public:
    MainSupply(SceneNode *parent = nullptr);

  private:
  protected:
    void drawEvent(DrawContext *ctx) override;
};
} // namespace Views