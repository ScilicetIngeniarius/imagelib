#include "../include/image.hh"


int main()
{
	Image img ("../../Multimedia/lena.pgm");
	Image img2 ("../../Multimedia/parrot_original.ppm");
	
	img.display("lena");
	Image img1=img.interpolation();
	img1.display("lena_inter");
	img2.display("parrot");
	Image img22=img2.interpolation();
	img22.display("parrot_inter");
}


