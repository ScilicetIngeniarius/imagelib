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
	
	int spec=imagen.spectrum();
	
	for (int i=0; i<5; i++)
	{
	unsigned char a = imagen.get_vector_at(i, 0, 0) [1];
	cout << "\n Vector at  " << static_cast<unsigned>(a);
	}
	
	for (int j=0; j<imagen.width(); j++)
	{ 
		for (int i=0; i<imagen.height(); i++)
		{
			for (int k=0; k<imagen.spectrum(); k++)
			{
				
				unsigned char a [] = {0, 0, 0};
			
				CImg<unsigned char> kern (a, spec, spec, spec);
			
				imagen.set_vector_at(kern, j, i, k);
			}
		}
	}
	
	imagen.save("negro.pgm");
	
	
	for (int i=0; i<5; i++)
	{
	unsigned char a = imagen.get_vector_at(i, 0, 0) [1];
	cout << "\n Modified vector  " << static_cast<unsigned>(a)<<endl; 
	}
}

