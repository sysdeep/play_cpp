#include "images.hpp"
#include <iostream>

Images::Images(Session *session) : session(session) {}

std::vector<Image> Images::get_all()
{

    std::string path = "/images/json";

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        return Image::fromStringArray(res.second);
    }

    std::vector<Image> result;
    return result;
    // std::cout << "images all: " << res.first << std::endl;
    // std::cout << "images: " << res.second << std::endl;
    // std::cout << "-------------------- " << std::endl;
}
