# Makefile

all 		: question11 question13


question11 	: question11.o
			gcc -o question11 question11.o -lm

question11.o : question11.c
			gcc -c -O0 -fno-dce -static -m32 -Wall question11.c

question13 	: question13.o
			gcc -o question13 question13.o -lm

question13.o : question13.c
			gcc -c -O0 -fno-dce -static -m32 -Wall question13.c

clean: 
			rm -rf *.o question11  question13
