#include "../include/image.hh" //include the header image.hh located in include directory
#include <iostream>

using namespace std;

int main(){

	// Call to a constructor of the class Image by giving it the name of the picture file.
	
	Image imagen ("../../Multimedia/lena.pgm"); // Image "__name__" ("__image_path__");

	// Create an image with width=256 , height=256, depth=1, spectrum = 3 and all the pixel values set in 168.

	Image image_created (256, 256, 1, 3, 168); // Image "__name__" (width, height, depth, spectrum, value);


	//Gets
	
	// get_width() allows to obtain the width of the image.
	cout<<"Image width: "<<image_created.get_width()<<endl; //"__Image_object__".get_width();
	
	//get_height allows to obtain the height of the image.
	cout<<"Image height: "<<image_created.get_height()<<endl; //"__Image_object__".get_height();
	
	//get_depth allows to obtain the depth of the image.
	cout<<"Image depth: "<<image_created.get_depth()<<endl; //"__Image_object__".get_depth();
	
	//get_spectrum allows to obtain the specrum of the image.
	cout<<"Image spectrum: "<<image_created.get_spectrum()<<endl; //"__Image_object__".get_spectrum();
	
	//get_pixel_value returns the unsigned char value of the pixel in the given coordinates.
	cout<<"Pixel value: "<< static_cast<unsigned>(image_created.get_pixel_value(100, 150, 1, 1))<<std::endl; //"__Image_object__".get_pixel_value(x,y,z,c);

	//Set
	for(int i=0;i<100;i++)
	{
	image_created.set_pixel_value(i, i, 1, 1, 0); //"__Image_object__".set_pixel_value(x,y,z,c,pixel value);
	}
	//Save the image
	image_created.save("image_created.ext"); // "__Image_object__".save("__picture_name");


}

//include
//abrir imagen
//sets gets
//salvar img
