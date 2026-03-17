#include <iostream>
#include "./application.hpp"

Application::Application()
{

    _main_window = new UI::MainWindow();

    std::cout << "Application created" << std::endl;
}

void Application::run()
{
    std::cout << "application run" << std::endl;

    _main_window->loop();

    std::cout << "application finish" << std::endl;
}
