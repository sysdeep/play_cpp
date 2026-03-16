#include "./application.hpp"
#include "application/application_ctx.hpp"
#include "logic/project/project.hpp"
#include "ui/main_window.hpp"
#include <iostream>

Application::Application() {

    application_ctx = new ApplicationCtx();
    application_ctx->project = new LOGIC::Project();

    _main_window = new UI::MainWindow(application_ctx);

    std::cout << "Application created" << std::endl;
}

void Application::run() {
    std::cout << "application run" << std::endl;

    _main_window->loop();

    std::cout << "application finish" << std::endl;
}
