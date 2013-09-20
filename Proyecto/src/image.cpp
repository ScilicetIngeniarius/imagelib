#include "../include/image.hh"

/**\file ../include/image.hh
 * Header for the image class
 */

/*! \fn Image::Image(const char *const filename)
 * \brief Constructor
 * 
 * This constructor is used when the image already exist's and is stored in the \param filename path.
 */

Image::Image(const char *const filename)
{
	///Este es el constructor de la clase en donde solamente se conoce la variable filename(NO ESTOY SEGURO DE QUE ES!!)
	this->Img = new CImg<unsigned char>(filename);
	///La variable Img es del tipo CImg y se trata como un unsigned char.
	this->width = this->Img->width();
	///width se refiere al ancho de la imagen.
	this->height = this->Img->height();
	///height se refiere al alto de la imagen.
	this->depth = this->Img->depth();
	///depth se refiere a la cantidad de capas que tenga la imagen
	this->spectrum = this->Img->spectrum();
	///NO SE QUE ES SPECTRUM
	
	this->update_matrix();
	
}

Image::Image()
{
	///Este es el constructor de la clase que inicializa las variables en 0.
	///En el caso de Img se llama al constructor de CImg que inicialice la imagen como vacía.
	this->Img = new CImg<unsigned char>();
	this->width = 0;
	this->height = 0;
	this->depth = 0;
	this->spectrum = 0;
	
	this->update_matrix();
}

Image::Image(const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
{
	///Este es el constructor de la imagen para el caso en el que le pasen los parámetros de la imagen.
	this->Img = new CImg<unsigned char>(width, height, depth, spectrum, value);
	///Llama al constrcutor de CImg donde se le dan los valores de width, height, depth, spectrum, y value (NO SE QUE ES VALUE)
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->spectrum = spectrum;
	
	this->update_matrix();
}

Image::~Image(void)
{
	///~Image(void) es el destructor de la clase
}


unsigned int Image:: get_width()
{
	///get_width retorna un puntero entero con el ancho de la imagen
	return this->width;
}

unsigned int Image:: get_height()
{
	///get_height retorna un puntero entero con el alto de la imagen
	return this->height;
}

unsigned int Image:: get_depth()
{
	///get_depth retorna un puntero entero con el número de capas o canales de la imagen
	return this->depth;
}

unsigned int Image:: get_spectrum()
{
	///get_spectrum retorna un puntero entero con spectrum (NO SE)
	return this->spectrum;
}

void Image:: save(const char *const savefilename)
{
	///save permite salvar un archivo con la imagen con la que se está trabajando.
	this->Img->save(savefilename);
}

unsigned int Image:: get_pixel_value(int x, int y, int z, int c)
{
	return this->Img->get_vector_at(x, y, z)[c];
}

/*! \fn Image Image :: filter (int [] *kernel )
 * \brief This function aplies a space domain filter, its a general function, and each filter will
 * depend on the \param kernel matrix, wich provides the respective weights to the surroundings.
 * \param int [] *kernel: Must ve a square matrix, of anm uneven dimention, because the center value
 * must be the (x,y) value.
 * \param int dim: Is the dimention of the square matrix. 
 * \param float normalizer: Is a value in order to avoid the loss of information and normalize the output of the sum of the values of the pixel in the
 * neighborhood with the weight values of the kernel. 
 */

Image Image :: filter (int [] *kernel, int dim, float normalizer)
{
	Image filtered (this->get_width() , this->get_height(), this->depth(), this->spectrum(), int value);
	int m = (dim-1)/2;
	
	for(int z = 0; c < this->depth(); c++)
	{
		for(int c = 0; z < this->spectrum(); z++)
		{
			for(int x = 0; x < this->width(); x++)
			{
				for(int y = 0; y < this->height(); y++)
				{
					///A variable to sum the values of the kernes with the heights.
					int sum = 0;
					
					///Two loops for the kernel:
					for(int i = x-m; i <= x+1; i++)
					{
						for(int j = y-m; j<= j+1; j++)
						{
							sum += this->get_pixel_value(i, j, z, c) * (*kernel[i][j]); 
						}
					}
					 
					unsigned int pixel_value = sum * normalizer;
				 }
			 }
		 }
	 }  
 }


