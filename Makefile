# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g

# the build target executable:
TARGET = main
TARGETSTATIC = static/main
TARGETMAP = map/main

$(TARGET): map.cpp
	
	$(CC) -o $(TARGETMAP) map/map.cpp map/allstruct.c map/cursor.c map/video.c map/plotting.c map/rotasi.c map/drawing.c map/clip.c -lpthread
	
	$(CC) -o $(TARGETSTATIC) static/map.cpp static/allstruct.c static/cursor.c static/video.c static/plotting.c static/rotasi.c static/drawing.c static/clip3d.c -lpthread

	$(CC) -o $(TARGET) map.cpp allstruct.c cursor.c video.c plotting.c rotasi.c drawing.c clip.c colorpicker.c clip3d.c -lpthread -lm
	
clean:
	$(RM) $(TARGET)
	$(RM) $(TARGETSTATIC)
	$(RM) $(TARGETMAP) 
