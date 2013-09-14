# Make variable

all: doc src

MAKE = make
CD = cd

doc: doc/Makefile
	$(MAKE) -C ./doc/ all 

src: src/Makefile
	$(MAKE) -C ./src/ all

.PHONY: all doc clean

clean:
	make -C ./doc/ clean
	
