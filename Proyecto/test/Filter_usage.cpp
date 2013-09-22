#include "../include/image.hh"

int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");

	int kernel[5][5];
	
	for (int j=0; j<5; j++)
	{ 
		for (int i=0; i<5; i++)
		{
		kernel[i][j] = 1;
		}
	}
	
	//Now we apply the filter with the kernel. Note that normalizer = 9
	
	imagen = imagen.filter(kernel, 25);
	
	imagen.save("parrot_original_filtered.ppm");

}
