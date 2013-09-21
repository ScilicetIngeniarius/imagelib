#include "../include/image.hh"


int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	int kernel [3][3];
	
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			kernel[i][j] = 0;
		}
	}
	 
	Image filtered ("../../Multimedia/lena.pgm");
	filtered = imagen.filter(kernel, 1);
	
	filtered.save("negro_filtro.pgm");

}
