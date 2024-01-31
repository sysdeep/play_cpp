#ifndef DSENSOR_VIEW
#define DSENSOR_VIEW

#include "./dsensor_vm.hpp"

namespace UI {

class DSensorViewEx {
  public:
    DSensorViewEx(DSensorVM *model);
    void draw();

  private:
    DSensorVM *model;
    bool is_visible;
};

} // namespace UI
#endif // !DEBUG
