#include "../include/image.hh"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	Image img ("../../Multimedia/lena.pgm");
	img.gaussian_noise(0.5);
	img.display("Gaussian noise");
	
	
	
}

void Image :: gaussian_noise(int intensity)
{
	srand(1);
	double porcentage = 1-intensity/100;

	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = 0; x < this->get_width(); x++)
			{
				for(unsigned int y = 0; y < this->get_height(); y++)
				{
					double random= 2.0*(rand()-RAND_MAX/2.0)/RAND_MAX;
					if(random > porcentage)
					{
						(*(this->Img))(x, y, z, c)= 255;
					}	

					else if(random<-porcentage)
					{
						(*(this->Img))(x, y, z, c)= 0;					
					}
				}
				
				
			 }
			 
		 }
	}  
	 
}
