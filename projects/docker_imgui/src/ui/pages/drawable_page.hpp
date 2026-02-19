#pragma once

class DrawablePage
{
public:
    virtual ~DrawablePage() {};

    virtual void draw() = 0;
};