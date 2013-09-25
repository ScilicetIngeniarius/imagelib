#include "../include/image.hh"
#include <iostream>


int main ()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");
	
	cout << "DEPTH: "<<imagen.get_depth(); 
	cout << "\nSPECTRUM " <<imagen.get_spectrum();
	cout << "\n";
	for (int i=0; i<imagen.get_width(); i++)
	{
		for (int j=0; j<imagen.get_height(); j++)
		{
			unsigned char a [] = {180, 180 , 180};
			imagen.set_pixel_value(a, i, j, 0);
		}
	}
	 
	
	
	imagen.save("prueba_4.pgm");

}
