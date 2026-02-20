#pragma once
#include <vector>
#include "session/session.hpp"
#include "models/image.hpp"

class Images
{
public:
    Images(Session *session);

    std::vector<Image> get_all();

private:
    Session *session;
};