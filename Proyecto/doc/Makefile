all: doxygen pdf 

pdf: refman.pdf Propuesta.pdf

Propuesta.pdf : Propuesta.tex
	pdflatex Propuesta.tex
	make clean

doxygen: Imagelib.doxygen
	doxygen Imagelib.doxygen
	make -C ./doxygen/ all

clean:
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl
