#ifndef DSENSOR_VIEW
#define DSENSOR_VIEW

#include "./dsensor_vm.hpp"
#include "ui/core/draw_context.hpp"
#include "ui/core/scene_node.hpp"

namespace UI {

class DSensorView : public SceneNode, public DSensorVM {
  public:
    DSensorView();

    void set_light_state(bool) override;
    bool get_light_state();
    void toggle();
    void set_visible(bool);
    bool visible();

  private:
    bool is_visible;
    bool is_active = false;

  protected:
    void drawEvent(DrawContext *) override;
};

} // namespace UI
#endif // !DEBUG
