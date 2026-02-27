#include <FL/fl_draw.H>
#include "./mnemo.hpp"

double args[6] = {140, 140, 50, 0, 360, 0};

Mnemo::Mnemo(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
{
    this->lamp = new Lamp(x + 200, y + 200, 60);
}

void Mnemo::draw()
{

    fl_color(FL_DARK3);
    fl_rectf(x(), y(), w(), h());

    fl_color(FL_WHITE);
    fl_begin_line();
    fl_arc(args[0], args[1], args[2], args[3], args[4]);
    fl_end_line();

    fl_color(FL_RED);
    fl_begin_line();
    fl_arc(args[0], args[1], 30, args[3], args[4]);
    fl_end_line();
}