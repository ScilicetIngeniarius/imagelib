#include "../include/image.hh"
#include <iostream>
using namespace std;

int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	cout << "El valor del width " << imagen.get_width() << endl; 
	
	cout << "\n El valor del height " << imagen.get_height() << endl; 
	
	cout << "\n El valor del spectrum " << imagen.get_spectrum() << endl; 
	
	cout << "\n El valor del depth " << imagen(10,10, 0) << endl;
	
	imagen.save("../../Multimedia/lena2.pgm");
	
}
