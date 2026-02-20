#include <iostream>
#include "docker_client.hpp"
#include "application/application.hpp"

int main()
{
    std::cout << "main" << std::endl;

    DockerClient *client = new DockerClient();
    // auto sys_info = client->system->info();
    // std::cout << "containers: " << sys_info.Containers << std::endl;
    auto images = client->images->get_all();
    std::cout << "images: " << images.size() << std::endl;

    Application app = Application(client);
    app.start();

    return 0;
}