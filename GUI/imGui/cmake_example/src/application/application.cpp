#include "./application.hpp"
#include "./app_models/dsensor_model.hpp"
#include "./app_models/root_model.hpp"
#include "application/application_ctx.hpp"
#include "logic/project/project.hpp"
#include "ui/main_window.hpp"
#include <iostream>

Application::Application() {

    application_ctx = new ApplicationCtx();
    application_ctx->project = new LOGIC::Project();

    // auto section_node = application_ctx->project->get_node_by_name("section");
    // std::cout << "found section node: " << section_node->name << std::endl;

    // root app model
    application_ctx->root = new RootModel(application_ctx->project->get_node_root());

    _main_window = new UI::MainWindow(application_ctx);

    std::cout << "Application created" << std::endl;

    // ok
    // auto node = application_ctx->project->get_node_by_name("root");
    // std::cout << "node root: " << node << std::endl;
    // auto foo = application_ctx->project->get_node_by_name("foo");
    // std::cout << "node foo: " << foo << std::endl;
}

void Application::run() {
    std::cout << "application run" << std::endl;

    _main_window->loop();

    std::cout << "application finish" << std::endl;
}
