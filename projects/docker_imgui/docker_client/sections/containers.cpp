#include "containers.hpp"
#include <iostream>
#include "session/params_builder.hpp"
#include "parser/containers_list_parser.hpp"
#include "parser/container_parser.hpp"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace docker;
Containers::Containers(Session *session) : session(session) {}

std::vector<ContainerListModel> Containers::get_all(bool all, std::optional<ContainersFilter> filter)
{

    ParamsBuilder builder;
    builder.add("all", all ? "true" : "false");

    if (filter.has_value())
    {
        std::string jsonFilters = filter.value().format();
        // std::cout << "Filters JSON: " << jsonFilters << std::endl;

        // 3. URL-кодирование (через curl или вручную)
        CURL *curl = curl_easy_init();
        char *output = curl_easy_escape(curl, jsonFilters.c_str(), jsonFilters.length());
        std::string encodedFilters = output;

        // std::cout << "Encoded Filters: " << encodedFilters << std::endl;

        builder.add("filters", encodedFilters);
    }
    // --------------------------------------------------------------------

    // bool all, int limit, const std::string &since, const std::string &before, int size, JSON_DOCUMENT &filters
    // std::string path = "/containers/json?";

    // std::string path = "/containers/json";

    auto query_params = builder.build();
    // std::cout << "Query params: " << query_params << std::endl;

    std::string path = "/containers/json?" + query_params;
    // std::cout << "Path: " << path << std::endl;

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        // std::cout << "----------------------------------" << std::endl;
        // std::cout << "containers: " << res.second << std::endl;
        // std::cout << "----------------------------------" << std::endl;
        return parser::parseContainersList(res.second);
    }

    // TODO: error
    std::vector<ContainerListModel> result;
    return result;
}

ContainerModel Containers::get(const std::string &id)
{
    std::string path = "/containers/" + id + "/json";

    auto res = this->session->get(path);
    if (res.first == 200)
    {
        return parser::parseContainer(res.second);
    }

    // TODO: error
    ContainerModel result;
    return result;
}