#ifndef DSENSOR_VIEW
#define DSENSOR_VIEW

#include "./dsensor_vm.h"

namespace UI {

class DSensorView {
  public:
    DSensorView(DSensorVM *model);
    void draw();

  private:
    DSensorVM *model;
    bool is_visible;
};

} // namespace UI
#endif // !DEBUG
