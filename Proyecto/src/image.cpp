#include "../include/image.hh"

Image::Image(const char *const filename)
{
	this->Img = new CImg<unsigned char>(filename);
	this->width = this->Img->width();
	this->height = this->Img->height();
	this->depth = this->Img->depth();
	this->spectrum = this->Img->spectrum();
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

unsigned int Image:: get_width()
{
	return this->width;
}
unsigned int Image:: get_height()
{
	return this->height;
}
unsigned int Image:: get_depth()
{
	return this->depth;
}
unsigned int Image:: get_spectrum()
{
	return this->spectrum;
}

void Image:: save(const char *const savefilename)
{
	this->Img->save(savefilename);
}
