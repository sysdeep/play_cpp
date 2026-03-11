#include <iostream>
#include "images.hpp"
#include "parser/images_list_parser.hpp"
#include "parser/image_parser.hpp"
#include "parser/image_history_parser.hpp"

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

ImageModel Images::get(const std::string &id)
{
    std::string path = "/images/" + id + "/json";

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        return parser::parseImage(res.second);
    }
    else
    {
        // TODO: throw exception
    }

    ImageModel result;
    return result;
}

std::vector<ImageHistoryModel> Images::get_history(const std::string &id)
{
    std::string path = "/images/" + id + "/history";

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        return parser::parseImageHistory(res.second);
    }
    else
    {
        // TODO: throw exception
    }

    std::vector<ImageHistoryModel> result;
    return result;
}