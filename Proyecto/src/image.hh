#include "../include/CImg.h"

#ifndef IMAGE_CLASS
#define IMAGE_CLASS

class Image
{
private:
	CImg<unsigned char> Img;
	
public:
	Image (string foto);
	
	~Image();
		
};

#endif
