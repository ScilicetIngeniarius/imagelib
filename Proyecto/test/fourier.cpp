# include "../include/CImg.h"
# include <iostream>

using namespace cimg_library;

int main ()
{
	CImg<float> real ("../../Multimedia/images.jpg");
	
	CImg<float> imaginary ();
	
	CImgList<float> list (real, imaginary);
	
	list = list.get_FFT();
	
	list.display();
	
	list = list.get_FFT(true);
	
	list.display();
}
