# include "../include/image.hh"
int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	//This function binarize an image.
	Image bin = img1.binarize_img(120);
	bin.save("parrot_binarized.ppm");
	
}

