# This makefile is intented to compile every test made in the development of this library.

CC = g++
CFLAGS = -c -Wall
LFLAGS = ../src/image.o -O2 -L/usr/X11R6/lib -lm -lpthread -lX11
EFLAGS = -o

# All the targets
all: filter set_pixel blur binary bin_blue

set_pixel : set_pixel_test.cpp ../src/image.o
	$(CC) $(EFLAGS) pixel_test.exe set_pixel_test.cpp $(LFLAGS)

filter : Filter_usage.cpp
	$(CC) $(EFLAGS) fiter.exe Filter_usage.cpp $(LFLAGS) 

blur: Average_filter.cpp
	$(CC) $(EFLAGS) avg_filter.exe Average_filter.cpp $(LFLAGS)
 
binary: binary.cpp
	$(CC) $(EFLAGS) binary.exe binary.cpp $(LFLAGS)

bin_blue: bin_blue.cpp
	$(CC) $(EFLAGS) bin_blue.exe bin_blue.cpp $(LFLAGS) 
