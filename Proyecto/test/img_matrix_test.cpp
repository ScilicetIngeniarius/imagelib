#include "../include/image.hh"
#include <stdio>

int main()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	cout << "El valor de el pixel " << imagen.get_vector_at(5, 5, 0)[0] << endl;
	 
}
