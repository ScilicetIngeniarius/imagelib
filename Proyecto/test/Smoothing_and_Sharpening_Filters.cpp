# include "../include/image.hh"

int main ()
{
	Image parrot ("../../Multimedia/parrot_original.ppm");
	
	//Some smoothing filters
	
	Image smoothed = (parrot.filter_average(4));
	
	smoothed.display("Smoothed Parrot");
	
	smoothed.save("../../Multimedia/tutorials/smoothed_parrot.jpg");
	
	(parrot.filter_gaussian(3,3)).display("Gaussian");
	
	(parrot.filter_median(0)).display("Median");
	
	//Some Sharpening filters
	
	Image displaced = parrot.filter_edge_enhacement_displacement(1,1);
	
	displaced.display("Displaced");
	
	displaced.save("../../Multimedia/tutorials/parrot_displaced.jpg");
	
	displaced = parrot.filter_Laplacian();
	
	displaced.display("Laplacian");
	
	displaced.save("../../Multimedia/tutorials/parrot_laplace.jpg");
	
	displaced = parrot.filter_horizontal_borders();
	
	displaced.display("Displaced");
	
	displaced.save("../../Multimedia/tutorials/parrot_hor_Bord.jpg");
}
