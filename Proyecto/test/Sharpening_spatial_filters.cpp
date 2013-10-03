#include "../include/image.hh"
#include <iostream>

int main()
{
	//Image parrot_substracted ("parrot_substracted.ppm");

	Image parrot ("../../Multimedia/parrot_original.ppm");
	
	Image lena ("../../Multimedia/lena_colored.jpg");
	
	//Image Hello ("../../Multimedia/HelloWorld.jpeg");
	
	//Image woods ("../../Multimedia/woods.jpg");
	
	Image logo ("../../Multimedia/logo.png");
	
	//Image taj ("../../Multimedia/taj_orig.jpg");
	
	Image filtered = parrot.log_transformation();
	
	(logo.filter_Laplacian()).display("Logo");
	
	(logo.filter_Laplacian_no_diagonal()).display("Logo ND");
	
	filtered.display("Log Transformation");
	
	filtered.plot_histogram("LOG PARROT");
	
	parrot.plot_histogram("PARROT");
	
	(parrot.filter_average(5)).plot_histogram("AVERAGE");
}
