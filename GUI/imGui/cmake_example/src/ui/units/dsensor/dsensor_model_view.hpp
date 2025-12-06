#pragma once

#include "application/app_models/dsensor_model.hpp"
#include "ui/core/graph_item.hpp"

namespace UI {

/*
новая реализация основанная напрямую из данных от модели
*/
class DSensorModelView : public GraphItem {
  public:
    DSensorModelView(DSensorModel *model);
    void draw(ImDrawList *) override;

    void set_visible(bool);
    bool visible();

  private:
    DSensorModel *model;

    bool is_visible = true;
    ImVec4 get_color();
};

} // namespace UI
