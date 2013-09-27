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
	
	//PREWIT
	//N_S
	
	(parrot.filter_Prewitt_N_S()).display("N_S");
	
	//E_W
	
	(parrot.filter_Prewitt_E_W()).display("E_W");
	
	//NE_SW
	
	(parrot.filter_Prewitt_NE_SW()).display("N_S");
	
	//NW_SE
	
	(parrot.filter_Prewitt_NW_SE()).display("N_S");
	
	//FOR THE SUM OF THEM ALL
	
	Image sum = ((parrot.filter_Prewitt_N_S()).sum_img(parrot.filter_Prewitt_E_W())).sum_img((parrot.filter_Prewitt_NE_SW()).sum_img(parrot.filter_Prewitt_NW_SE()));
	
	sum.display("SUM");
	
	sum.save("../../parrot_prewitt_borders.ppm");
	
	
	
}
