#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../core/update_ctx.hpp"

class SceneNode
{
public:
    SceneNode(float x, float y, SceneNode *parent = nullptr);

    std::vector<SceneNode *> get_childrens();
    std::vector<sf::Drawable *> get_drawable();

    void update(UpdateCtx *ctx);
    // void set_pos(float x, float y)
    // {
    //     this->x = x;
    //     this->y = y;
    // };

    float x = 0.0f;
    float y = 0.0f;

private:
    SceneNode *parent;
    std::vector<sf::Drawable *> draw_items;
    std::vector<SceneNode *> childrens;

protected:
    void add_drawable(sf::Drawable *item);
    void add_children(SceneNode *item);

    virtual void updatedEvent(UpdateCtx *ctx) {};
};