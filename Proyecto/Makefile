# Make variable

all: src doc

MAKE = make
CD = cd

doc: doc/Makefile
	$(MAKE) -C ./doc/ all 

src: src/Makefile
	$(MAKE) -C ./src/ all

.PHONY: all doc clean src

clean:
	make -C ./doc/ clean
	
