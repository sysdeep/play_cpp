#pragma once
#include "../main_supply_view/main_supply_view.hpp"
#include "application/app_models/section_model.hpp"

namespace UI {

/*
новая реализация основанная напрямую из данных от модели
*/
class SectionView {
  public:
    SectionView(SectionModel *model);
    void draw();

    // void set_visible(bool);
    // bool visible();

  private:
    SectionModel *model;

    // components
    MainSupplyView *main_supply;

    // bool is_visible = true;
    // ImVec4 get_color();
};

} // namespace UI
