#ifndef GRAPH_ITEM
#define GRAPH_ITEM

#include "draw_context.hpp"
#include "imgui.h"
#include <vector>

namespace UI {

class SceneNode {
  public:
    SceneNode(SceneNode *parent = nullptr);
    // virtual void draw(ImDrawList *) = 0;
    void draw(DrawContext *ctx);

    void setPos(float x, float y);
    void setRect(float w, float h);
    ImVec2 pos() { return _local_pos; };
    ImVec2 parent_pos() { return parent != nullptr ? parent->pos() : ImVec2{0, 0}; };
    ImVec2 rect() { return _rect; };

    class Helper {
      public:
        static ImVec2 VecAdd(ImVec2 a, ImVec2 b) { return ImVec2{a.x + b.x, a.y + b.y}; };
    };

  protected:
    std::vector<SceneNode *> childrens;
    ImVec2 _local_pos;
    ImVec2 _rect;
    SceneNode *parent = nullptr;

    virtual void drawEvent(DrawContext *ctx) = 0;

  private:
};

} // namespace UI
#endif // !GRAPH_ITEM
#define GRAPH_ITEM
