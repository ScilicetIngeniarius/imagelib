# Make variable

all: src doc examples

MAKE = make
CD = cd

doc: doc/Makefile
	$(MAKE) -C ./doc/ all 

src: src/Makefile
	$(MAKE) -C ./src/ all

examples: test/Makefile
	$(MAKE) -C ./test/ all

.PHONY: all doc clean src

clean:
	make -C ./doc/ clean
	
