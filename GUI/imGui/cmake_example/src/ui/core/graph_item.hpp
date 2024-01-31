#ifndef GRAPH_ITEM
#define GRAPH_ITEM

#include "imgui.h"

namespace UI {

class GraphItem {
  public:
    virtual void draw(ImDrawList *) = 0;
};

} // namespace UI
#endif // !GRAPH_ITEM
#define GRAPH_ITEM
