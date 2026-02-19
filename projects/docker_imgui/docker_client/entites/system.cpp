#include "system.hpp"
#include "rapidjson/document.h"
#include <iostream>

System::System(Session *session) : session{session} {}

SystemInfo System::info()
{
    std::string path = "/info";

    auto res = this->session->get(path);
    std::cout << "status: " << res.first << std::endl;
    std::cout << res.second << std::endl;

    return SystemInfo::fromString(res.second);
}
