# include "../include/image.hh"

int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	Image real      (imagen.get_width(), imagen.get_height(), imagen.get_depth(), imagen.get_spectrum(), 0);
	
	Image imaginary (imagen.get_width(), imagen.get_height(), imagen.get_depth(), imagen.get_spectrum(), 0);
	
	for(unsigned int c = 0; c < image.spectrum(); c++)
	{
		for(unsigned int z = 0; z < real.depth(); z++)
		{
			for(unsigned int x = 0; x < real.width(); x++)
			{
				for(unsigned int y = 0; y < real.height(); y++)
				{
					real.set_pixel_value(x, y, z, c) = 
				}
			}		 
		}
	}  
}
