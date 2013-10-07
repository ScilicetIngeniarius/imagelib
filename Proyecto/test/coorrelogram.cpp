#include "../include/image.hh"
#include <iostream>
using namespace std;
int main()
{
	Image lena ("../../Multimedia/lena.pgm");
	//This function could take between 30 mins and 1 hour
	Image coorrel=lena.coorrelogram(1,0);
	Image coor=coorrel.interpolation();
	coor.display("coorrel.jpg");
	
	coor.save("coorrelograma.jpg");
}



