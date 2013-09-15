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
	
	cout << "\n Vector at  " << imagen.get_vector_at(5, 5, 1) << endl;
}
