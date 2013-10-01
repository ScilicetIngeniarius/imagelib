#include "../include/image.hh"


/**\file ../include/image.hh
 * Header for the image class
 */
 
 // *************************************************************************
 // ********************* CONTRUCTORS ***************************************
 // *************************************************************************
 
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
// *************************************************************************
// ************************** SAVE & DISPLAY *******************************
// *************************************************************************
/** \fn void Image:: save(const char *const savefilename)
 * \brief Allows to save the image in a file with the name in the parameter \param const char *const savefilename
 * 
 */

void Image:: save(const char *const savefilename)
{
	this->Img->save(savefilename);
}

void Image :: display(const char* message)
{
	CImgDisplay main (*(this->Img), message);
	while(!main.is_closed())
	{
		main.wait();
	}
}

// *************************************************************************
// *************************** GETs & SETs *********************************
// *************************************************************************

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


// *************************************************************************
// ************************** FILTER ***************************************
// *************************************************************************


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
	
	int m = (int)(dim-1)/2;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					double sum_values = 0;
					
					for(unsigned int i = (x-m); i <= (x+m); i++)
					{
						for(unsigned int j = (y-m); j<= (y+m); j++)
						{
							sum_values += (this->get_pixel_value(i, j, z, c)) * (kernel[ (i-x+m)*dim + (j-y+m)]); 
						}
					}
					
					unsigned char pixel = static_cast<unsigned char> (abs(sum_values/ normalizer));
					
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
 }
 
 
// *************************************************************************
// **************************Arithmetic and Logic **************************
// *************************************************************************

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


Image Image :: sum_img(Image image2)
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
						unsigned char pixel;
						int sum = this->get_pixel_value(x,y,z,c)+image2.get_pixel_value(x,y,z,c);
						if (sum <= 255)
						{
							pixel = static_cast<unsigned int>(sum);
						}
						else
						{
							pixel = 255;
						}
						result.set_pixel_value(x,y,z,c,pixel);
					}
				}
			}
		}
	}
	return result;
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

/*! \fn Image Image :: bynarize_img(double)
 * \brief This function set the pixel value to 255 if the original pixel value is higher than a cutoff value, and 0 if the pixel value is less than the cut off value
 * \param unsigned int cutoff_value is the limit of the pixel value, to be changed by 0 or 255.
 * \return Image result: Is the result of binarize the image.
 */

Image Image :: binarize_img(unsigned int cutoff_value)
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
					unsigned char pixel= static_cast<unsigned int>(this->get_pixel_value(x,y,z,c));
					if(pixel >= cutoff_value)
						pixel=255;
					else
						pixel=0;
					result.set_pixel_value(x,y,z,c,pixel);

				}
			}
		}
	}

	
	return result;
}


// *************************************************************************
// ************************** SPACE DOMAIN FILTERS *************************
// *************************************************************************




// *************************************************************************
// *********************** Sharpening Spatial Filters **********************
// *************************************************************************

/// \fn Image Image::filter_Laplacian(): Returns an image after applying the Laplacian filter to the image. Considers the diagonal values
Image Image::filter_Laplacian()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = 0;
					
					for (unsigned int i = 0 ; i < 3; i++)
					{
						for(unsigned int j = 0 ; j < 3; j++)
						{
						sum += -this->get_pixel_value(x+i-1, y+i-1, z, c);
						}
					}
					
					sum += 9*(this->get_pixel_value(x,y,z,c));
					
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	return filtered; 
}

/*! \fn Image Image :: filter_Laplacian_no_diagonal(): The same as the  \fn filter_Laplacian(), but doesn't include the diagonal values.
* Works as a derivative function, reacts to high change on the pixels value, especially to noise, and borders.
* 
* \return A filtered Image with the laplacian filter.
*/
Image Image :: filter_Laplacian_no_diagonal()
{
	//int kernel[9] = {0, -1, 0, -1, 4, -1, 0, -1, 0};
	
	//return (this->filter(kernel, 3, 1));
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = 4*(this->get_pixel_value(x,y,z,c)) - (this->get_pixel_value(x-1,y,z,c) + this->get_pixel_value(x+1,y,z,c) + this->get_pixel_value(x,y-1,z,c) +this->get_pixel_value(x,y+1,z,c));
					
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	return filtered; 
	
}

/*! \fn  Image Image :: filter_Gradient_horizontal()
 * This filter is used as as Sharpening Spatial Filter, used to identify borders and noise in the image.
 * Can be used to identify horizontal borders or discrepation
 * \return An image object that contains the original image after receiving a gradient filter in the 
 * horizontal direction. Could be used to identify horizontal borders.
 */ 
Image Image :: filter_Gradient_horizontal()
{
	//int kernel [9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
	
	//return (this->filter(kernel, 3, 0.5));	
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = this->get_pixel_value(x-1, y-1, z, c) + 2*(this->get_pixel_value(x, y-1, z, c)) + this->get_pixel_value(x+1, y-1, z, c) - (this->get_pixel_value(x-1, y+1, z, c) + 2*(this->get_pixel_value(x, y+1, z, c)) + this->get_pixel_value(x+1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}

/*! \fn  Image Image :: filter_Gradient_vertical()
 * This filter is used as as Sharpening Spatial Filter, used to identify borders and noise in the image.
 * Can be used to identify vertical borders or discrepations.
 * \return An image object that contains the original image after receiving a gradient filter in the 
 * vertical direction. Could be used to identify vertical borders.
 */ 
Image Image :: filter_Gradient_vertical()
{
	//int kernel [9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
	
	//return (this->filter(kernel, 3, 0.5));	

	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = get_pixel_value(x-1, y-1, z, c) + 2*get_pixel_value(x-1, y, z, c) + get_pixel_value(x-1, y+1, z, c) - (get_pixel_value(x+1, y-1, z, c) + 2*get_pixel_value(x+1, y, z, c) + get_pixel_value(x+1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}

Image Image :: filter_Prewitt_N_S()
{
	//int kernel[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
	
	//return (this->filter(kernel, 3, 0.5));
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = get_pixel_value(x-1, y-1, z, c) + get_pixel_value(x, y-1, z, c) + get_pixel_value(x+1, y-1, z, c) - (get_pixel_value(x-1, y+1, z, c) + get_pixel_value(x, y+1, z, c) + get_pixel_value(x+1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}
	
Image Image ::filter_Prewitt_NE_SW()
{
	//int kernel[9] = {0, 1, 1, -1, 0, 1, -1, -1, 0};
	
	//return (this->filter(kernel, 3, 1));
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = get_pixel_value(x, y-1, z, c) + get_pixel_value(x+1, y-1, z, c) + get_pixel_value(x+1, y, z, c) - (get_pixel_value(x-1, y, z, c) + get_pixel_value(x-1, y+1, z, c) + get_pixel_value(x, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_Prewitt_E_W()
{
	//int kernel[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
	
	//return (this->filter(kernel, 3, 1));	
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = get_pixel_value(x-1, y-1, z, c) + get_pixel_value(x-1, y, z, c) + get_pixel_value(x-1, y+1, z, c) - (get_pixel_value(x+1, y-1, z, c) + get_pixel_value(x+1, y, z, c) + get_pixel_value(x+1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}
	
Image Image ::filter_Prewitt_NW_SE()
{
	//int kernel[9] = {-1, -1, 0, -1, 0, 1, 0, 1, 1};
	
	// (this->filter(kernel, 3, 1));	
	
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = get_pixel_value(x-1, y-1, z, c) + get_pixel_value(x-1, y, z, c) + get_pixel_value(x, y-1, z, c) - (get_pixel_value(x+1, y, z, c) + get_pixel_value(x+1, y+1, z, c) + get_pixel_value(x, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
		
}

Image Image ::filter_edge_enhacement_displacement(unsigned int horizontal_dis, unsigned int vertical_dis)
{
	Image result (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); 
	if((horizontal_dis < this->get_width()) && (vertical_dis < this->get_height()))
	{
		for(unsigned int c = 0; c < this->get_spectrum(); c++)
		{
			for(unsigned int z = 0; z < this->get_depth(); z++)
			{
				for(unsigned int x = horizontal_dis; x < this->get_width(); x++)
				{
					for(unsigned int y = vertical_dis; y < this->get_height(); y++)
					{
						unsigned char value = static_cast<unsigned char>(abs(this->get_pixel_value(x,y,z,c) - this->get_pixel_value(x-horizontal_dis, y-vertical_dis, z, c)));
						
						result.set_pixel_value(x,y,z,c, value);
					}
				}
			}
		}
	}
	return result;
}

Image Image :: filter_vertical_borders()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = 0; y < this->get_height()-m; y++)
				{
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(this->get_pixel_value(x-1, y, z, c) - get_pixel_value(x+1, y, z, c)));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}

Image Image :: filter_horizontal_borders()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(this->get_pixel_value(x, y-1, z, c) - get_pixel_value(x, y+1, z, c)));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}

// *************************************************************************
// *********************** Smoothing Spatial Filters **********************
// *************************************************************************

Image Image :: filter_median (int dim)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int kernel [dim*dim];

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
							pixel_values [(i-x+m)*dim + (j-y+m)]= this->get_pixel_value(i, j, z, c)* (kernel[(i-x+m)*dim + (j-y+m)]);
							
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


Image Image :: filter_average(int dim)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 

	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = dim; x < this->get_width()-dim; x++)
			{
				for(unsigned int y = dim; y < this->get_height()-dim; y++)
				{
					int sum = 0;
					for(unsigned int i = x-dim; i<= x+dim; i++)
					{
						for(unsigned int j = y-dim; j<= y+dim; j++)
						{
							sum += this->get_pixel_value(i, j, z, c);
						}
					}
			
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (sum/((dim*2+1)*(dim*2+1)));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;	
} 


Image Image :: filter_gaussian(int o, int dim_kernel)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0);

	double kernel[dim_kernel*dim_kernel];
	
	int m = (dim_kernel-1)/2;
	
	double gaussian =1/pow(3.1415*2*o,0.5);

	for(int i =-m; i <=m; i++)
	{
		for(int j =-m; j<=+m; j++)
		{
			double exp= -(i*i+j*j)*0.5/o;
			kernel[(i+m)*dim_kernel + (j+m)]=gaussian*pow(2.7,exp); 
		}
	}
	
	
	
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
							unsigned char pixel= this->get_pixel_value(i, j, z, c)* (kernel[(i-x+m)*dim_kernel + (j-y+m)]); 
							filtered.set_pixel_value(x, y, z, c, pixel);
						}
					}
					
				}
				
			 }
			 
		 }
	}  
	 return filtered;		
}	



Image Image :: filter_modal(int dim)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0);
	unsigned char pixel_values[dim*dim];
	unsigned char moda;
	unsigned char average=0;
	int m=(dim-1)/2;
	unsigned char copy_pixels[dim*dim];

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
							pixel_values [(i-x+m)*dim + (j-y+m)]= this->get_pixel_value(i, j, z, c);
		
							int frequency[dim*dim];
							moda=0;	
							
							for(int k=0;k<dim*dim;k++)
							{
								copy_pixels[k]=	pixel_values[k];
								frequency[k]=0;
							}
							
							for(int p=0;p<dim*dim;p++)
							{
								for(int q=p+1;q<dim*dim;q++)
								{
									if(copy_pixels[p]==pixel_values[q]){
										frequency[p]++;
								
									}
			
								}
	
							}



							for(int s=0; s<dim*dim ; s++)
							{
								for(int e=s+1 ; e<dim*dim ; e++)
								{
									if(frequency[e] < frequency[s])
									{
										moda = copy_pixels[s];
										average=copy_pixels[s];
									}
								}
							}
							

							if(moda==0)
							{
								for(int k=0;k<dim*dim;k++)
								{
									moda += pixel_values[k];
								}
							average=(moda/dim);
							}


						}	
					}
					
					filtered.set_pixel_value(x, y, z, c, average);
				}
				
			 }
			 
		 }
	}

return filtered;

}
	

// *************************************************************************
// *********************** Frequency Domain Filters ************************
// *************************************************************************

/*void Image :: FFT()
{

	this->imaginary = new CImg<float> (this->width, this->height, this->depth, this->spectrum, 255);
	
	CImgList<float> list (*(this->Img), *(this->imaginary));
	
	list = list.get_FFT();
	
	*(this->real) = (list[0]);
	
	*(this->imaginary) = list[1];
	
}

// correnogramas
// fitro de varianza espacial
// 

void Image :: display_FFT()
{
	CImgList<float> list (*(this->real), *(this->imaginary));
	
	list.display();
}

void Image :: FFT_inverse()
{
	CImgList<float> list (*(this->real), *(this->imaginary));
	
	list = list.get_FFT(true);
	
	*this->real = list[0];
	
	*this->imaginary = list[1];
	
	*(this->Img) = list[0];
}*/

// *************************************************************************
// ******************** Sharpening Frecquency Filters **********************
// *************************************************************************

// *************************************************************************
// ********************* Smoothing Frecquency Filters **********************
// *************************************************************************



// *************************************************************************
// *********************** Dot to Dot Transformations **********************
// *************************************************************************

/*! \fn  Image Image :: inverse()
 * \return An image object that contains the inverse of the original image, this means that every pixel value is substracted to 255.
 */ 

Image Image ::inverse()
{
	Image inverted (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 

	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width(); x++)
			{
				for(unsigned int y = 0; y < this->get_height(); y++)
				{
					unsigned char pixel= static_cast<unsigned int>(255-this->get_pixel_value(x,y,z,c));
					inverted.set_pixel_value(x,y,z,c,pixel);
				}
			}
		}
	}
	return inverted;
}


Image Image :: log_transformation()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 

	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width(); x++)
			{
				for(unsigned int y = 0; y < this->get_height(); y++)
				{
					unsigned char pixel = static_cast<unsigned char>((255/log(256)) * log(1+this->get_pixel_value(x, y, z, c)));
					
					filtered.set_pixel_value(x,y,z,c, pixel);
				}
			}
		}
	}
	return filtered;
}

/*! \fn  Image Image ::filter_dynamic_range_dilatation(unsigned char a, unsigned char b, double alpha, double beta, double gamma)
 * \param unsigned char a is the first cutoff pixel value. 
 * \param unsigned char b is the second cutoff pixel value.
 * \param double alpha is the first multiplier.
 * \param double beta is the second multiplier.
 * \param double gamma is the third multiplier.
 * \return An image object that contains the dilatated image. All the pixel values are divided in three ranges, and each range suffer a diferent transformation.
 */ 
Image Image ::filter_dynamic_range_dilatation(unsigned char a, unsigned char b, double alpha, double beta, double gamma)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); 
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width(); x++)
			{
				for(unsigned int y = 0; y < this->get_height(); y++)
				{
					unsigned char pixel=0;
					
					if(this->get_pixel_value(x,y,z,c)<a)
						pixel =abs(alpha*this->get_pixel_value(x,y,z,c));
						
					else if(this->get_pixel_value(x,y,z,c)>=a && this->get_pixel_value(x,y,z,c)<b)
						pixel=abs(beta*(this->get_pixel_value(x,y,z,c)-a)+alpha*a);
					
					else if(this->get_pixel_value(x,y,z,c)<=b)
						
						pixel=abs(gamma*(this->get_pixel_value(x,y,z,c)-b)+((beta*(b-a))+alpha*a));
					filtered.set_pixel_value(x,y,z,c,static_cast<unsigned int>(pixel));
				}
			}
		}
	}
	return filtered;
}
// *************************************************************************
// *********************** HISTOGRAM AND EQUALIZATION **********************
// *************************************************************************

/*! \fn int* Image :: get_histogram(int c, int z)
 * This function returns an array containing the values of the histogram points, in the 
 * desired channel and depth. 
 * An Histogram is measure of the frecquency of a intensity value in an image, and is often 
 * used as a parameter to improve the constrast and quality of the image. After observing the 
 * histogram ( see plot_histogram() ) you could 
 * 
 * 
 */
int* Image :: get_histogram(unsigned int c, unsigned int z)
{
	int histogram [256];
	for(int i = 0; i<256; i++)
	{
	histogram[i] = 0;	
	}
	
	if (c < this->get_spectrum() && z < this->get_depth())
	{
		for(unsigned int x = 0; x < this->get_width(); x++)
		{
			for(unsigned int y = 0; y < this->get_height(); y++)
			{
				unsigned char pixel_value = this->get_pixel_value(x,y,z,c);
				(histogram[pixel_value])++;
			}
		}
	}
	
	int* histogram_pointer = histogram;
	
	return histogram_pointer;
}

void Image :: plot_histogram(int levels,const char* title)
{
	CImg<unsigned char> img = this->Img->histogram(levels);
	
	CImgDisplay main_display (*(this->Img), title);
	
	img.display_graph(main_display, 3, 1, "Pixel Intensity", 0, 0, "Frequency", 0, 0);
}

void Image :: plot_histogram_equalization(int levels, const char* title)
{
	CImg<unsigned char> img = this->Img->equalize(levels);
	
	CImgDisplay main_display (*(this->Img), title);
	
	img.display_graph(main_display, 3, 1, "Pixel Intensity", 0, 0, "Frequency", 0, 0);
}

// *************************************************************************
// *********************** OTHER TRANSFORMATIONS ***************************
// *************************************************************************

/*! \fn Image Image :: filter_kirsch_0()
 *  \brief Applies the kirsch mask at 0°.
 */
Image Image ::filter_kirsch_0()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_45()
 *  \brief Applies the kirsch mask at 45°.
 */
Image Image ::filter_kirsch_45()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x, y-1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
	
}

/*! \fn Image Image :: filter_kirsch_90()
 *  \brief Applies the kirsch mask at 90°.
 */
Image Image ::filter_kirsch_90()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x-1, y-1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_135()
 *  \brief Applies the kirsch mask at 135°.
 */
Image Image ::filter_kirsch_135()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_180()
 *  \brief Applies the kirsch mask at 180°.
 */
Image Image ::filter_kirsch_180()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x-1, y-1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_225()
 *  \brief Applies the kirsch mask at 225°.
 */
Image Image ::filter_kirsch_225()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_270()
 *  \brief Applies the kirsch mask at 270°.
 */
Image Image ::filter_kirsch_270()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c))+5*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x-1, y+1, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_kirsch_315()
 *  \brief Applies the kirsch mask at 315°.
 */
Image Image ::filter_kirsch_315()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = -3*(get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c))+5*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c));
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_0()
 *  \brief Applies the freeman mask [1,1,1][1,-2,1][1,-1,-1].
 */

Image Image ::filter_freeman_0()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1,y,z,c))-1*(get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_1()
 *  \brief Applies the freeman mask [1,1,1][-1,-2,1][1,-1,1].
 */
Image Image ::filter_freeman_1()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1,y,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y+1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_2()
 *  \brief Applies the freeman mask [-1,1,1][-1,-2,1][1,1,1].
 */
Image Image ::filter_freeman_2()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1,y+1,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_3()
 *  \brief Applies the freeman mask [-1,-1,1][-1,-2,1][1,1,1].
 */
Image Image ::filter_freeman_3()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1,y+1,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x-1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_4()
 *  \brief Applies the freeman mask [-1,-1,-1][1,-2,1][1,1,1].
 */
Image Image ::filter_freeman_4()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c))-1*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}


/*! \fn Image Image :: filter_freeman_5()
 *  \brief Applies the freeman mask [1,-1,-1][1,-2,-1][1,1,1].
 */
Image Image ::filter_freeman_5()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c))-1*(get_pixel_value(x+1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}


/*! \fn Image Image :: filter_freeman_6()
 *  \brief Applies the freeman mask [1,1,-1][1,-2,-1][1,1,-1].
 */
Image Image ::filter_freeman_6()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x, y-1, z, c))-1*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1,y+1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_freeman_7()
 *  \brief Applies the freeman mask [1,1,1][1,-2,-1][1,-1,-1].
 */
Image Image ::filter_freeman_7()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x, y-1, z, c))-1*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1,y+1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

/*! \fn Image Image :: filter_maximum()
 *  \brief Assigns the highest value in the neighborhood.
 * Assigns the highest value in the neighborhood around the desired pixel.
 */


Image Image :: filter_maximum()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 1; x < this->get_width()-1; x++)
			{
				for(unsigned int y = 1; y < this->get_height()-1; y++)
				{
					unsigned char max = 0;
					
					for (unsigned int i = x-1; i< x+2; i++)
					{
						for (unsigned int j = y-1; j< y+2; j++)
						{
							unsigned char pixel = (this->get_pixel_value(i, j, z, c));
							 
							if (pixel > max)
							{
								max = this->get_pixel_value(i, j, z, c);
							}
						} 
					}
					
					filtered.set_pixel_value(x, y, z, c, max);
				}
				
			 }
			 
		 }
	}  
	return filtered;
}


/*! \fn Image Image :: filter_minimun()
 *  \brief Assigns the lowest value in the neighborhood.
 * Assigns the lowest value in the neighborhood around the desired pixel.
 */

Image Image :: filter_minimum()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 1; x < this->get_width()-1; x++)
			{
				for(unsigned int y = 1; y < this->get_height()-1; y++)
				{
					unsigned char minimun = 255;
					
					for (unsigned int i = x-1; i< x+2; i++)
					{
						for (unsigned int j = y-1; j< y+2; j++)
						{
							if ((this->get_pixel_value(i, j, z, c)) < minimun)
							{
								minimun = this->get_pixel_value(i, j, z, c);
							}
						} 
					}
					
					filtered.set_pixel_value(x, y, z, c, minimun);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}
