#pragma once
#include <vector>
#include "session/session.hpp"
#include "models/image_list_model.hpp"

namespace docker
{

    class Images
    {
    public:
        Images(Session *session);

        std::vector<ImageListModel> get_all();

    private:
        Session *session;
    };
}