# Make variable

all: build doc

MAKE = make
CD = cd

doc: doc/Makefile
	$(MAKE) -C ./doc/ all 

build: src/Makefile
	$(MAKE) -C ./build/ all

examples: test/Makefile
	$(MAKE) -C ./test/ all

.PHONY: all doc clean src

clean:
	make -C ./doc/ clean
	
