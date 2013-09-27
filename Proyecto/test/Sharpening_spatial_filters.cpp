#include "../include/image.hh"
#include <iostream>

int main()
{
	//Image parrot_substracted ("parrot_substracted.ppm");

	Image parrot ("../../Multimedia/parrot_original.ppm");
	
	Image lena ("../../Multimedia/lena_colored.jpg");
	
	//Image Hello ("../../Multimedia/HelloWorld.jpeg");
	
	//Image woods ("../../Multimedia/woods.jpg");
	
	//Image milla ("../../Multimedia/milla.bmp");
	
	//Image taj ("../../Multimedia/taj_orig.jpg");
	
	Image vert = parrot.filter_Gradient_vertical();
	
	vert.display("VERT GRAD");
	
	Image vert2 = parrot.filter_Prewitt_N_S();
	
	vert2.display("OTHER GRAD");
	
	//sum.save("../../Multimedia/lena_bord.ppm");
	
}
