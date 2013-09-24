#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	Image img2 ("parrot.ppm");
	//This function can substract two images of the same dimensions, to see the diferences between both.
	Image sub = img1.substract_img(img2);
	sub.save("parrot_substracted.ppm");
	
}
