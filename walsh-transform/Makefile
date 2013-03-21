# Makefile

all 		: question7 question8 question9

question7 	: question7.o 
			gcc -o question7 question7.o

question7.o : question7.c 
			gcc -c -O0 -fno-dce -static -m32 -Wall question7.c 

question8 	: question8.o
			gcc -o question8 question8.o -lm

question8.o : question8.c
			gcc -c -O0 -fno-dce -static -m32 -Wall question8.c

question9 	: question9.o
			gcc -o question9 question9.o -lm

question9.o : question9.c
			gcc -c -O0 -fno-dce -static -m32 -Wall question9.c

clean: 
			rm -rf *.o question7 question8 question9
