#include "../include/image.hh"


int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");

	
	Image filtered = imagen.filter_median(3);
	
	filtered.save("filter_median.ppm");

}
