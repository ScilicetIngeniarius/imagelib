# include "../include/image.hh"

int main ()
{
	Image parrot ("../../Multimedia/parrot_original.ppm");
	
	Image parrot_max = parrot.filter_maximum();
	
	parrot_max.display("");
	
	Image parrot_min = parrot.filter_minimum();
	
	parrot_min.display("");


}
