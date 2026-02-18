#pragma once
#include <chrono>

class DrawContext {
  public:
    explicit DrawContext();

    // время вызова update из главного loop
    std::chrono::system_clock::time_point update_time;
    // std::vector<sf::Event> events;
};