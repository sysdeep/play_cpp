#include "main_supply.hpp"
#include <iostream>

MainSupply::MainSupply(float x, float y, SceneNode *parent) : SceneNode{x, y, parent}, size{size}
{
    inner = new sf::RectangleShape(sf::Vector2f{40.f, 60.f});
    inner->setFillColor(sf::Color::Yellow);
    inner->setPosition(x, y);

    this->add_drawable(inner);

    sensor_enabled = new Lamp(x + 2.f, y + 2.f, 8, this);

    new Lamp(x + 2.f, y + 14.f, 10, this);
}

void MainSupply::updatedEvent(UpdateCtx *ctx)
{

    for (auto event : ctx->events)
    {

        // Check for a mouse button pressed event
        if (event.type == sf::Event::MouseButtonPressed)
        {

            // Check which button was pressed
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                // std::cout << "Main supply - Left mouse button clicked at X: "
                //           << event.mouseButton.x << ", Y: "
                //           << event.mouseButton.y << std::endl;

                if (inner->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    blocked = !blocked;
                    auto color = blocked ? sf::Color::Red : sf::Color::Yellow;
                    inner->setFillColor(color);
                }

                // Add your click handling logic here (e.g., check if a sprite was clicked)
            }
            // else if (event.mouseButton.button == sf::Mouse::Right)
            // {
            //     std::cout << "Right mouse button clicked." << std::endl;
            // }
        }

        // Check for a mouse button released event (useful for drag operations or single clicks)
        // if (event.type == sf::Event::MouseButtonReleased)
        // {
        //     if (event.mouseButton.button == sf::Mouse::Left)
        //     {
        //         std::cout << "Main supply - Left mouse button released." << std::endl;
        //     }
        // }
    }
};