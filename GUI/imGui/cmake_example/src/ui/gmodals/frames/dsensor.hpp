#ifndef DSENSOR_GFRAME
#define DSENSOR_GFRAME

#include "./base_frame.hpp"

namespace UI {
namespace GMODALS {

class DSensor : public BaseFrame {
  public:
    DSensor();
    void draw() override;

  private:
    bool is_disabled = false;
};
} // namespace GMODALS
} // namespace UI
#endif // !DSENSOR_GFRAME
