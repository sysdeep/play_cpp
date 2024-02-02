#ifndef SCENE
#define SCENE

#include "logic/models/dsensor.hpp"
#include "ui/core/graph_item.hpp"
#include "ui/units/dsensor/dsensor_proto.hpp"
#include <vector>

namespace UI {
class Scene {
  public:
    Scene();
    void draw();
    void addItem(GraphItem *);

  private:
    std::vector<GraphItem *> graph_items;

    DSensorProto *dsensor_proto;
    LOGIC::DSensor *dsensor_model;
};
} // namespace UI

#endif // !SCENE
