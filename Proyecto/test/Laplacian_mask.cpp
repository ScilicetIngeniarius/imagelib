#include "../include/image.hh"
#include <iostream>

int main()
{
	Image imagen ("parrot_substracted.ppm");
	
	//Now we apply the filter with the kernel. Note that normalizer =
	
	Image filtered = imagen.filter_Laplacian();
	
	filtered.save("laplacian2.ppm");
	
	
	
	int kernel[9] = {0, -1, 0, -1, 4, -1, 0, -1, 0};
	
	Image filt = imagen.filter(kernel, 3, 4);
	
	filt.save("no_diagonal.ppm");
	
}
