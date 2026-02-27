/*
https://www.seriss.com/people/erco/fltk/#AnimateDrawing
*/
#include <FL/fl_draw.H>

#include "./lamp.hpp"
#include <iostream>

Lamp::Lamp(int x, int y, int size) : Fl_Box(x, y, size, size), radius(size / 2)
{
    box(FL_FLAT_BOX);
    color(45);

    s = new Fl_Slider(x - 40, y, 20, 100, "foo");
    s->step(1);
    s->minimum(0);
    s->maximum(radius * 2);
    s->value(radius);
    s->align(FL_ALIGN_LEFT);
    s->callback(on_slider_cb, (void *)this);

    // Fl::add_timeout(0.5, [](void *data)
    //                 { std::cout << "after" << std::endl; });
}

void Lamp::on_slider_cb(Fl_Widget *o, void *p)
{
    Fl_Slider *s = (Fl_Slider *)o;
    auto val = s->value();
    std::cout << val << std::endl;

    Lamp *l = (Lamp *)p;
    l->radius = val;
    l->redraw();
}

void Lamp::start()
{
    Fl::add_timeout(0.5, on_timeout, (void *)this);
}

void Lamp::draw()
{

    auto c = is_active ? FL_GREEN : FL_YELLOW;
    std::cout << c << std::endl;
    std::cout << x() << std::endl;
    auto aaa = std::to_string(c);

    Fl_Box::draw();

    fl_push_clip(x(), y(), w(), h());
    fl_push_matrix(); // NOTE: это очень важная штука!! без нею update не работает

    // fl_color(FL_READ);
    // fl_rectf(x(), y(), w(), h());

    // fl_color(FL_DARK3);
    // fl_rectf(x(), y(), w(), h());

    fl_translate(x(), y());
    // fl_translate(x() + w() / 2.0, y() + h() / 2.0);

    // body
    fl_color(c);
    fl_begin_polygon();
    fl_arc(radius, radius, radius, 360, 0);
    fl_end_polygon();

    // border
    fl_color(FL_BLUE);
    fl_begin_line();
    fl_arc(radius, radius, radius, 360, 0);
    fl_end_line();

    // fl_color(FL_RED);
    // fl_begin_line();
    // fl_arc(args[0], args[1], 30, args[3], args[4]);
    // fl_end_line();

    // DRAW TIMER TEXT STRING
    fl_color(FL_WHITE);
    fl_font(FL_HELVETICA, 16);
    fl_draw(aaa.c_str(), x() + 4, y() + h() - 4);

    fl_pop_matrix();
    fl_pop_clip();
}

void Lamp::on_timeout(void *data)
{
    std::cout << "on timeout" << std::endl;
    Lamp *l = (Lamp *)data;

    l->is_active = !l->is_active;
    // l->position(l->x() + 10, l->y());
    l->redraw();
    // Fl::wait();

    Fl::repeat_timeout(0.5, on_timeout, data);
}