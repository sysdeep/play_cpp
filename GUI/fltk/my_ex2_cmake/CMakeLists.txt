cmake_minimum_required(VERSION 3.10)
set( CMAKE_VERBOSE_MAKEFILE on )

# set the project name
project(hello)


# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")





include_directories(${CMAKE_SOURCE_DIR}/../fltk/)

set(SOURCES src/hello.cxx)

# add the executable
add_executable(hello ${SOURCES})


target_link_libraries(hello 
	${CMAKE_SOURCE_DIR}/../fltk/lib/libfltk_images.a
	"-lpng -lz" 
	${CMAKE_SOURCE_DIR}/../fltk/lib/libfltk_jpeg.a
	${CMAKE_SOURCE_DIR}/../fltk/lib/libfltk.a
	"-lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11" 
	)










# /usr/bin/c++   
# 	-lpng 
# 	-lz 
# 	-lXrender 
# 	-lXcursor 
# 	-lXfixes 
# 	-lXext 
# 	-lXft 
# 	-lfontconfig 
# 	-lXinerama 
# 	-lpthread 
# 	-ldl 
# 	-lm 
# 	-lX11 
# 	../../fltk/lib/libfltk.a 
# 	../../fltk/lib/libfltk_images.a 
# 	../../fltk/lib/libfltk_jpeg.a 


# g++ hello.o 
# 	../fltk-1.3.6/lib/libfltk_images.a 
# 	-lpng 
# 	-lz 
# 	../fltk-1.3.6/lib/libfltk_jpeg.a 
# 	../fltk-1.3.6/lib/libfltk.a 
# 	-lXrender 
# 	-lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11 -o hello