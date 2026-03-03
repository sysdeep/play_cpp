#include "containers.hpp"
#include <iostream>
#include "session/params_builder.hpp"
#include "parser/containers_list_parser.hpp"

using namespace docker;
Containers::Containers(Session *session) : session(session) {}

std::vector<ContainerListModel> Containers::get_all()
{

    // bool all, int limit, const std::string &since, const std::string &before, int size, JSON_DOCUMENT &filters
    // std::string path = "/containers/json?";
    std::string path = "/containers/json";

    // ParamsBuilder builder;
    // builder.add("all", "true")

    //     path += param("all", all);
    // path += param("limit", limit);
    // path += param("since", since);
    // path += param("before", before);
    // path += param("size", size);
    // path += param("filters", filters);

    // auto res = this->session->get(path);

    // std::cout << "containers get all: " << res.first << std::endl;
    // std::cout << "containers: " << res.second << std::endl;
    // std::cout << "----------------------------------" << std::endl;

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "containers: " << res.second << std::endl;
        std::cout << "----------------------------------" << std::endl;
        return parser::parseContainersList(res.second);
    }

    // TODO: error
    std::vector<ContainerListModel> result;
    return result;
}