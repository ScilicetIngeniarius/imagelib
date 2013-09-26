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

bin_blue: bin_blue.cpp
	$(CC) $(EFLAGS) bin_blue.exe bin_blue.cpp $(LFLAGS) 

median: mediana.cpp
	$(CC) $(EFLAGS) median.exe mediana.cpp $(LFLAGS) 


laplacian: Laplacian_mask.cpp
	$(CC) $(EFLAGS) laplace.exe Laplacian_mask.cpp $(LFLAGS)
	
substraction: img_substraction.cpp
	$(CC) $(EFLAGS) substraction.exe img_substraction.cpp $(LFLAGS)

multiply: img_multiply.cpp
	$(CC) $(EFLAGS) multiply.exe img_multiply.cpp $(LFLAGS)

binary: img_binary.cpp
	$(CC) $(EFLAGS) binary.exe img_binary.cpp $(LFLAGS)

average: promedio.cpp
	$(CC) $(EFLAGS) average.exe promedio.cpp $(LFLAGS)
	
gaussian: gaussian.cpp
	$(CC) $(EFLAGS) gaussian.exe gaussian.cpp $(LFLAGS)
