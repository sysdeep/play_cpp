#pragma once

#include "FL/Fl_Widget.H"
#include "FL/Fl_Box.H"
#include <FL/Fl_Slider.H>

class Lamp : public Fl_Box
{

public:
    Lamp(int x, int y, int size);
    int radius;
    void start();

    static void on_timeout(void *data);

    static void on_slider_cb(Fl_Widget *, void *);

private:
    void draw() FL_OVERRIDE;

    bool is_active = false;

    Fl_Slider *s;
};
