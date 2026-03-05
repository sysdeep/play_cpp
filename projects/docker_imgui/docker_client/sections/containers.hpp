#pragma once
#include "session/session.hpp"
#include <vector>
#include "models/container_list_model.hpp"
#include "models/container_model.hpp"

namespace docker
{
    class Containers
    {
    public:
        Containers(Session *session);

        std::vector<ContainerListModel> get_all();
        ContainerModel get(const std::string &id);

    private:
        Session *session;
    };
}