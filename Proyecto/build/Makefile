# Vars

CC = g++

CImgFLAGS = -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 

CFLAGS = -c -Wall 


all: image

image: ../src/image.cpp
	@echo "**************** Compiling Image.cpp *********************"
	@echo "*********** This may take a while, please wait ***********"
	$(CC) $(CFLAGS) ../src/image.cpp $(CImgFLAGS) 
	@echo "******************* DONE *********************************"
