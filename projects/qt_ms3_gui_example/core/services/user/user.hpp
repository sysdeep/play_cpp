#pragma once

#include "./iuser.hpp"

class User : public IUser
{
public:
    User();

    int get_mask() override;
};