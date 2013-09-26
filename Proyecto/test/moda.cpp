
#include "../include/image.hh"
#include "iostream"

using namespace std;

int main()
{
	
	Image imagen ("../../Multimedia/lena.pgm");
	Image filtered = imagen.filter_modal(3);
	filtered.save("modal_lena.ppm");
}
