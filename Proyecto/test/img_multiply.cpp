# include "../include/image.hh"
int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	//This function multiplies an image by a factor.
	Image mult = img1.multiply_img(5);
	mult.save("parrot_multiplied.ppm");
	
}
