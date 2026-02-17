#include "lamp_view.hpp"
#include <iostream>
#include <chrono>

/*
простой вариант одиночного view - композиция отсутствует
*/
LampView::LampView(float size) : sf::CircleShape(size)
// LampView::LampView(float size)
{

    inner = new sf::CircleShape(size - 4);
    inner->setFillColor(sf::Color::Green);
    inner->setPosition(2.f, 2.f);

    this->timer = new AniTimer(500, [&]()
                               {
                                   std::cout << "update lamp timer" << std::endl;
                                   this->light_state = !this->light_state;

                                   auto color = this->light_state ? sf::Color::Blue : sf::Color::Green;
                                   this->setFillColor(color);
                                   //
                               });
}

void LampView::update(UpdateCtx *ctx)
{

    // meashuring
    // auto start = std::chrono::high_resolution_clock::now();

    // auto end = std::chrono::high_resolution_clock::now();

    // // Calculate the duration and cast to milliseconds
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    // get time
    // // Get the current time point from the system clock
    // system_clock::time_point now = system_clock::now();

    // // Cast the duration since the epoch to milliseconds and get the count
    // uint64_t milliseconds = duration_cast<milliseconds>(now.time_since_epoch()).count();

    // std::cout << "update" << std::endl;
    this->timer->update(ctx);
};

// void LampView::draw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     this->outer->draw(target, states);
//     this->inner->draw(target, states);

//     // this->outer->
// }