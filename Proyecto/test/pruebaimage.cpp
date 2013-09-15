#include  "../include/CImg.h"

using namespace cimg_library;

int main(int argc, char **argv)
{
	CImg<unsigned char> img(300,200,1,3);
	img.fill(32);
	img.noise(10);
	//img.blur(2,0,0);
	const unsigned char white[] = {255,255,255};
	img.draw_text(80,80,"HELLO WORLD", white,0,200);
	img.get_crop(70,70,128,128);
	img.display();
	img.save("helloworld.jpeg");
	return 0;	
}
