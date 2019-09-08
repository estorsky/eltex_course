all:
	-ctags -R .
	cd src; make all
	cd lib; make all

clean:
	rm -f tags
	cd src; make clean
	cd lib; make clean

