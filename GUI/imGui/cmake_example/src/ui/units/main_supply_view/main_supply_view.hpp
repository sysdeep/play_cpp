#pragma once
#include "../dsensor/dsensor_model_view.hpp"
#include "application/app_models/main_supply_model.hpp"
#include "ui/views/main_supply/main_supply.hpp"

namespace UI {

/*
новая реализация основанная напрямую из данных от модели
*/
class MainSupplyView : public Views::MainSupply {
  public:
    // MainSupplyView(DSensorModel *model);
    MainSupplyView(MainSupplyModel *model, SceneNode *parent = nullptr);

    // void set_visible(bool);
    // bool visible();

  private:
    MainSupplyModel *model;

    DSensorModelView *sensor_enabled;
    DSensorModelView *sensor_blocked;

    // bool is_visible = true;
    // ImVec4 get_color();

  protected:
    void drawEvent(DrawContext *ctx) override;
};

} // namespace UI
