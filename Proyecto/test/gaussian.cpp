#include "../include/image.hh"
#include "iostream"

using namespace std;

int main()
{
	Image imagen ("../../Multimedia/salt.gif");
	Image filtered = imagen.filter_gaussian(1,3);
	filtered.save("gaussian.ppm");
}
