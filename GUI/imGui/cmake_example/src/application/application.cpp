#include "./application.hpp"
#include "ui/main_window.hpp"
#include <iostream>

Application::Application() {
    std::cout << "Application created" << std::endl;

    this->_main_window = new UI::MainWindow();
}

void Application::run() { std::cout << "application run" << std::endl; }
