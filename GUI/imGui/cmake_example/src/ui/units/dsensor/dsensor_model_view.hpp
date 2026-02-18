#pragma once

#include "application/app_models/dsensor_model.hpp"
#include "ui/core/ani_timer.hpp"
#include "ui/core/draw_context.hpp"
#include "ui/core/scene_node.hpp"

namespace UI {

/*
новая реализация основанная напрямую из данных от модели
*/
class DSensorModelView : public SceneNode {
  public:
    DSensorModelView(DSensorModel *model, SceneNode *parent = nullptr);

    void set_visible(bool);
    bool visible();

  private:
    DSensorModel *model;

    bool is_visible = true;
    ImVec4 get_color();
    void drawEvent(DrawContext *) override;

    AniTimer *timer;
    bool timerST = false;
};

} // namespace UI
