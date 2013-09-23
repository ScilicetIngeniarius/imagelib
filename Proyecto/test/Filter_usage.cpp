#include "../include/image.hh"

int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");

	int kernel[25];
	
	for (int j=0; j<5; j++)
	{ 
		for (int i=0; i<5; i++)
		{
		kernel[5*j+i] = 1;
		}
	}
	
	//Now we apply the filter with the kernel. Note that normalizer = 9
	
	Image filtered = imagen.filter(kernel, 5, 25);
	
	filtered.save("parrot.ppm");

}
