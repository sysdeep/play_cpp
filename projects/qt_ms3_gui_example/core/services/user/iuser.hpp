#pragma once

class IUser
{
public:
    virtual ~IUser() = default;
    virtual int get_mask() = 0;
};