#!/bin/bash


#--- not working
# g++ -I../fltk-1.3.6 -I../fltk-1.3.6/jpeg -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -I. -g -c hello.cxx
# cc -L../fltk-1.3.6/lib -lfltk_images -lpng -lz -lfltk_jpeg -lfltk_gl -lGLU -lGL -lfltk -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11  hello.o   -o hello



#*** Compile hello.cxx...
g++ -I.. -I../fltk-1.3.6 -I../fltk-1.3.6/jpeg -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -Wall -I. -c hello.cxx -o hello.o
#*** Linking hello...
g++ hello.o ../fltk-1.3.6/lib/libfltk_images.a -lpng -lz ../fltk-1.3.6/lib/libfltk_jpeg.a ../fltk-1.3.6/lib/libfltk.a -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11 -o hello
#rm hello.o
