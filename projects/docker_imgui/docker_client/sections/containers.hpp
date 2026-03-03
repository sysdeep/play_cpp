#pragma once
#include "session/session.hpp"
#include <vector>
#include "models/container_list_model.hpp"

namespace docker
{
    class Containers
    {
    public:
        Containers(Session *session);

        std::vector<ContainerListModel> get_all();

    private:
        Session *session;
    };
}