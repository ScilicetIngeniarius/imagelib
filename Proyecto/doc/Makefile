all: doxygen pdf doc latex

pdf: Propuesta.pdf Usage.pdf Technical_Report.pdf Presentation.pdf

Technical_Report.pdf: Technical_Report.tex
	@echo "******************* TECHNICAL REPORT PDF **************************************";\
	pdflatex Technical_Report.tex
	pdflatex Technical_Report.tex
	make clean
	
Presentation.pdf: Presentation.tex
	pdflatex Presentation.tex
	pdflatex Presentation.tex

Propuesta.pdf : Propuesta.tex
	@echo "******************* PROPUESTA PDF **************************************";\
	pdflatex Propuesta.tex
	pdflatex Propuesta.tex
	make clean
	
Usage.pdf : Usage.tex
	@echo "******************* PROPUESTA PDF **************************************";\
	pdflatex Usage.tex
	pdflatex Usage.tex
	

doxygen: Imagelib.doxygen
	@echo "******************* CREATING DOXYGEN OUTPUT ****************************";\
	doxygen Imagelib.doxygen
	make latex

doc: 
	make -C ./doxygen/ all

latex:
	@echo "******************* PRODUCING DOXYGEN LATEX OUTPUT *********************";\
	make -C doxygen/latex/ all
	cp doxygen/latex/refman.pdf ./

clean:
	@echo "******************* CLEANING *******************************************"
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl *.snm *.nav *.info
	make -C doxygen/latex/ clean

.PHONY: all
