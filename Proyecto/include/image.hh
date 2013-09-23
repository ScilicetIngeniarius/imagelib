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
	
public:
	Image ();
	///Image() is the constructor of the image used when the image doesn't been be created.
	Image (const char *const filename);
	///Image (const char *const filename) this constructor is used when the image already exist's and is stored in \param filename.
	Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value);
	/**Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
	 * This constructor is used when we try to create an image with the specified dimensions and the parameter \param value is the value of the color of all the pixels of the image.
	 */
	~Image(void);
	/// \fn ~Image(void) es el destructor de la clase
	

	unsigned int get_pixel_value(int, int, int, int); ///< \fn get_pixel_value returns the unsigned char value of the pixel in the given coordinates.

	void set_pixel_value(int x, int y, int z, int c, unsigned char value); ///< \fn set_pixel_value allows to set value of pixel in an image.  
	
	unsigned int get_width();///< \fn get_width() allows to obtain the width of the image.
	unsigned int get_height();///< \fn get_height allows to obtain the height of the image.
	unsigned int get_depth();///< \fn get_depth allows to obtain the depth of the image.
	unsigned int get_spectrum();///< \fn get_spectrum allows to obtain the specrum of the image.

	
	
	void save(const char *const savefilename);
	///< \fn save(const char *const savefilename) allows to save an image with the name of \param savefilename.

	Image filter(int *kernel, int , float);

};

#endif
