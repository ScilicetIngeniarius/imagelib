#include "../include/image.hh"

/**\file ../include/image.hh
 * Header for the image class
 */
 
 /** \fn Image::Image()
 * \brief Constructor
 * This constructor initializes the four dimension params at 0;
 * The \param Img calls the constructor of CImg to create an empty image.
 */
Image::Image()
{
	this->Img = new CImg<unsigned char>();
	this->width = 0;
	this->height = 0;
	this->depth = 0;
	this->spectrum = 0;
}
/** \fn Image::Image(const char *const filename)
 * \brief Constructor
 * 
 * This constructor is used when the image already exist's and is stored in the \param filename path.
 */

Image::Image(const char *const filename)
{
	this->Img = new CImg<unsigned char>(filename);
	///< \param <Img> is a var of type Cimg that is treated like an unsigned char.
	this->width = this->Img->width();
	///< \param <width> refers to the number of columns of pixels in the image.
	this->height = this->Img->height();
	///< \param <height> refers to the number of rows of pixels in the image.
	this->depth = this->Img->depth();
	///< \param <depth> is the amount of layers of depth the image has, usually is one, except for 3D images.
	this->spectrum = this->Img->spectrum();
	///< \param <spectrum> is the number of channels in the image, RGB has a spectrum of 3, a monocromatic image has a spectrum of 1.
		
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
{
	///Este es el constructor de la imagen para el caso en el que le pasen los parámetros de la imagen.
	this->Img = new CImg<unsigned char>(width, height, depth, spectrum, value);
	///Llama al constrcutor de CImg donde se le dan los valores de width, height, depth, spectrum, y value (NO SE QUE ES VALUE)
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->spectrum = spectrum;
	
	this->update_matrix();
}

Image::~Image(void)
{
	///~Image(void) es el destructor de la clase
}

/** \fn unsigned int Image:: get_width()
 * \brief returns a pointer of type int, with the width of the image.
 * 
 */
unsigned int Image:: get_width()
{
	return this->width;
}
/** \fn unsigned int Image:: get_height()
 * \brief returns a pointer of type int, with the height of the image.
 * 
 */
unsigned int Image:: get_height()
{
	return this->height;
}

/** \fn unsigned int Image:: get_depth()
 * \brief returns a pointer of type int, with the depth of the image.
 * 
 */
unsigned int Image:: get_depth()
{
	return this->depth;
}

/** \fn unsigned int Image:: get_spectrum()
 * \brief returns a pointer of type int, with the spectrum of the image.
 * 
 */
unsigned int Image:: get_spectrum()
{
	return this->spectrum;
}
/** \fn void Image:: save(const char *const savefilename)
 * \brief Allows to save the image in a file with the name in the parameter \param const char *const savefilename
 * 
 */
void Image:: save(const char *const savefilename)
{
	this->Img->save(savefilename);
}

/*! \fn unsigned int Image:: get_pixel_value(int x, int y, int z, int c)
 * \brief Returns the value of the unsigned char in the x, y, z, and c coordinates.
 */

unsigned int Image:: get_pixel_value(int x, int y, int z, int c)
{
	return this->Img->get_vector_at(x, y, z)[c];
}

/*! \fn Image Image :: filter (int [] *kernel )
 * \brief This function aplies a space domain filter, its a general function, and each filter will
 * depend on the \param kernel matrix, wich provides the respective weights to the surroundings.
 * \param int [] *kernel: Must ve a square matrix, of anm uneven dimention, because the center value
 * must be the (x,y) value.
 * \param int dim: Is the dimention of the square matrix. 
 * \param float normalizer: Is a value in order to avoid the loss of information and normalize the output of the sum of the values of the pixel in the
 * neighborhood with the weight values of the kernel. 
 */

Image Image :: filter (int [] *kernel, int dim, float normalizer)
{
	Image filtered (this->get_width() , this->get_height(), this->depth(), this->spectrum(), int value);
	int m = (dim-1)/2;
	
	for(int z = 0; c < this->depth(); c++)
	{
		for(int c = 0; z < this->spectrum(); z++)
		{
			for(int x = 0; x < this->width(); x++)
			{
				for(int y = 0; y < this->height(); y++)
				{
					///A variable to sum the values of the kernes with the heights.
					int sum = 0;
					
					///Two loops for the kernel:
					for(int i = x-m; i <= x+1; i++)
					{
						for(int j = y-m; j<= j+1; j++)
						{
							sum += this->get_pixel_value(i, j, z, c) * (*kernel[i][j]); 
						}
					}
					 
					unsigned int pixel_value = sum * normalizer;
				 }
			 }
		 }
	 }  
 }


