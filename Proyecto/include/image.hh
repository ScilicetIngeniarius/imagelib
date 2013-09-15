#include "../include/CImg.h"
#include <string>

using namespace cimg_library;
using namespace std;

#ifndef IMAGE_CLASS
#define IMAGE_CLASS

class Image
{
private:
	CImg<unsigned char> *Img;
	unsigned int width;
	unsigned int height;
	unsigned int depth;
	unsigned int spectrum;
	
	
public:
	Image ();
	Image (const char *const filename);
	Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value);
	~Image(void);
	
	unsigned int get_width();
	unsigned int get_height();
	unsigned int get_depth();
	unsigned int get_spectrum();
	
	void save(const char *const savefilename);
	
};

#endif
