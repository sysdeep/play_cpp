#include "containers.hpp"
#include <iostream>
#include "session/params_builder.hpp"

Containers::Containers(Session *session) : session(session) {}

void Containers::get_all()
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

    auto res = this->session->get(path);

    std::cout << "containers get all: " << res.first << std::endl;
    std::cout << "containers: " << res.second << std::endl;
    std::cout << "----------------------------------" << std::endl;
}