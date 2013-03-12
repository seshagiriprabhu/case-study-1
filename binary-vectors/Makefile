# Makefile

all : question1 question2

question1 : question1.o 
			gcc -o question1 question1.o

question1.o : question1.c 
			gcc -c -O0 -fno-dce -fno-stack-protector -static -m32 -Wall question1.c

question2: question2.0
			gcc -o question2 question2.o

question2.o: question2.c
			gcc -c -O0 -fno-dce -fno-stack-protector -static -m32 -w question2.c

clean: 
		rm -rf *.o question1 question2
