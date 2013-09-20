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
	for (int i=0; i<100; i++)
	{
	unsigned char a = imagen.get_vector_at(i, 0, 0) [0];
	cout << "\n Vector at  " << static_cast<unsigned>(a);
	}
}

