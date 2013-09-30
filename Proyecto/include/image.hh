#include "../include/CImg.h"
#include <string>
#include <cstddef>
#include <ostream>

/**\brief image.hh implements a wrapper over the library CImg.
 * For more information go to cimg.sourceforge.net
 */ 

using namespace cimg_library;
/**The namespace is defined to avoid functions and class names collisions 
 * that could happen with the inclusion of other C++ header files.
 */
using namespace std;

#ifndef IMAGE_CLASS
#define IMAGE_CLASS

class Image
/**\brief 	The Image class is the abstraction of the image, contains a CImg object that defines
 * the handling of the image.
 * 
 * This class have the attributes of the four dimensions of the image: height, width, depth and spectrum
 * 
 */
{
private:
	CImg<unsigned char> *Img; ///< \param CImg<unsigned char> *Img is a pointer to the image of type CImg, and that is treated as a unsigned char.
	unsigned int width; ///< \param unsigned int width refers to the width of the image.
	unsigned int height; ///< \param unsigned int height refers to the height of the image.
	unsigned int depth; ///< \param unsigned int depth refers to the depth of the image.
	unsigned int spectrum; ///< \param unsigned int spectrum refers to the spectrum of the image.
	CImgList<unsigned char> complex; 
	
public:
// *************************************************************************
// *********************** Constructors ************************************
// *************************************************************************

	Image ();
	///Image() is the constructor of the image used when the image doesn't been be created.
	
	Image (const char *const filename);
	///Image (const char *const filename) this constructor is used when the image already exist's and is stored in \param filename.
	
	Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value);
	/**Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
	 * This constructor is used when we try to create an image with the specified dimensions and the parameter \param value is the value of the color of all the pixels of the image.
	 */
	
	~Image(void); /// \fn ~Image(void) es el destructor de la clase
	

// *************************************************************************
// *********************** Save and Display ********************************
// *************************************************************************

	void save(const char *const savefilename); ///< \fn save(const char *const savefilename) allows to save an image with the name of \param savefilename.

	void display(const char* message); /// \fn void display() displays an image. CImg Display Wrapper
	
// *************************************************************************
// *********************** GETs & SEts *************************************
// *************************************************************************

	unsigned int get_pixel_value(int, int, int, int); ///< \fn get_pixel_value returns the unsigned char value of the pixel in the given coordinates.

	void set_pixel_value(int x, int y, int z, int c, unsigned char value); /// \fn set_pixel_value allows to set value of pixel in an image.  
	
	unsigned int get_width();///< \fn get_width() allows to obtain the width of the image.
	
	unsigned int get_height();///< \fn get_height allows to obtain the height of the image.
	
	unsigned int get_depth();///< \fn get_depth allows to obtain the depth of the image.
	
	unsigned int get_spectrum();///< \fn get_spectrum allows to obtain the specrum of the image.

// *************************************************************************
// **************************** Filter *************************************
// *************************************************************************
	
	Image filter(int kernel [], int , float); /// \fn Image filter(int kernel [], int , float) This function returns an Image object after applying the desired filter given by the kernel.

// *************************************************************************
// *********************** Arithmetic & Logic ******************************
// *************************************************************************

	Image substract_img(Image); /// \fn substract image allows to substract the pixel values of two images.

	Image sum_img(Image);
	
	Image multiply_img(double); /// \fn image multiplier multiplies an image by a factor.

	Image binarize_img(unsigned int); /// \fn bynary image adjust the pixel value to 0 or 255 depending on the cutoff values.
		
// *************************************************************************
// ************************* SPACE DOMAIN FILTERS **************************
// *************************************************************************

// *************************************************************************
// ********************** Sharpening Spatial Filters ***********************
// *************************************************************************

	Image filter_Laplacian(); /// \fn La placian filter, used to identify sudden changes in the image. 
	
	Image filter_Laplacian_no_diagonal(); /// \fn La placian filter no diagonal, calculates de laplacian of an image without including the diagonal directions.

	Image filter_Gradient_vertical(); /// \fn Gradient filter in the vertical direction
	
	Image filter_Gradient_horizontal(); /// \fn Gradient filter in the horizontal direction
	
	Image filter_Prewitt_N_S(); /// \fn Prewitt Filter in the North-South direction
	
	Image filter_Prewitt_NE_SW(); /// \fn Prewitt Filter in the Northeast-Southwest direction
	
	Image filter_Prewitt_E_W(); /// \fn Prewitt Filter in the East-West direction
	
	Image filter_Prewitt_NW_SE(); /// \fn Prewitt Filter in the Northwest-Southeast direction

	Image filter_edge_enhacement_displacement(unsigned int, unsigned int); /// \fn This filter displaces the image and by ...
	
	Image filter_horizontal_borders();
	
	Image filter_vertical_borders();
	
// *************************************************************************
// *********************** Smoothing Spatial Filters ***********************
// *************************************************************************

	Image filter_median(int);
	
	Image filter_average(int);
	
	Image filter_gaussian(int, int);
	
	Image filter_modal(int);
	
// *************************************************************************
// *********************** Frequency Domain Filters ************************
// *************************************************************************

void FFT();

void FFT_inverse();

void display_FFT();

// *************************************************************************
// ******************** Sharpening Frecquency Filters **********************
// *************************************************************************

	Image filter_butterworth_low_pass(Image, unsigned int, unsigned int);

// *************************************************************************
// ********************* Smoothing Frecquency Filters **********************
// *************************************************************************

// *************************************************************************
// *********************** Dot to Dot Transformations **********************
// *************************************************************************
	Image filter_dynamic_range_dilatation(unsigned char, unsigned char, double, double, double);

	Image inverse(); /// \fn inverse of an image substract the original pixel values to 255.
	
	Image log_transformation();
	
// *************************************************************************
// *********************** HISTOGRAM AND EQUALIZATION **********************
// *************************************************************************

	int* get_histogram(unsigned int c, unsigned int z);
	
	void plot_histogram(const char* title);
	
	int* histogram_equalization(int*);
};

#endif
