# Makefile

all 		: question1 question2 question3

question1 	: question1.o 
			gcc -o question1 question1.o

question1.o : question1.c 
			gcc -c -O0 -fno-dce -static -Wall question1.c

question2 	: question2.o
			gcc -o question2 question2.o

question2.o : question2.c
			gcc -c -O0 -fno-dce -static -Wall question2.c

question3 	: question3.o
			gcc -o question3 question3.o

question3.o : question3.c
			gcc -c -O0 -fno-dce -static -Wall question3.c

clean: 
			rm -rf *.o question1 question2 question3
