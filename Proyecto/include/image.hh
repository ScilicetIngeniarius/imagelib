#include "../include/CImg.h"
#include <string>

/**\brief image.hh implements a wrapper over the library CImg.
 * For more information go to cimg.sourceforge.net
 */ 

using namespace cimg_library;
using namespace std;

#ifndef IMAGE_CLASS
#define IMAGE_CLASS

class Image
/**\brief The Image class is the 
 */
{
private:
	///Primero se declaran las variables de la clase como privadas
	CImg<unsigned char> *Img;
	///La variable *Img es un puntero a la imagen del tipo CImg y en CImg se trata esta como un unsigned char.
	unsigned int width;
	unsigned int height;
	unsigned int depth;
	unsigned int spectrum;
	///Las variables width, height, depth y spectrum se refieren a las dimensiones y se tratan como unsigned int
	
public:
	///Luego se declaran las funciones de la clase como publicas
	Image ();
	///Image() es el primer constructor de la clase que no recibe parámetros.
	Image (const char *const filename);
	///Image (const char *const filename) es el constructor de la clase que recibe solo *filename
	Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value);
	///Image (const unsigned int width, const unsigned int height, const unsigned int depth, const unsigned int spectrum, int value)
	///Es el constructor que recibe las dimensiones de la imagen(width, height, depth, spectrum) y un int value QUE NO SE QUE ES.
	~Image(void);
	///~Image(void) es el destructor de la clase
	unsigned int get_width();///get_width permite obtener el ancho de la imagen
	unsigned int get_height();///get_height permite obtener el alto de la imagen
	unsigned int get_depth();///get_depth permite obtener el número de capas de color que tiene la imagen
	unsigned int get_spectrum();///get_spectrum permite obtener spectrum(NO SE)
	
	void save(const char *const savefilename);
	///save(const char *const savefilename) permite salvar una imagen con el nombre de "savefilename"
	
};

#endif
