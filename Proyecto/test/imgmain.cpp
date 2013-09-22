#include "../include/CImg.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

int main()
{
	CImg <unsigned char> imagen ("../../Multimedia/parrot_original.ppm");
	
	cout << "El valor del width " << imagen.width() << endl; 
	
	cout << "\n El valor del height " << imagen.height() << endl; 
	
	cout << "\n El valor del spectrum " << imagen.spectrum() << endl; 
	
	cout << "\n El valor del depth " << imagen.depth() << endl; 
	
	for (int i=0; i<5; i++)
	{
	unsigned char a = imagen.get_vector_at(i, 0, 0) [0];
	cout << "\n Vector at  " << static_cast<unsigned>(a);
	}
	
	
	for (int c=0; c<imagen.spectrum(); c++)
	{
		for (int j=0; j<imagen.width(); j++)
		{ 
			for (int i=0; i<imagen.height(); i++)
			{
				imagen(j, i, 0, c) = 225;
			}
		}
	}
	imagen.save("negro_parrot.pgm");
	
	for (int i=0; i<5; i++)
	{
	unsigned char a = imagen.get_vector_at(i, 0, 0) [0];
	cout << "\n Modified vector  " << static_cast<unsigned>(a); 
	}
}

