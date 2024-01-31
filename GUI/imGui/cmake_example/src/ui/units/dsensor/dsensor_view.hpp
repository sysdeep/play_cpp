#ifndef DSENSOR_VIEW
#define DSENSOR_VIEW

#include "./dsensor_vm.hpp"
#include "ui/core/graph_item.hpp"

namespace UI {

class DSensorView : public GraphItem {
  public:
    DSensorView(DSensorVM *model);
    void draw(ImDrawList *) override;

  private:
    DSensorVM *model;
    bool is_visible;
};

} // namespace UI
#endif // !DEBUG
