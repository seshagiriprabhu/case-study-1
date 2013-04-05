# Makefile

all 		: question14 question15 question16


question14 	: question14.o
			gcc -o question14 question14.o -lm

question14.o : question14.c
			gcc -c -O0 -fno-dce -static -Wall question14.c

question15 	: question15.o
			gcc -o question15 question15.o -lm

question15.o : question15.c
			gcc -c -O0 -fno-dce -static -Wall question15.c

question16 	: question16.o
			gcc -o question16 question16.o -lm

question16.o : question16.c
			gcc -c -O0 -fno-dce -static -Wall question16.c

clean: 
			rm -rf *.o question14  question15 question16
