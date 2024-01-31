#ifndef SCENE
#define SCENE

#include "ui/core/graph_item.hpp"
#include <vector>

namespace UI {
class Scene {
  public:
    Scene();
    void draw();
    void addItem(GraphItem *);

  private:
    std::vector<GraphItem *> graph_items;
};
} // namespace UI

#endif // !SCENE
