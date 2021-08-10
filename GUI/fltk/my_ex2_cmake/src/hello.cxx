#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Progress.H>
 
int main(int argc, char **argv) {

	std::cout << "Hello" << std::endl;
	// return 0;	


	Fl_Window *window = new Fl_Window(340,180);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show(argc, argv);
	return Fl::run();
	
	

	// Fl_Window win(220,90);
 //    Fl_Button butt(10,10,100,25,"Press");
 //    // butt.callback(butt_cb, &win);
 //    win.resizable(win);
 //    win.show();
 //    return(Fl::run());
}