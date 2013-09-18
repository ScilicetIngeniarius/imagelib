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


/*
 * Filter Function
 * void Filter (int [] kernel)
 * {
	 * // K = 2m+1;
	 * int k = matriz.width();
	 * int m = (k-1)/2
	 * 
	 * //Se define la matriz de números (Para extraer los valores de unsigned char)
	 * //Se definen las dimensiones de la 
	 * unsigned char matrix [this->spectrum()] [this->depth()] [this->width()] [this->height()];
	 * 
	 * 
	 * for(int c = 0; c < this->depth(); c++)
	 * {
		 * for(int z = 0; z < this->spectrum(); z++)
		 * {
			 * for(int x = 0; x < this->width(); x++)
			 * {
				 * for(int y = 0; y < this->height(); y++)
				 * {
					 * //HASTA AQUI, SOLO RECORRO TODA LA IMAGEN; FALTA EL KERNEL
					 * 
					 * int sum = 0;
					 * 
					 * //Para el kernel:
					 * for(int i = x-m; i <= x+1; i++)
					 * {
						 * for(int j = y-m; j<= j+1; j++)
						 * {
							 * sum += this->Img->getMatrix...;
						 * }
					 * }
					 * 
					 * this->Img->setpixel(x,y,z,c, sum/(K*k))
				 * }
			 * }
		 * }
	 * }  
 * }
 * 
*/
