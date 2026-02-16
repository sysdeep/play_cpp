#include <SFML/Graphics.hpp>
#include "views/lamp_view.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML CMake Setup");

    // Create a graphical shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(220.f, 140.f);

    auto lamp = LampView(10.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw items
        window.draw(shape);
        window.draw(lamp);

        // display
        window.display();
    }

    return 0;
}
