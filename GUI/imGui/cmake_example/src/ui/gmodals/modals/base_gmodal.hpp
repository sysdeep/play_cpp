#ifndef BASE_GMODAL
#define BASE_GMODAL

#include "ui/gmodals/frames/base_frame.hpp"

namespace UI {
namespace GMODALS {

class BaseGmodal {
  public:
    BaseGmodal();
    void draw();

  protected:
    bool is_visible = true;
    BaseFrame *frame;
};
} // namespace GMODALS
} // namespace UI
#endif // !BASE_GMODAL
