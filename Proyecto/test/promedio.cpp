#include "../include/image.hh"

int main()
{
	Image imagen ("../../Multimedia/parrot_original.ppm");

	Image filtered = imagen.filter_average(10);
	
	filtered.display("FUNCTION_10");
	
	filtered = imagen.filter_average(20);
	
	filtered.display("FUNCTION_20");
	
	filtered = filtered.filter_average(20);
	
	filtered.display("FUNC 20 + 20");

}
