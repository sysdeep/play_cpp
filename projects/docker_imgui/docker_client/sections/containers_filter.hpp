#pragma once
#include <string>
#include <vector>

namespace docker
{
    // ContainersFilter - билдер параметров фильтрации контейнеров
    class ContainersFilter
    {
    public:
        ContainersFilter *addAncestor(const std::string &imageId);
        const std::string format();

    private:
        std::vector<std::string> ancestor_list;
    };
}
