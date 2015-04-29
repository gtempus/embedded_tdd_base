all: 
	make -f MakefileCppUTest.mk
	make -f MakefileAVR.mk all

test:
	make -f MakefileCppUTest.mk

flash:
	make -f MakefileAVR.mk flash

size:
	make -f MakefileAVR.mk size

clean:
	make -f MakefileCppUTest.mk realclean
	make -f MakefileAVR.mk clean
