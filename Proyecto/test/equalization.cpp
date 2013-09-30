#include "../include/image.hh"
#include "math.h"
#include "stdio.h"

int main()
{
	Image img1 ("../../Multimedia/lena.pgm");
	int* hist=img1.get_histogram(1,3);
	img1.plot_histogram("histogram");
	histogram_equalization(hist).plot_histogram("equalizated");
	
}

int* Image :: histogram_equalization(int* histogram_pointer)
{
	int equal_histogram [256];
	
	int pixel_value_max =255;
	double A =  this->get_height()*this->get_width() / pixel_value_max;
	for(int i = 0; i<256; i++)
	{
	equal_histogram[i] = 0;	
	}
	
	for(int j = 0; j < 256 ; j++)
	{
		if(j>=1)
		{
			for(int k=0; k<j-1; k++)
			equal_histogram[j]+= (histogram_pointer[k]+ (histogram_pointer[j]/2))/A;
		}
		
	}
	int* eq_hist_ptr= equal_histogram;
	return eq_hist_ptr;
}

