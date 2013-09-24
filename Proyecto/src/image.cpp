#include "../include/image.hh"

/**\file ../include/image.hh
 * Header for the image class
 */
 
 /** \fn Image::Image()
 * \brief Constructor
 * This constructor initializes the four dimension params at 0;
 * The Img calls the constructor of CImg to create an empty image.
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
/** \fn Image::Image(const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
 * \brief This constructor is used when we need to create an image, and gives the dimensions of the image, and the value of a color that fills all the pixels.
 * 
 */
Image::Image(const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
{
	this->Img = new CImg<unsigned char>(width, height, depth, spectrum, value);
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->spectrum = spectrum;
}
/** \fn ~Image(void) 
 * \brief is the destructor of the class.
 */ 
Image::~Image(void)
{
	
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

/*! \fn void Image:: set_pixel_value(unsigned char (int x, int y, int z, int c, unsigned char value)
 * \brief Sets the value of the unsigned chars in the x, y and z coordinates of a pixel.
 */

void Image:: set_pixel_value(int x, int y, int z, int c, unsigned char value)
{
	(*(this->Img))(x, y, z, c)= value;
}

/*! \fn Image Image :: filter (int [] *kernel )
 * \brief This function aplies a space domain filter, its a general function, and each filter will
 * depend on the \param kernel matrix, wich provides the respective weights to the surroundings.
 * \param int [] *kernel: Must be a square matrix, of anm uneven dimention, because the center value
 * must be the (x,y) value.
 * \param int dim: Is the dimention of the square matrix. 
 * \param float normalizer: Is a value in order to avoid the loss of information and normalize the output of the sum of the values of the pixel in the
 * neighborhood with the weight values of the kernel. Normally, this value could be the max value of the multiplication of the pixels in the neighborhoog
 * divided between 255 (Maximun of intensity). 
 */
 
Image Image :: filter (int kernel [], int dim, float normalizer)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = (dim-1)/2;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width(); x++)
			{
				for(unsigned int y = m; y < this->get_height(); y++)
				{
					double sum_values =0;
					
					for(unsigned int i = x-m; i < x+m; i++)
					{
						for(unsigned int j = y-m; j< y+m; j++)
						{
							sum_values += this->get_pixel_value(i, j, z, c)* (kernel[(i-x+m)*dim + (j-y+m)]); 
						}
					}
					
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs((sum_values) / normalizer));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
 }
 
 /// \fn Image Image::filter_Laplacian(): Returns an image after applying the Laplacian filter to the image. Considers the diagonal values
Image Image::filter_Laplacian()
{
	int kernel[9];
	
	for (int j=0; j<3; j++)
	{ 
		for (int i=0; i<3; i++)
		{
			if(j==i && i == 1)
			{
				kernel[3*j+i] = 8;
			}
			else
			{
				kernel[3*j+i] = -1;
			}
		}
	}
	
	return (this->filter(kernel, 3, 8)); 
}

/// \fn Image Image :: filter_Laplacian_no_diagonal(): The same as the \fn filter_Laplacian(), but doesn't include the diagonal values.
Image Image :: filter_Laplacian_no_diagonal()
{
	int kernel[9] = {0, -1, 0, -1, 4, -1, 0, -1, 0};
	
	return (this->filter(kernel, 3, 4));
}


Image Image :: filter_median (int kernel [], int dim)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = (dim-1)/2;
	unsigned char pixel_values [dim*dim-1];
	unsigned char temp;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width(); x++)
			{
				for(unsigned int y = m; y < this->get_height(); y++)
				{
					for(unsigned int i = x-m; i < x+m; i++)
					{
						for(unsigned int j = y-m; j< y+m; j++)
						{
							pixel_values [dim*dim-1]= this->get_pixel_value(i, j, z, c)* (kernel[(i-x+m)*dim + (j-y+m)]);
							
							for(int k=0; k<dim*dim-1 ; k++)
							{
								for(int p=k+1 ; p<dim*dim-1 ; p++)
								{
									if(pixel_values[p] < pixel_values[k])
									{
										// Intercambiar los valores
										temp = pixel_values[k];
										pixel_values[k] = pixel_values[p];
										pixel_values[p] = temp;
									}
								}
							}
						}	
					}
					
					unsigned char pixel = pixel_values[((dim*dim-1)/2)-1];
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
 }



/*! \fn Image Image :: substract_img(Image image2)
 * \brief This function substracts the pixel values of two images, that can be used to see the differences between them. 
 * \param Image image2: Is the image that will be substracted to the original image.
 * \return Image result: Is the result of the substraction of both images.
 */
Image Image :: substract_img(Image image2)
{
	Image result (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 

	if(this->get_width() == image2.get_width() && this->get_height() == image2.get_height() && this->get_depth() == image2.get_depth() && this->get_spectrum() == image2.get_spectrum())
	{
		for(unsigned int c = 0; c < this->get_spectrum(); c++)
		{
			for(unsigned int z = 0; z < this->get_depth(); z++)
			{
				for(unsigned int x = 0; x < this->get_width(); x++)
				{
					for(unsigned int y = 0; y < this->get_height(); y++)
					{
						unsigned char pixel= static_cast<unsigned int>(abs(this->get_pixel_value(x,y,z,c)-image2.get_pixel_value(x,y,z,c)));
	
						result.set_pixel_value(x,y,z,c,pixel);
					}
				}
			}
		}
	}
	return result;
}

Image Image :: filter_Gradient_horizontal()
{
	int kernel [9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
	
	return (this->filter(kernel, 3, 4));	
}

Image Image :: filter_Gradient_vertical()
{
	int kernel [9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
	
	return (this->filter(kernel, 3, 4));	
}

/*! \fn Image Image :: multiply_img(double)
 * \brief This function multiplies the pixel values by a factor. If the pixel value is higher than 255, adjust the pixel value to 255.
 * \param double multiplier is the factor that mutiplies all the pixel values.
 * \return Image result: Is the result of multiply the image.
 */

Image Image :: multiply_img(double multiplier)
{
	Image result (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0);
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width(); x++)
			{
				for(unsigned int y = 0; y < this->get_height(); y++)
				{
					unsigned char pixel= static_cast<unsigned int>(abs(this->get_pixel_value(x,y,z,c)*multiplier));
					if (pixel >255)
						pixel = 255;
					result.set_pixel_value(x,y,z,c,pixel);
				}
			}
		}
	}
	return result;
}

