#include "../include/image.hh"
#include "math.h"
#include "stdio.h"


int main()
{
	Image img ("../../Multimedia/parrot_original.ppm");
	Image img_variance = img.variance(2);
	img_variance.display("variance");
}


