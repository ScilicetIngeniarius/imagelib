# include "../include/image.hh"

int main ()
{
	Image polar ("../../Multimedia/parrot_prewitt_borders.ppm");
	
	polar.display("");
	
	polar.plot_histogram(256, "");
	
	
}
