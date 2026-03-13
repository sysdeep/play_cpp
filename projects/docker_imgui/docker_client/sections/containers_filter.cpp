#include "containers_filter.hpp"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace docker;

ContainersFilter *ContainersFilter::addAncestor(const std::string &imageId)
{
    ancestor_list.push_back(imageId);
    return this;
}

/*
Available filters:

ancestor=(<image-name>[:<tag>], <image id>, or <image@digest>)
before=(<container id> or <container name>)
expose=(<port>[/<proto>]|<startport-endport>/[<proto>])
exited=<int> containers with exit code of <int>
health=(starting|healthy|unhealthy|none)
id=<ID> a container's ID
isolation=(default|process|hyperv) (Windows daemon only)
is-task=(true|false)
label=key or label="key=value" of a container label
name=<name> a container's name
network=(<network id> or <network name>)
publish=(<port>[/<proto>]|<startport-endport>/[<proto>])
since=(<container id> or <container name>)
status=(created|restarting|running|removing|paused|exited|dead)
volume=(<volume name> or <mount point destination>)
*/
const std::string ContainersFilter::format()
{

    // 1. Создаем JSON с фильтрами через RapidJSON
    // Структура: {"status": ["running"], "label": ["env=prod"]}
    // все фильтры в виде массива
    rapidjson::Document filters;
    filters.SetObject();
    rapidjson::Document::AllocatorType &allocator = filters.GetAllocator();

    // accessor
    if (!ancestor_list.empty())
    {
        rapidjson::Value ancestorArray(rapidjson::kArrayType);
        for (const auto &ancestor : ancestor_list)
        {
            auto val = rapidjson::Value(ancestor.c_str(), allocator); // Важно передать allocator!
            ancestorArray.PushBack(val, allocator);
        }
        filters.AddMember("ancestor", ancestorArray, allocator);
    }

    // Фильтр по статусу
    // rapidjson::Value statusArray(rapidjson::kArrayType);
    // statusArray.PushBack("running", allocator);
    // filters.AddMember("status", statusArray, allocator);

    // // Фильтр по метке
    // rapidjson::Value labelArray(rapidjson::kArrayType);
    // labelArray.PushBack("env=prod", allocator);
    // filters.AddMember("label", labelArray, allocator);

    // 2. Сериализуем JSON в строку
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    filters.Accept(writer);
    return buffer.GetString();
}