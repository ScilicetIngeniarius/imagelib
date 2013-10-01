#include "../include/image.hh"

int main()
{
	Image img1 ("../../Multimedia/parrot_original.ppm");
	img1.display("img");
	Image freeman0 = img1.filter_freeman_0();
	freeman0.display("freeman0");
	Image freeman1 = img1.filter_freeman_1();
	freeman1.display("freeman1");
	Image freeman2 = img1.filter_freeman_2();
	freeman2.display("freeman2");
	Image freeman3 = img1.filter_freeman_3();
	freeman3.display("freeman3");
	Image freeman4 = img1.filter_freeman_4();
	freeman4.display("freeman4");
	Image freeman5 = img1.filter_freeman_5();
	freeman5.display("freeman5");
	Image freeman6 = img1.filter_freeman_6();
	freeman6.display("freeman6");
	Image freeman7 = img1.filter_freeman_7();
	freeman7.display("freeman7");
	
}


