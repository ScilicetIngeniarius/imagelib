#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	//This function invert an image.
	Image inv = img1.inverse();
	inv.save("parrot_inverted.ppm");
	
}
