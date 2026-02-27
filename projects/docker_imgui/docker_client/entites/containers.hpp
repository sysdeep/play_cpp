#pragma once
#include "session/session.hpp"

namespace docker
{
    class Containers
    {
    public:
        Containers(Session *session);

        void get_all();

    private:
        Session *session;
    };
}