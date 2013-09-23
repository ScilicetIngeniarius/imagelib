#include "../include/image.hh"

int main()
{
	Image imagen ("fitered_parrot.ppm");
	
	for (int c=0; c<imagen.get_spectrum(); c++)
	{
		for (int x=0; x<imagen.get_width(); x++)
		{ 
			for (int y=0; y<imagen.get_height(); y++)
			{
				int sum = 0;
				
				
				if(imagen.get_pixel_value(x,y,0,c)>127)
				{
					imagen.set_pixel_value(x, y, 0, c , 255);
				}
				else
					imagen.set_pixel_value(x, y, 0, c , 0);
			}
		}
	}
	
	imagen.save("fitered_parrot2.ppm");
}
