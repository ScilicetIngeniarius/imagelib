#include "../src/image.cpp"
#include <iostream>

int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	cout << "El valor del width " << imagen.get_width() << endl; 
	
	cout << "\n El valor del height " << imagen.get_height() << endl; 
	
	cout << "\n El valor del spectrum " << imagen.get_spectrum() << endl; 
	
	cout << "\n El valor del depth " << imagen.get_depth() << endl; 
	
	*T=imagen->Img->data()
	
	cout<< "\n Vamos a ver que sale" << *T << endl;
	
}
