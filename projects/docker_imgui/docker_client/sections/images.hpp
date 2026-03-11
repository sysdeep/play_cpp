#pragma once
#include <vector>
#include "session/session.hpp"
#include "models/image_list_model.hpp"
#include "models/image_model.hpp"
#include "models/image_history_model.hpp"

namespace docker
{

    class Images
    {
    public:
        Images(Session *session);

        std::vector<ImageListModel> get_all();
        ImageModel get(const std::string &id);
        std::vector<ImageHistoryModel> get_history(const std::string &id);

    private:
        Session *session;
    };
}