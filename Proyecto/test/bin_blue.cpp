#include "../include/image.hh"

int main()
{
	Image imagen ("fitered_parrot4.ppm");
	
	for (int c=0; c<imagen.get_spectrum(); c++)
	{
		for (int x=0; x<imagen.get_width(); x++)
		{ 
			for (int y=0; y<imagen.get_height(); y++)
			{
				int sum = 0;
				
				if(c=2)
				{
					
					imagen.set_pixel_value(x, y, 0, c , 255);
					
				}else
				{imagen.set_pixel_value(x, y, 0, c , 0);}
			}
		}
	}
	
	imagen.save("fitered_parrot5.ppm");
}
