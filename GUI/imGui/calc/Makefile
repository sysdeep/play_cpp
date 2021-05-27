CXX = g++

EXE = app
OBJS = ./src/main.o ./src/imgui_impl_glfw_gl3.o
OBJS += ./vendors/imgui/imgui.o ./vendors/imgui/imgui_draw.o
OBJS += ./vendors/gl3w/GL/gl3w.o
OBJS += ./src/main_menu/main_menu.o


LIBS = -lGL `pkg-config --static --libs glfw3`

CXXFLAGS = -I./vendors/imgui -I./vendors/glfw -I./vendors/gl3w `pkg-config --cflags glfw3`
CXXFLAGS += -Wall -Wformat -std=c++11
CFLAGS = $(CXXFLAGS)






.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<


all: $(EXE)
	@echo Build complete for

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS) $(LIBS)












clean:
	rm $(EXE) $(OBJS)