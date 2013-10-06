# This makefile is intented to compile every test made in the development of this library.

CC = g++
CFLAGS = -c -Wall
LFLAGS = ../build/image.o -O2 -L/usr/X11R6/lib -lm -lpthread -lX11
EFLAGS = -o

# All the targets
all: Tutorials 

Tutorials: Tutorial2 Tutorial Tutorial3

set_pixel : set_pixel_test.cpp ../build/image.o
	$(CC) $(EFLAGS) pixel_test.exe set_pixel_test.cpp $(LFLAGS)

filter : Filter_usage.cpp
	$(CC) $(EFLAGS) fiter.exe Filter_usage.cpp $(LFLAGS) 

blur: Average_filter.cpp
	$(CC) $(EFLAGS) avg_filter.exe Average_filter.cpp $(LFLAGS)

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
	
inverse: inverse.cpp
	$(CC) $(EFLAGS) inverse.exe inverse.cpp $(LFLAGS)

sharpening_spatial: Sharpening_spatial_filters.cpp
	$(CC) $(EFLAGS) sharp_spatial.exe Sharpening_spatial_filters.cpp $(LFLAGS)

average: promedio.cpp
	$(CC) $(EFLAGS) average.exe promedio.cpp $(LFLAGS)
	
gaussian: gaussian.cpp
	$(CC) $(EFLAGS) gaussian.exe gaussian.cpp $(LFLAGS)

butterworth: Butterworth.cpp
		$(CC) $(EFLAGS) butterworth.exe Butterworth.cpp $(LFLAGS)

dilatation: dilatation.cpp
	$(CC) $(EFLAGS) dilatation.exe dilatation.cpp $(LFLAGS)

modal: moda.cpp
	$(CC) $(EFLAGS) modal.exe moda.cpp $(LFLAGS)

fourier: fourier.cpp
	$(CC) $(EFLAGS) fourier.exe fourier.cpp $(LFLAGS)
	
equalization: equalization.cpp
	$(CC) $(EFLAGS) equalization.exe equalization.cpp $(LFLAGS)

	
Variance: Varianza.cpp
	$(CC) $(EFLAGS) Variance.exe Varianza.cpp $(LFLAGS)
	
Tutorial: Tutorial.cpp
	$(CC) $(EFLAGS) Tutorial.exe Tutorial.cpp $(LFLAGS)
	
Tutorial3: Tutorial3.cpp
	$(CC) $(EFLAGS) Tutorial3.exe Tutorial3.cpp $(LFLAGS)
	
Noises: noises.cpp
	$(CC) $(EFLAGS) Noises.exe noises.cpp $(LFLAGS)


kirsch: kirsch.cpp
	$(CC) $(EFLAGS) kirsch.exe kirsch.cpp $(LFLAGS)
	
freeman: freeman.cpp
	$(CC) $(EFLAGS) freeman.exe freeman.cpp $(LFLAGS)
	
max_min: maxandmin.cpp
	$(CC) $(EFLAGS) max_min.exe maxandmin.cpp $(LFLAGS)
	
Tutorial2: Tutorial2.cpp
	$(CC) $(EFLAGS) Tutorial2.exe Tutorial2.cpp $(LFLAGS)
	
interpolation: interpolacion.cpp
	$(CC) $(EFLAGS) interpolation.exe interpolacion.cpp $(LFLAGS)

gray_scale: gray_scale.cpp
	$(CC) $(EFLAGS) gray_scale.exe gray_scale.cpp $(LFLAGS)
	
coorrelogram: coorrelogram.cpp
	$(CC) $(EFLAGS) coorrelogram.exe coorrelogram.cpp $(LFLAGS)
	
coorrelogram2: coorrelogram2.cpp
	$(CC) $(EFLAGS) coorrelogram2.exe coorrelogram2.cpp $(LFLAGS)
