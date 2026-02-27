#pragma once
#include "ui/main_window/main_window.hpp"
#include "docker_client.hpp"

class Application
{
public:
    Application(docker::DockerClient *docker_client);

    void start();

private:
    MainWindow *main_window;
};