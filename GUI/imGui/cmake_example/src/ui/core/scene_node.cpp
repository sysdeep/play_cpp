#include "./scene_node.hpp"
#include <iostream>

UI::SceneNode::SceneNode(SceneNode *parent) : parent{parent}, _local_pos{0, 0}, _rect{0, 0} {
    if (parent != nullptr) {
        parent->childrens.push_back(this);
    }
}

void UI::SceneNode::setPos(float x, float y) {
    _local_pos.x = x;
    _local_pos.y = y;
}

void UI::SceneNode::setRect(float w, float h) {
    _rect.x = w;
    _rect.y = h;
}

void UI::SceneNode::draw(DrawContext *ctx) {
    auto p0 = ImGui::GetCursorScreenPos();
    // std::cout << "save pos: " << p0.x << " " << p0.y << std::endl;
    this->drawEvent(ctx);
    // std::cout << "restore pos: " << p0.x << " " << p0.y << std::endl;
    ImGui::SetCursorScreenPos(p0);
}