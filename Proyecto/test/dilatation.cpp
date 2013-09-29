#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	Image dilatated = img1.filter_dynamic_range_dilatation(50,150,0.5,1.1,0.1);
	dilatated.display("dilatated");
	
}


