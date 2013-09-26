#include "../include/image.hh"
#include "math.h"
#include "iostream"

using namespace std;

int main()
{
	int o=1;
	int dim=3;
	double kernel[dim*dim];
	
	int m = (dim-1)/2;
	
	double gaussian =1/(3.1415*2*o);
	//cout<< gaussian<<endl;
	double G;

	for(int i =-m; i <=m; i++)
						{
							for(int j =-m; j<=+m; j++)
							{
								double exp= -(j*j+i*i)/(2*(o*o));
								kernel[(i+m)*dim + (j+m)]=gaussian*pow(2.7,exp); 
								cout<<"exp : " << exp<< endl;
								cout<< kernel[(i+m)*dim + (j+m)]<<endl;
							}
						}
						
/*	for (int j=0; j<dim*dim; j++)
	{ 
		cout<< kernel[j]<<endl;
	
	}
*/

}
