#include "../include/image.hh" //include the header image.hh located in include directory
#include <iostream>

using namespace std;

int main()
{
	// Call to a constructor of the class Image by giving it the name of the picture file.
	
	Image lena ("../../Multimedia/tutorials/lena.jpg"); // Image "__name__" ("__image_path__");

	lena.display("Lena Original"); //display("title") the image in a window, with the title.
		
	//Dot to dot transformations
	
	Image lena_inverted (256, 256, 1, 1, 168); // Image "__name__" (width, height, depth, spectrum, value);
	// Create an image with width=256 , height=256, depth=1, spectrum = 3 and all the pixel values set in 168.

	//inverse() Returns the inverse image (Set all pixels at the substraction of the max value with the original pixel value).
	
	lena_inverted= lena.inverse();
	
	//Save the result.
	lena_inverted.save("lena_inverse.jpg");
	
	  
	lena_inverted.display("lena inverted");
	
	Image lena_dilatated (256, 256, 1, 1, 168);
	
	//filter_dynamic_range_dilatation(unsigned char a,unsigned char b,double alpha,double beta,double gamma), divides the intensity values in 3 ranges and apply a diferent transformation to each.
	
	lena_dilatated= lena.filter_dynamic_range_dilatation(50,150,1,0.5,1.1); //alpha, beta and gamma are the factors to transform the pixel values.
	lena_dilatated.display("lena_dilatated");
	lena_dilatated.save("lena dilatated.jpg");
	
	Image lena_log (256, 256, 1, 1, 168);
	
	//log_transformation(), executes this transformation: v(x,y,z,c) = c log(u(x,y,z,c)+1)
	
	lena_log=lena.log_transformation();
	lena_log.display("lena log");
	lena_log.save("lena_log.jpg");
	
	Image lena_power (256, 256, 1, 1, 168);
	
	//Image power_law_transformatiom(double exponent), transform the pixel values in the form v(x,y,z,c)=k*(u(x,y,z,c))^gamma.
	
	lena_power=lena.power_law_transformatiom(1.1);
	lena_power.display("lena_power");
	lena_power.save("lena_power_law.jpg");
	
	Image lena_color_slicing (256, 256, 1, 1, 168);
	
	//Image color_slicing (unsigned char color1[], unsigned char color2[], unsigned char neutral[]), highlights the desired colors, between the two colors given as parameters.
	unsigned char color1[]={23};
	unsigned char color2[]={130};
	unsigned char neutral[]={50};
	lena_color_slicing=lena.color_slicing(color1,color2,neutral);
	lena_color_slicing.display("Lena Color Slicing");
	lena_color_slicing.save("lena_color_slicing.jpg");
}
