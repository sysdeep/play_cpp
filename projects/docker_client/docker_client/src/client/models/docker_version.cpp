#include "docker_version.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

DockerVersion DockerVersion::fromString(std::string src)
{
    json data = json::parse(src);
    // std::cout << data["BuildTime"] << std::endl;

    DockerVersion result;
    result.build_time = data["BuildTime"];
    result.kernel_version = data["KernelVersion"];

    return result;
}