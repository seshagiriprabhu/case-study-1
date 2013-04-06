# Makefile

COMPILER = gcc
HEADER = ../header
FLAGS = -c -ggdb -Wall -W -O0
OFLAG = -o
CXX_CFLAGS = -I$(HEADER)

CPROG1 = question1.c
CPROG2 = question2.c
CPROG3 = question3.c

OBJECT1 = question1.o
OBJECT2 = question2.o
OBJECT3 = question3.o

EXEC1 = question1
EXEC2 = question2
EXEC3 = question3

OBJECTS = $(OBJECT1) $(OBJECT2) $(OBJECT3)
EXEC = $(EXEC1) $(EXEC2) $(EXEC3)

all	: $(EXEC)

EXEC1 	: $(OBJECT1)
		$(COMPILER) $(OFLAG) $(EXEC1)  $(OBJECT1)

OBJECT1 : $(CPROG1) 
		$(COMPILER) $(FLAGS) $(CPROG1)

EXEC2 	: $(OBJECT2)
		$(COMPILER) $(OLFAG) $(EXEC2) $(OBJECT2)

OBJECT2 :  $(CPROG2)
		$(COMPILER) $(FLAGS) $(CPROG2)

EXEC3 	: $(OBJECT3)
		$(COMPILER) $(OLFAG) $(EXEC3) $(OBJECT3)

OBJECT3 : $(CPROG3)
		$(COMPILER) $(FLAGS) $(OBJECT3) $(CXX_CFLAGS) $(CPROG3)

clean: 
		rm -rf *.o $(EXEC)
