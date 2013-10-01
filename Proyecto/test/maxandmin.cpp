# include "../include/image.hh"

int main ()
{
	Image parrot ("../../Multimedia/parrot_original.ppm");
	
	Image parrot_max = parrot.filter_maximum();
	
	parrot_max.display("MAX");
	
	Image parrot_min = parrot.filter_minimum();
	
	parrot_min.display("MIN");
	
	Image power = parrot.power_law_transformatiom(2);
	
	power.display("POWER");
	
	unsigned char red1 [] = {150, 0 , 0};
	unsigned char red2 []= {255, 0, 0};
	unsigned char black []= {0, 0, 0};
	
	Image Slicing = parrot.color_slicing(red1, red2, black);
	
	Slicing.display("RED?");


}
