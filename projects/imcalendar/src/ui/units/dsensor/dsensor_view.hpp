#ifndef DSENSOR_VIEW
#define DSENSOR_VIEW

#include "./dsensor_vm.hpp"
#include "ui/core/graph_item.hpp"

namespace UI {

class DSensorView : public GraphItem, public DSensorVM {
  public:
    DSensorView();
    void draw(ImDrawList *) override;
    void set_light_state(bool) override;

  private:
    bool is_visible;
};

} // namespace UI
#endif // !DEBUG
