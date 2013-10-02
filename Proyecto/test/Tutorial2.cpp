# include "../include/image.hh"

int main ()
{
	//First we construct an image from a file.
	Image parrot ("../../Multimedia/parrot_original.ppm");
		
	//Here is the image by itself. We can display it like this:
	
	parrot.display("Parrot Original");
	
	parrot.save("../../Multimedia/parrot_original.jpg");
	
	//We can apply several filters to an image. A filter returns a Image object with the
	//corresponding filter applied to the image.

	//For example, applying an average filter to the parrot image (it receives a int that
	//corresponds to the intensity of the average filter. In this case its a 4):
	
	Image smoothed_parrot = parrot.filter_average(4);
	
	//We display it:
	smoothed_parrot.display("Smoothed Parrot");
	
	///////////
	smoothed_parrot.save("../../Multimedia/tutorials/smoothed_parrot.jpg");
	
	//We can also apply a filter, and display it without storing it in a Image object. like this:
	
	(parrot.filter_gaussian(3,3)).display("Gaussian");
	
	//We can also just save the image, without storing it in an Image object like this:
	(parrot.filter_median(0)).save("../../Multimedia/Parrot_median.jpg");
	
	/*The filters that we have applied are smoothing filters, that as you can see dont modify 
	 * the images alot, just, as the name says, smooth it.  Now we will apply some sharpening
	 * filters that enhance some details in the image, for example borders and noise.
	*/
	
	//We can enhance edges, by displacement. The parameters of this function are the 
	//horizontal, and vertical displacement in pixels.
	
	Image displaced = parrot.filter_edge_enhacement_displacement(1,1);
	
	//We display it
	displaced.display("Displaced");
	
	////
	displaced.save("../../Multimedia/tutorials/parrot_displaced.jpg");
	
	//We can add noise to the image
	parrot.gaussian_noise(2);
	
	//And apply a Laplacian filter, that acts as a sharpening filter.
	Image filtered = parrot.filter_Laplacian();
	
	filtered.display("Laplacian");
	
	filtered.save("../../Multimedia/tutorials/parrot_laplace.jpg");
	
	//We can overwrite an Image objec with another, in this case with a 
	// horizontal borders enhance filter:
	filtered = parrot.filter_horizontal_borders();
	
	filtered.display("Horizontal Borders");
	
	
	displaced.save("../../Multimedia/tutorials/parrot_hor_Bord.jpg");
}
