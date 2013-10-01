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

Image Image ::filter_freeman_0()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1,y,z,c))-1*(get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_1()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1,y,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y+1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_2()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1,y+1,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_3()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1,y+1,z,c))-1*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x-1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_4()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c))-1*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_5()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c))-1*(get_pixel_value(x+1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1,y-1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_6()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x, y-1, z, c))-1*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1,y+1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}

Image Image ::filter_freeman_7()
{
	Image filtered (this->get_width() , this->get_height(), this->get_depth(), this->get_spectrum(), 0); /// 
	
	int m = 1;
	
	for(unsigned int c = 0; c < this->get_spectrum(); c++)
	{
		for(unsigned int z = 0; z < this->get_depth(); z++)
		{
			for(unsigned int x = m; x < this->get_width()-m; x++)
			{
				for(unsigned int y = m; y < this->get_height()-m; y++)
				{
					int sum = (get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x, y-1, z, c))-1*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1,y+1,z,c))+-2*get_pixel_value(x, y, z, c);
					if (sum > 255 || sum < -255)
					{
						sum = 255;
					}
					unsigned char pixel = (unsigned char)static_cast<unsigned char> (abs(sum));
					filtered.set_pixel_value(x, y, z, c, pixel);
				}
				
			 }
			 
		 }
	}  
	
	return filtered;
	
}
