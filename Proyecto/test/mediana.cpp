#include "../include/image.hh"


int main()
{
	Image imagen ("../../Multimedia/lena.pgm");

	int kernel[25];
	
	for (int j=0; j<5; j++)
	{ 
		for (int i=0; i<5; i++)
		{
		kernel[5*j+i] = 1;
		}
	}
	
	//Now we apply the filter with the kernel. Note that normalizer = 9
	
	Image filtered = imagen.filter_median(kernel, 5);
	
	filtered.save("filter_median.ppm");

}
