#pragma once
#include <vector>
#include "session/session.hpp"
#include "models/image.hpp"

namespace docker
{

    class Images
    {
    public:
        Images(Session *session);

        std::vector<Image> get_all();

    private:
        Session *session;
    };
}