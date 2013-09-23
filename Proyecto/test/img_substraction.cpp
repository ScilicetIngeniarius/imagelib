#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	Image img2 ("parrot.ppm");
	
	Image sub = img1.substract_img(img2);
	sub.save("parrot_substracted.ppm");
	
}
