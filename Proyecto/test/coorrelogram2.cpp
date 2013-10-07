#include "../include/image.hh"
#include <iostream>
using namespace std;
int main()
{
	Image parrot ("../../Multimedia/parrot_original.ppm");
	//This function could take between 30 mins and 1 hour
	Image coorrel=parrot.coorrelogram_ZC(1,0,1,1);
	Image coor=coorrel.interpolation().interpolation();
	coor.display("coorrel.jpg");
	
	coor.save("coorrelograma2.jpg");
}


