#pragma once
#include "../main_supply_view/main_supply_view.hpp"
#include "application/app_models/section_model.hpp"
#include "ui/core/draw_context.hpp"
#include "ui/core/scene_node.hpp"
namespace UI {

/*
новая реализация основанная напрямую из данных от модели
*/
class SectionView : public SceneNode {
  public:
    SectionView(SectionModel *model, SceneNode *parent = nullptr);

    // void set_visible(bool);
    // bool visible();

  private:
    SectionModel *model;

    // components
    MainSupplyView *main_supply;

    // bool is_visible = true;
    // ImVec4 get_color();

  protected:
    void drawEvent(DrawContext *ctx) override;
};

} // namespace UI
