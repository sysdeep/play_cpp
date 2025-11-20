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
    bool get_light_state();
    void toggle();
    void set_visible(bool);
    bool visible();

  private:
    bool is_visible;
    bool is_active = false;
};

} // namespace UI
#endif // !DEBUG
