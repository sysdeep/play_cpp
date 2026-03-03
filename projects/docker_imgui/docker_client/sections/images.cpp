#include <iostream>
#include "images.hpp"
#include "parser/images_list_parser.hpp"

using namespace docker;
Images::Images(Session *session) : session(session) {}

std::vector<ImageListModel> Images::get_all()
{

    std::string path = "/images/json";

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        return parser::parseImagesList(res.second);
    }

    std::vector<ImageListModel> result;
    return result;
    // std::cout << "images all: " << res.first << std::endl;
    // std::cout << "images: " << res.second << std::endl;
    // std::cout << "-------------------- " << std::endl;
}
