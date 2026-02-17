#pragma once
#include <SFML/Graphics.hpp>
#include "../scene_node/scene_node.hpp"
#include "../core/ani_timer.hpp"

class Lamp : public SceneNode
{
public:
    explicit Lamp(float x, float y, float size, SceneNode *parent = nullptr);

    void updatedEvent(UpdateCtx *ctx) override;

private:
    float size;
    bool light_state = false;
    AniTimer *timer;

    sf::CircleShape *inner;
    sf::CircleShape *outer;
};
