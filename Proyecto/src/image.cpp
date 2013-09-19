#include "../include/image.hh"

/**\file ../include/image.hh
 * Header for the image class
 */
 
 /** \fn Image::Image()
 * \brief Constructor
 * This constructor initializes the four dimension params at 0;
 * The \param Img calls the constructor of CImg to create an empty image.
 */
Image::Image()
{
	this->Img = new CImg<unsigned char>();
	this->width = 0;
	this->height = 0;
	this->depth = 0;
	this->spectrum = 0;
}
/** \fn Image::Image(const char *const filename)
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


/*
 * Filter Function
 * ///Esta función recorre toda la matriz con un kernel de dimensión desconocida y aplica una función cualquiera a los píxeles de la imagen cuando el kernel esta encima de ellos, el kernel va recorriendo toda la imagen haciendo esto.
 * void Filter (int [] kernel)
 * {
	 * // K = 2m+1;
	 * int k = matriz.width();
	 * int m = (k-1)/2
	 * 
	 * ///Se define la matriz de números (Para extraer los valores de unsigned char)
	 * ///Se definen las dimensiones de la 
	 * unsigned char matrix [this->spectrum()] [this->depth()] [this->width()] [this->height()];
	 * 
	 * 
	 * for(int c = 0; c < this->depth(); c++)
	 * {
		 * for(int z = 0; z < this->spectrum(); z++)
		 * {
			 * for(int x = 0; x < this->width(); x++)
			 * {
				 * for(int y = 0; y < this->height(); y++)
				 * {
				 *  ///Se recorre la matriz en sus 4 dimensiones, con 4 ciclos, luego se debe recorrer el Kernel con otros 2 ciclos.
					 * //HASTA AQUI, SOLO RECORRO TODA LA IMAGEN; FALTA EL KERNEL
					 * 
					 * int sum = 0;
					 * 
					 * //Para el kernel:
					 * for(int i = x-m; i <= x+1; i++)
					 * {
						 * for(int j = y-m; j<= j+1; j++)
						 * {
							 * sum += this->Img->getMatrix...;
						 * }
					 * }
					 * 
					 * this->Img->setpixel(x,y,z,c, sum/(K*k))
				 * }
			 * }
		 * }
	 * }  
 * }
 * 
*/
