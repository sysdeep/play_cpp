# MyEx1

Пример сборки


hello.cxx

```cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Progress.H>
 
int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(340,180);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
```

Makefile

```makefile
FLTKCONFIG   = ../fltk-1.3.6/fltk-config



CXX          = $(shell $(FLTKCONFIG) --cxx)
CXXFLAGS     = $(shell $(FLTKCONFIG) --cxxflags) -Wall -I.
LINKFLTK     = $(shell $(FLTKCONFIG) --ldstaticflags)
LINKFLTK_GL  = $(shell $(FLTKCONFIG) --use-gl --ldstaticflags)
LINKFLTK_IMG = $(shell $(FLTKCONFIG) --use-images --ldstaticflags)
LINKFLTK_ALL = $(shell $(FLTKCONFIG) --use-images --use-gl --ldstaticflags)
.SUFFIXES: .cxx .h .fl .o


default all: hello$(EXEEXT)


# HOW TO COMPILE
.cxx.o:
	@echo "*** Compile $<..."
	$(CXX) -I.. $(CXXFLAGS) -c $< -o $@

# HOW TO LINK
.o$(EXEEXT):
	@echo "*** Linking $@..."
	$(CXX) $< $(LINKFLTK_IMG) -o $@
# 	$(CXX) $< $(LINKFLTK) $(LINKFLTK_IMG) -o $@


```