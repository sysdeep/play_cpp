#pragma once
#include "session/session.hpp"

class Images
{
public:
    Images(Session *session);

    void get_all();

private:
    Session *session;
};