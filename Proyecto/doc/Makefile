all: doxygen pdf doc latex

pdf: Propuesta.pdf

Propuesta.pdf : Propuesta.tex
	echo "******************* PROPUESTA PDF **************************************";\
	pdflatex Propuesta.tex
	make clean

doxygen: Imagelib.doxygen
	echo "******************* CREATING DOXYGEN OUTPUT ****************************";\
	doxygen Imagelib.doxygen

doc: 
	make -C ./doxygen/ all

latex:
	echo "******************* PRODUCING DOXYGEN LATEX OUTPUT *********************";\
	make -C doxygen/latex/ all

clean:
	echo "******************* CLEANING *******************************************"
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl
	make -C doxygen/latex/ clean

