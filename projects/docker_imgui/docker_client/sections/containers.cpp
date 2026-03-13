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

std::vector<ContainerListModel> Containers::get_all(bool all)
{

    // --------------------------------------------------------------------
    // 1. Создаем JSON с фильтрами через RapidJSON
    // Структура: {"status": ["running"], "label": ["env=prod"]}
    rapidjson::Document filters;
    filters.SetObject();
    rapidjson::Document::AllocatorType &allocator = filters.GetAllocator();

    // Фильтр по статусу
    rapidjson::Value statusArray(rapidjson::kArrayType);
    statusArray.PushBack("running", allocator);
    filters.AddMember("status", statusArray, allocator);

    // // Фильтр по метке
    // rapidjson::Value labelArray(rapidjson::kArrayType);
    // labelArray.PushBack("env=prod", allocator);
    // filters.AddMember("label", labelArray, allocator);

    // 2. Сериализуем JSON в строку
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    filters.Accept(writer);
    std::string jsonFilters = buffer.GetString();

    std::cout << "Filters JSON: " << jsonFilters << std::endl;

    // 3. URL-кодирование (через curl или вручную)
    CURL *curl = curl_easy_init();
    char *output = curl_easy_escape(curl, jsonFilters.c_str(), jsonFilters.length());
    std::string encodedFilters = output;

    std::cout << "Encoded Filters: " << encodedFilters << std::endl;
    // --------------------------------------------------------------------

    // bool all, int limit, const std::string &since, const std::string &before, int size, JSON_DOCUMENT &filters
    // std::string path = "/containers/json?";

    // std::string path = "/containers/json";

    ParamsBuilder builder;
    builder.add("all", all ? "true" : "false");
    // builder.add("filters", encodedFilters);

    auto query_params = builder.build();
    std::cout << "Query params: " << query_params << std::endl;

    std::string path = "/containers/json?" + query_params;
    std::cout << "Path: " << path << std::endl;

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