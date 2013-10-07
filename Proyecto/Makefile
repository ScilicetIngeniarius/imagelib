# Make variable

all: build doc

MAKE = make
CD = cd

doc: doc/Makefile
	$(MAKE) -C ./doc/ all 

build: build/Makefile
	$(MAKE) -C ./build/ all

examples: test/Makefile
	$(MAKE) -C ./test/ all

.PHONY: all doc clean build

clean:
	make -C ./doc/ clean
	rm ../Multimedia/*.log ../Multimedia/*.snm ../Multimedia/*.aux ../Multimedia/*.out ../Multimedia/*.toc ../Multimedia/*.nav ../Multimedia/*.info ../Multimedia/*.gz
	
	
