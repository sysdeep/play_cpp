#include "images.hpp"
#include <iostream>

Images::Images(Session *session) : session(session) {}

void Images::get_all()
{
    std::string path = "/images/json";

    auto res = this->session->get(path);
    std::cout << "images all: " << res.first << std::endl;
    std::cout << "images: " << res.second << std::endl;
    std::cout << "-------------------- " << std::endl;
}
