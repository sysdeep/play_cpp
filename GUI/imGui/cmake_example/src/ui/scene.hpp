#ifndef SCENE
#define SCENE

#include "application/application_ctx.hpp"
#include "logic/models/dsensor.hpp"
#include "ui/core/graph_item.hpp"
#include "ui/demo/demo_modal/demo_modal.hpp"
#include "ui/units/dsensor/dsensor_proto.hpp"
#include <vector>

namespace UI {
class Scene {
  public:
    Scene(ApplicationCtx *ctx);
    void draw();
    void addItem(GraphItem *);

  private:
    ApplicationCtx *ctx;
    std::vector<GraphItem *> graph_items;

    DSensorProto *dsensor_proto;
    LOGIC::DSensor *dsensor_model;
    DemoModal *demo_modal;
    bool use_demo_modal;
};
} // namespace UI

#endif // !SCENE
