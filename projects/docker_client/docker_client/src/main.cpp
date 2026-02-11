#include <iostream>
#include "client/client.hpp"

int main()
{
    std::cout << "Hello" << std::endl;

    // unix socket
    Client cli;

    // tcp
    // std::string host("http://172.28.2.1:2375");
    // Client cli(host);

    cli.containers->get_all();
    cli.images->get_all();

    //
    cli.system_info();

    // version
    auto version = cli.docker_version();
    std::cout << version.build_time << std::endl;
    std::cout << version.kernel_version << std::endl;
    std::cout << "Version: " << version.version << std::endl;
    std::cout << "Api version: " << version.api_version << std::endl;

    // SIGFAULT
    // other client
    // Docker client = Docker("http://<ip>:<port>");
    // Docker client = Docker("http://172.28.2.1:2375");

    // JSON_DOCUMENT doc = client.docker_version();
    // std::cout << jsonToString(doc) << std::endl;

    return 0;
}