#include <iostream>
#include "client.hpp"
#include "ddd/docker.h"

int main()
{
    std::cout << "Hello" << std::endl;

    Client cli;

    cli.containers.get_all();
    cli.images.get_all();
    cli.docker_version();
    cli.system_info();
    // cli.container.

    // other client
    // Docker client = Docker("http://<ip>:<port>");
    Docker client = Docker("http://172.28.2.1:2375");

    JSON_DOCUMENT doc = client.docker_version();
    std::cout << jsonToString(doc) << std::endl;

    return 0;
}