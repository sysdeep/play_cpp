#pragma once
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

class UpdateCtx
{
private:
    /* data */
public:
    UpdateCtx(/* args */);
    ~UpdateCtx();

    // время вызова update из главного loop
    std::chrono::system_clock::time_point update_time;
    std::vector<sf::Event> events;
};
