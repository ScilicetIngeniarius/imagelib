#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	img1.display("kirsch0");
	Image kirsch0 = img1.filter_kirsch_0();
	kirsch0.display("kirsch0");
	Image kirsch45 = img1.filter_kirsch_45();
	kirsch45.display("kirsch45");
	Image kirsch90 = img1.filter_kirsch_90();
	kirsch90.display("kirsch90");
	Image kirsch135 = img1.filter_kirsch_135();
	kirsch135.display("kirsch135");
	Image kirsch180 = img1.filter_kirsch_180();
	kirsch180.display("kirsch180");
	Image kirsch225 = img1.filter_kirsch_225();
	kirsch225.display("kirsch225");
	Image kirsch270 = img1.filter_kirsch_270();
	kirsch270.display("kirsch270");
	Image kirsch315 = img1.filter_kirsch_315();
	kirsch315.display("kirsch315");
	
}


