
# ../fltk-1.3.6/fltk-config --ldstaticflags
# ../fltk-1.3.6/lib/libfltk.a -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11

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




#--- not working 2
# CXX      = $(shell $(FLTKCONFIG) --cxx)
# DEBUG    = -g
# CXXFLAGS = $(shell $(FLTKCONFIG) --use-images --cxxflags ) -I.
# LDFLAGS  = $(shell $(FLTKCONFIG) --use-images --ldflags )
# LDSTATIC = $(shell $(FLTKCONFIG) --use-images --ldstaticflags )
# LINK     = $(CXX)
 
# TARGET = hello
# OBJS = hello.o
# SRCS = hello.cxx
 
# .SUFFIXES: .o .cxx
# %.o: %.cxx
# 	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

# all: $(TARGET)
# 	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

# $(TARGET): $(OBJS)

# hello.o: hello.cxx
 
# clean: $(TARGET) $(OBJS)
# 	rm -f *.o 2> /dev/null
# 	rm -f $(TARGET) 2> /dev/null





#--- not working...
# CXX      = g++
# DEBUG    = -g
# CXXFLAGS = -I../fltk-1.3.6 -I../fltk-1.3.6/jpeg -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
# # LDFLAGS  = -L../fltk-1.3.6/lib -lfltk -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
# # LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
# LDSTATIC = ../fltk-1.3.6/lib/libfltk.a -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
# LINK     = $(CXX)
 
# TARGET = hello
# OBJS = hello.o
# SRCS = hello.cxx
 
# .SUFFIXES: .o .cxx

# %.o: %.cxx
# 	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

# all: $(TARGET)
# 	$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

# $(TARGET): $(OBJS)
# hello.o: hello.cxx
 
# clean: $(TARGET) $(OBJS)
# 	rm -f *.o 2> /dev/null
# 	rm -f $(TARGET) 2> /dev/null



#--- site example
# CXX      = $(shell fltk-config --cxx)
# DEBUG    = -g
# CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
# LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
# LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
# LINK     = $(CXX)
 
# TARGET = cube
# OBJS = CubeMain.o CubeView.o CubeViewUI.o
# SRCS = CubeMain.cxx CubeView.cxx CubeViewUI.cxx
 
# .SUFFIXES: .o .cxx
# %.o: %.cxx
#         $(CXX) $(CXXFLAGS) $(DEBUG) -c $<
 
# all: $(TARGET)
#         $(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)
 
# $(TARGET): $(OBJS)
# CubeMain.o: CubeMain.cxx CubeViewUI.h
# CubeView.o: CubeView.cxx CubeView.h CubeViewUI.h
# CubeViewUI.o: CubeViewUI.cxx CubeView.h
 
# clean: $(TARGET) $(OBJS)
#         rm -f *.o 2> /dev/null
#         rm -f $(TARGET) 2> /dev/null