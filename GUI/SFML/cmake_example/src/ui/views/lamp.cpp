#include "lamp.hpp"
#include <iostream>

Lamp::Lamp(float x, float y, float size, SceneNode *parent) : SceneNode{x, y, parent}, size{size}
{
    outer = new sf::CircleShape(size);
    outer->setFillColor(sf::Color::White);
    outer->setPosition(x, y);

    inner = new sf::CircleShape(size - 4);
    inner->setFillColor(sf::Color::Green);
    inner->setPosition(x + 4.f, y + 4.f);

    this->add_drawable(outer);
    this->add_drawable(inner);

    this->timer = new AniTimer(500, [&]()
                               {
                                   std::cout << "update lamp timer" << std::endl;
                                   this->light_state = !this->light_state;

                                   auto color = this->light_state ? sf::Color::Blue : sf::Color::Green;
                                   this->inner->setFillColor(color);
                                   //
                               });

    // cycle!
    // new Lamp(x + 30.f, y + 30.f, 10.f, this);
    // auto *qqq = new Lamp(x + 30.f, y + 30.f, 10.f, this);
    // this->childrens.push_back(qqq);
}

void Lamp::updatedEvent(UpdateCtx *ctx)
{
    this->timer->update(ctx);
};