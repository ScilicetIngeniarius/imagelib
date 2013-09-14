#Variables
PDFLATEX = pdflatex
all: doxygen pdf

doxygen : Imagelib.doxygen
	doxygen Imagelib.doxygen	

pdf: refman.pdf Propuesta

refman.pdf: clean refman.tex
	pdflatex refman
	makeindex refman.idx
	pdflatex refman
	latex_count=5 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' refman.log && [ $$latex_count -gt 0 ] ;\
	    do \
	      echo "Rerunning latex...." ;\
	      pdflatex refman ;\
	      latex_count=`expr $$latex_count - 1` ;\
	    done

Propuesta : Propuesta.tex
	$(PDFLATEX) Propuesta.tex 

clean:
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl
