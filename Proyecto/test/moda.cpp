
#include "../include/image.hh"
#include "iostream"

using namespace std;

int main()
{
	
	Image imagen ("../../Multimedia/parrot_original.ppm");
	Image filtered = imagen.filter_modal(3);
	filtered.save("modal_parrot.ppm");
}
