#include "../include/image.hh"

int main()
{
	Image imagen ("fitered_parrot2.ppm");
	
	for (int c=0; c<imagen.get_spectrum(); c++)
	{
		for (int x=10; x<imagen.get_width(); x++)
		{ 
			for (int y=10; y<imagen.get_height(); y++)
			{
				int sum = 0;
				
				for (int j=x-10; j<=x+10; j++)
				{ 
					for (int i=y-10; i<=y+10; i++)
					{
						sum += imagen.get_pixel_value(j,i,0,c);

					}
				}
				unsigned char pixel = static_cast<unsigned char>(sum / 100);
				imagen.set_pixel_value(x, y, 0, c , pixel);

			}
		}
	}
	
	imagen.save("fitered_parrot3.ppm");
}
