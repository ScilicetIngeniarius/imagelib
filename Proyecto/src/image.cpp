#include "../include/image.hh"

Image::Image(const char *const filename)
{
	this->Img = new CImg<unsigned char>(filename);
	this->width = this->Img.;
	this->height = 0;
	this->depth = 0;
	this->spectrum = 0;
}

Image::Image()
{
	this->Img = new CImg<unsigned char>();
	this->width = 0;
	this->height = 0;
	this->depth = 0;
	this->spectrum = 0;
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
{
	this->Img = new CImg<unsigned char>(width, height, depth, spectrum, value);
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->spectrum = spectrum;
}

Image::~Image(void)
{

}

/*
Image :: CImgDisplay Display (Image *image, string title)
{
	CImgDisplay main_disp (image, title); 
}
*/
