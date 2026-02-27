#include "application.hpp"

Application::Application(docker::DockerClient *docker_client)
{
    //
    main_window = new MainWindow(docker_client);
};

void Application::start()
{
    //
    main_window->start_loop();
};
