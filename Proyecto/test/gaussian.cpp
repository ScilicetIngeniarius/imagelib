#include "../include/image.hh"
#include "iostream"

using namespace std;

int main()
{
/*	int o=1;
	int dim=3;
	double kernel[dim*dim];
	
	int m = (dim-1)/2;
	
	double gaussian =1/pow(3.1415*2*o,0.5);
	//cout<< gaussian<<endl;

	for(int i =-m; i <=m; i++)
	{
		for(int j =-m; j<=+m; j++)
		{
			double exp= -(i*i+j*j)*0.5/o;
			kernel[(i+m)*dim + (j+m)]=gaussian*pow(2.7,exp); 
			cout<<"exp : " << exp<< endl;
			cout<< kernel[(i+m)*dim + (j+m)]<<endl;
		}
	}
*/	
	Image imagen ("../../Multimedia/taj_orig.jpg");
	Image filtered = imagen.filter_gaussian(1,3);
	filtered.save("gaussian_taj.ppm");
}
