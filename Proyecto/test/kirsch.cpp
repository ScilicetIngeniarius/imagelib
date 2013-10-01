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

Image Image ::filter_kirsch_0()
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
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c));
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

Image Image ::filter_kirsch_45()
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
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x, y-1, z, c));
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

Image Image ::filter_kirsch_90()
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
					int sum = -3*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c))+5*(get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x-1, y-1, z, c));
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

Image Image ::filter_kirsch_135()
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
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c)+get_pixel_value(x-1, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c));
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

Image Image ::filter_kirsch_180()
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
					int sum = -3*(get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x-1, y-1, z, c));
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

Image Image ::filter_kirsch_225()
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
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c)+get_pixel_value(x+1, y+1, z, c))+5*(get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x, y+1, z, c));
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

Image Image ::filter_kirsch_270()
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
					int sum = -3*(get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c)+get_pixel_value(x+1, y, z, c))+5*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x-1, y+1, z, c));
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


Image Image ::filter_kirsch_315()
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
					int sum = -3*(get_pixel_value(x-1, y+1, z, c)+get_pixel_value(x-1, y, z, c)+get_pixel_value(x-1, y-1, z, c)+get_pixel_value(x, y-1, z, c)+get_pixel_value(x+1, y-1, z, c))+5*(get_pixel_value(x, y+1, z, c)+get_pixel_value(x+1, y+1, z, c)+get_pixel_value(x+1, y, z, c));
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
