#include "./application.hpp"
#include "ui/main_window.hpp"
#include <iostream>

Application::Application() {

    this->_main_window = new UI::MainWindow();
    std::cout << "Application created" << std::endl;
}

void Application::run() {
    std::cout << "application run" << std::endl;

    _main_window->loop();

    std::cout << "application finish" << std::endl;
}
