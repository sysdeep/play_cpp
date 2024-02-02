#ifndef DSENSOR_VM
#define DSENSOR_VM
namespace UI {

class DSensorVM {
  public:
    virtual void set_light_state(bool) = 0;
    // bool state;
    // bool visible;
};
} // namespace UI
#endif
