#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/filename.H>
#include <iostream>

#include "gui/mnemo/mnemo.hpp"

Fl_Double_Window *window = nullptr;

Fl_Menu_Bar *app_menu_bar = nullptr;

void menu_quit_callback(Fl_Widget *, void *)
{
  Fl::hide_all_windows();
}

int main(int argc, char **argv)
{
  window = new Fl_Double_Window(600, 480, "FLTK CMake Example");
  window->begin();

  // menu
  app_menu_bar = new Fl_Menu_Bar(0, 0, window->w(), 25);
  app_menu_bar->add("File", FL_COMMAND + 'q', menu_quit_callback);
  window->callback(menu_quit_callback);

  std::cout << "version" << Fl::version() << std::endl;

  int mnemo_padding = 25;
  Mnemo *mnemo = new Mnemo(mnemo_padding, mnemo_padding, window->w() - mnemo_padding * 2, window->h() - mnemo_padding * 2);

  // Fl_Box *box = new Fl_Box(20, 40, 260, 60, "Hello, World!");
  // box->box(FL_UP_BOX);
  // box->labelsize(20);
  // box->labelfont(FL_BOLD + FL_ITALIC);

  Fl_Button *button = new Fl_Button(110, 120, 80, 30, "Quit");
  button->callback(menu_quit_callback);

  window->end();
  window->show(argc, argv);

  mnemo->lamp->start();

  return Fl::run();
}
