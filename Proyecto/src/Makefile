# Vars

CC = g++

CImgFLAGS = -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 

CFLAGS = -c -Wall 


all: image

image: image.cpp
	@echo "**************** Compiling Image.cpp *********************"
	@echo "*********** This may take a while, please wait ***********"
	$(CC) $(CFLAGS) image.cpp $(CImgFLAGS) 
