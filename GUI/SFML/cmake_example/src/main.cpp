#include <SFML/Graphics.hpp>
#include "views/lamp_view.hpp"
#include "ui/core/update_ctx.hpp"
#include "ui/views/lamp.hpp"
#include "ui/views/main_supply.hpp"
#include <iostream>

void redraw(sf::RenderWindow &window, SceneNode *node);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML CMake Setup");

    // Установка ограничения в 60 кадров в секунду
    window.setFramerateLimit(60);

    // простой объект в корне main
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(220.f, 140.f);

    // простой объект с наследованием - без композиции
    auto lamp = LampView(10.f);

    // сложные объекты в древовидной форме с композицией
    auto lamp_node = new Lamp(100.f, 100.f, 20.0f);
    auto main_supply = new MainSupply(150.f, 100.f);

    while (window.isOpen())
    {

        auto *ctx = new UpdateCtx();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for a mouse button pressed event
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check which button was pressed
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Left mouse button clicked at X: "
                              << event.mouseButton.x << ", Y: "
                              << event.mouseButton.y << std::endl;

                    // Add your click handling logic here (e.g., check if a sprite was clicked)
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "Right mouse button clicked." << std::endl;
                }
            }

            // Check for a mouse button released event (useful for drag operations or single clicks)
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Left mouse button released." << std::endl;
                }
            }

            ctx->events.push_back(event);
        }

        lamp.update(ctx);
        lamp_node->update(ctx);
        main_supply->update(ctx);

        window.clear(sf::Color::Black);

        // draw items
        window.draw(shape);
        window.draw(lamp);

        redraw(window, lamp_node);
        redraw(window, main_supply);

        // display
        window.display();
    }

    return 0;
}

/*
отрисовка дерева компонентов
*/
void redraw(sf::RenderWindow &window, SceneNode *node)
{
    // отрисовка самого объекта(внутренних приметивов)
    for (auto node : node->get_drawable())
    {
        window.draw(*node);
    }

    // отрисовка ветвей
    for (auto child : node->get_childrens())
    {
        redraw(window, child);
    }
}