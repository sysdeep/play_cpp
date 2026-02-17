#include "scene_node.hpp"
#include <iostream>

SceneNode::SceneNode(float x, float y, SceneNode *parent) : x{x}, y{y}, parent{parent}
{
    if (parent != nullptr)
    {
        std::cout << "add parent" << std::endl;
        parent->add_children(this);
    }
}

std::vector<SceneNode *> SceneNode::get_childrens()
{
    return childrens;
};

std::vector<sf::Drawable *> SceneNode::get_drawable()
{
    return draw_items;
};

void SceneNode::add_drawable(sf::Drawable *item)
{
    draw_items.push_back(item);
}

void SceneNode::add_children(SceneNode *item)
{
    childrens.push_back(item);
}

void SceneNode::update(UpdateCtx *ctx)
{
    this->updatedEvent(ctx);

    for (auto children : childrens)
    {
        children->update(ctx);
    }
};