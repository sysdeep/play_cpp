#ifndef DSENSOR_VIEW
#include "./dsensor_vm.h"

class DSensorView {
public:
  DSensorView(DSensorVM *model);
  void draw();

private:
  DSensorVM *model;
  bool is_visible;
};

#endif // !DEBUG
