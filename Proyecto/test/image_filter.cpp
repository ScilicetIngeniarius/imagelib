#include "../include/image.hh"

int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	int kernel [3][3];
	int* k = *kernel;
	
	for (int i = 0; i<3; i++) 
	{
		for (int j = 0; j<3; j++)
		{
			kernel[i][j] = 0;
		}
	}
	float a = 0.;
	
	Image negro = imagen.filter(*k, 3, a);
	
	negro.save("../../Multimedia/negro.pgm");
}
