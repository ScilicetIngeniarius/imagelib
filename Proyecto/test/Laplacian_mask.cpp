#include "../include/image.hh"
#include <iostream>

int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");

	int kernel[9];
	
	for (int j=0; j<3; j++)
	{ 
		for (int i=0; i<3; i++)
		{
			if(j==i && i == 1)
			{
				kernel[3*j+i] = 8;
			}
			else
			{
				kernel[3*j+i] = -1;
			}
		}
	}
	
	//Now we apply the filter with the kernel. Note that normalizer =
	
	Image filtered = imagen.filter(kernel, 3, 1);
	
	filtered.save("laplacian.ppm");

}
