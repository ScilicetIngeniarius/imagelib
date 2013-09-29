# include "../include/image.hh"

int main ()
{
	Image imagen ("../../Multimedia/lena.pgm");
	
	imagen.FFT();
	
	imagen.display_FFT();
	
	imagen.FFT_inverse();
	
	imagen.display("NORMAL");
	
}
