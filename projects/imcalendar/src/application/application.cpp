#include <iostream>
#include "./application.hpp"

Application::Application()
{

    _main_window = new UI::MainWindow();
}

void Application::run()
{

    _main_window->loop();
}
