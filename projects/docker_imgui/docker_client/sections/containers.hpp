#pragma once
#include <vector>
#include <optional>
#include "session/session.hpp"
#include "models/container_list_model.hpp"
#include "models/container_model.hpp"
#include "containers_filter.hpp"

namespace docker
{
    class Containers
    {
    public:
        Containers(Session *session);

        std::vector<ContainerListModel> get_all(bool all = false, std::optional<ContainersFilter> filter = std::nullopt);
        ContainerModel get(const std::string &id);

    private:
        Session *session;
    };
}