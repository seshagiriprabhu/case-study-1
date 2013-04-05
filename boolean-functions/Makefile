# Makefile

all 		: question4 question5 question6

question4 	: question4.o 
			gcc -o question4 question4.o

question4.o : question4.c 
			gcc -c -O0 -fno-dce -static -Wall question4.c

question5 	: question5.o
			gcc -o question5 question5.o

question5.o : question5.c
			gcc -c -O0 -fno-dce -static -Wall question5.c

question6 	: question6.o
			gcc -o question6 question6.o

question6.o : question6.c
			gcc -c -O0 -fno-dce -static -Wall question6.c

clean: 
			rm -rf *.o question4 question5 question6
