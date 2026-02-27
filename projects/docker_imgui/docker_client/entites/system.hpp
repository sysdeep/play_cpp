#pragma once
#include "session/session.hpp"
#include "models/system_info.hpp"

namespace docker
{
    class System
    {
    public:
        System(Session *session);

        // methods
        SystemInfo info();

    private:
        Session *session;
    };

}