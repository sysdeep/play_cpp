#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include "views/lamp_view.hpp"
#include "ui/core/update_ctx.hpp"
#include "ui/views/lamp.hpp"
#include "ui/views/main_supply.hpp"

void redraw(sf::RenderWindow &window, SceneNode *node);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML CMake Setup");

    // Установка ограничения в 60 кадров в секунду
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // простой объект в корне main
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(220.f, 140.f);

    // простой объект с наследованием - без композиции
    auto lamp = LampView(10.f);

    // сложные объекты в древовидной форме с композицией
    auto lamp_node = new Lamp(100.f, 100.f, 20.0f);
    auto main_supply = new MainSupply(150.f, 100.f);

    sf::Clock deltaClock;

    while (window.isOpen())
    {

        auto *ctx = new UpdateCtx();

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

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

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear(sf::Color::Black);

        // draw items
        window.draw(shape);
        window.draw(lamp);

        redraw(window, lamp_node);
        redraw(window, main_supply);

        ImGui::SFML::Render(window);

        // display
        window.display();
    }
    ImGui::SFML::Shutdown();
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