# include "../include/CImg.h"
# include <iostream>
#include <math.h>

using namespace cimg_library;

int main ()
{
	CImg<float> real ("../../Multimedia/lena.pgm");
	
	real.display("Normal");
	
	CImg<float> imaginary ();
	
	CImgList<float> list (real, imaginary);
	
	list = list.get_FFT();
	
	CImg<float> magnitude (real.width(), real.height(), real.depth(), real.spectrum(), 0);
	
	CImg<float> fase(real.width(), real.height(), real.depth(), real.spectrum(), 0);
	
	CImg<float> real2 (real.width(), real.height(), real.depth(), real.spectrum(), 0);
	
	CImg<float> im2(real.width(), real.height(), real.depth(), real.spectrum(), 0);
	
	CImgList<float> list2 (real2, im2);
	
	for(unsigned int c = 0; c < real.spectrum(); c++)
	{
		for(unsigned int z = 0; z < real.depth(); z++)
		{
			for(unsigned int x = 1; x < real.width(); x++)
			{
				for(unsigned int y = 1; y < real.height(); y++)
				{
					
					magnitude(x,y,z,c) = sqrt(((list[0])(x, y, z, c))*(list[0])(x, y, z, c) + ((list[0])(x, y, z, c))*((list[1])(x, y, z, c)) );
					
					fase(x,y,z,c) = atan(  ((list[1])(x, y, z, c)) / ((list[0])(x, y, z, c))  );

				}
				
			 }
			 
		 }
	}  
	CImgList<float> mag_dir (magnitude, fase);
	
	mag_dir.display();
	
	
	//INVERSA
	for(unsigned int c = 0; c < real.spectrum(); c++)
	{
		for(unsigned int z = 0; z < real.depth(); z++)
		{
			for(unsigned int x = 1; x < real.width(); x++)
			{
				for(unsigned int y = 1; y < real.height(); y++)
				{
					(list2[0])(x, y, z, c) = magnitude(x, y, z, c) * cos(fase(x, y, z, c));
					(list2[1])(x, y, z, c) = magnitude(x, y, z, c) * sin(fase(x, y, z, c));
				}
				
			 }
			 
		 }
	}
	
	
	list2 = list2.get_FFT(true);
	
	list2.display();
}
