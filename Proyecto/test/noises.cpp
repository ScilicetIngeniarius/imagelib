#include "../include/image.hh"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include "math.h"

using namespace std;

int main()
{
	Image img ("../../Multimedia/lena.pgm");
	Image img2 ("../../Multimedia/parrot_original.ppm");
	
	img.salt_pepper(5);
	img.display("Salt&Pepper noise");
	img2.gaussian_noise(50);
	img2.display("Gaussian noise");
}




