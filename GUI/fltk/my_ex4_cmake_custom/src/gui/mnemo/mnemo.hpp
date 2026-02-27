#pragma once

#include "FL/Fl_Widget.H"
#include "../views/lamp/lamp.hpp"

class Mnemo : public Fl_Widget
{

public:
    Mnemo(int x, int y, int w, int h);
    Lamp *lamp;

private:
    void draw() FL_OVERRIDE;
};
