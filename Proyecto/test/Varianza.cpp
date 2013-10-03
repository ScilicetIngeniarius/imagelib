#include "../include/image.hh"
#include "math.h"
#include "stdio.h"


int main()
{
	Image img ("../../Multimedia/parrot_original.ppm");
	Image img_variance = img.variance(2);
	img_variance.display("variance");
}

Image Image :: variance(int dim)
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 

	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = dim; x < this->get_width()-dim; x++)
			{
				for(unsigned int y = dim; y < this->get_height()-dim; y++)
				{
					int sum = 0;
					double variance=0;
					int kernel_values[(dim*2+1)*(dim*2+1)];
					int cont=0;

					for(unsigned int i = x-dim; i<= x+dim; i++)
					{
						for(unsigned int j = y-dim; j<= y+dim; j++)
						{
							sum += this->get_pixel_value(i, j, z, c);
							kernel_values[cont]=this->get_pixel_value(i, j, z, c);
							cont++;
						}
					}
			
					double average =  sum/((dim*2+1)*(dim*2+1));
					for(int i=0;i<(dim*2+1)*(dim*2+1);i++)
					{
						variance+=average*pow(kernel_values[i]-average,2);
					}
					
					
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (variance);
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	 return filtered;
}
