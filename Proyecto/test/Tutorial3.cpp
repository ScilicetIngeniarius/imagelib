#include "../include/image.hh" //include the header image.hh located in include directory
#include <iostream>

using namespace std;

int main()
{
	// Call to a constructor of the class Image by giving it the name of the picture file.
	
	Image image ("../../Multimedia/lena.pgm"); // Image "__name__" ("__image_path__");

	// Create an image with width=256 , height=256, depth=1, spectrum = 3 and all the pixel values set in 168.

	Image image_inverted (256, 256, 1, 3, 168); // Image "__name__" (width, height, depth, spectrum, value);

	Image image_dilatated (256, 256, 1, 3, 168);
	
	Image image_power (256, 256, 1, 3, 168);
	
	Image image_log (256, 256, 1, 3, 168);
	
	Image image_color_slicing (256, 256, 1, 3, 168);
	//Dot to dot transformations
	
	//inverse() Returns the inverse image (Set all pixels at the substraction of the max value with the original pixel value).
	
	image_inverted= image.inverse();
	
	//Save the result.
	image_inverted.save("lena_inverse.pgm");
	
	//display("title") the result in a window, with the title.  
	image_inverted.display("lena inverted");
	
	//filter_dynamic_range_dilatation(unsigned char a,unsigned char b,double alpha,double beta,double gamma), divides the intensity values in 3 ranges and apply a diferent transformation to each.
	
	image_dilatated= image.filter_dynamic_range_dilatation(50,150,1,0.5,1.1); //alpha, beta and gamma are the factors to transform the pixel values.
	image_dilatated.display("lena_dilatated");
	image_dilatated.save("lena dilatated.pgm");
	
	
	//log_transformation(), executes this transformation: v(x,y,z,c) = c log(u(x,y,z,c)+1)
	
	image_log=image.log_transformation();
	image_log.display("lena log");
	image_log.save("lena_log.pgm");
	
	//Image power_law_transformatiom(double exponent), transform the pixel values in the form v(x,y,z,c)=k*(u(x,y,z,c))^gamma.
	
	image_power.power_law_transformatiom(0.5);
	image_power.display("lena_power");
	image_power.save("lena_power_law.pgm");
	
	//Image color_slicing (unsigned char color1[], unsigned char color2[], unsigned char neutral[]), highlights the desired colors, between the two colors given as parameters.
	unsigned char color1[]={23,87,222};
	unsigned char color2[]={84,5,130};
	unsigned char neutral[]={7,7,6};
	image_color_slicing=image.color_slicing(color1,color2,neutral);
	image_color_slicing.display("Lena Color Slicing");
	image_color_slicing.save("lena_color_slicing.pgm");
}
