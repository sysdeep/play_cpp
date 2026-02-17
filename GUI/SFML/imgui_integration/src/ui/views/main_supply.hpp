#pragma once
#include <SFML/Graphics.hpp>
#include "../scene_node/scene_node.hpp"
#include "../core/ani_timer.hpp"
#include "lamp.hpp"

class MainSupply : public SceneNode
{
public:
    explicit MainSupply(float x, float y, SceneNode *parent = nullptr);

    void updatedEvent(UpdateCtx *ctx) override;

private:
    float size;
    // bool light_state = false;
    // AniTimer *timer;

    Lamp *sensor_enabled;

    sf::RectangleShape *inner;

    bool blocked = false;
};
