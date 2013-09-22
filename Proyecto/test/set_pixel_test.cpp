#include "../include/image.hh"

int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");
	
	for (int c=0; c<imagen.get_spectrum(); c++)
	{
		for (int j=0; j<imagen.get_width(); j++)
		{ 
			for (int i=0; i<imagen.get_height(); i++)
			{
				imagen.set_pixel_value(j, i, 0, c, 255) ;

			}
		}
	}
	
	imagen.save("blanco_1.ppm");
}
	 
