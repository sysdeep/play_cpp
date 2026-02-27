#include "docker_client.hpp"
#include <string>
#include <iostream>
// #include "nlohmann/json.hpp"
#include "models/docker_version.hpp"
#include "rapidjson/document.h"

// using json = nlohmann::json;
using namespace docker;

DockerClient::DockerClient() : host("http:/v1.24")
{
    this->is_remote = false;
    this->init();
}

DockerClient::DockerClient(std::string host) : host(host)
{
    this->is_remote = false;
    this->init();
}

DockerClient::~DockerClient()
{
    curl_global_cleanup();
}

void DockerClient::init()
{
    if (this->is_remote)
    {
        this->session = new Session(this->host);
    }
    else
    {
        this->session = new Session();
    }
    this->containers = new Containers(this->session);
    this->images = new Images(this->session);
    this->system = new System(session);
}

DockerVersion DockerClient::docker_version()
{
    std::string path = "/version";

    auto res = this->session->get(path);
    // std::cout << "status: " << res.first << std::endl;
    // std::cout << res.second << std::endl;

    // json data = json::parse(res.second);

    // std::cout << data["BuildTime"] << std::endl;

    // TODO
    DockerVersion v{};
    // DockerVersion v = DockerVersion::fromString(res.second);
    // std::cout << v.build_time << std::endl;
    // std::cout << v.kernel_version << std::endl;

    return v;
}
