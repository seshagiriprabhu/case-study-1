# Makefile

# Bonus question:
# the Makefile now seems correct but does not work as intended:
# after 'make clean && make', the last output line
# is 'rm OBJECTS/question3.o'. Do we want that?
# I spent a certain amount of time finding the error. It is just this
# kind of problems which contribute to make me hate make!
# Please, don't spend much time on this.
# There was an extra ')' bracket at the end of "OBJS := " statement. So
# the object was saved as "question.o)". This made make think that it 
# is an intermediate file obtained as part of chain rules. So the 
# default make rule deleted that file. 
# I debuuged it using make -np option

CC = gcc
HEADER = ../header
UOBJ = $(HEADER)/util.o
UPROG = $(HEADER)/util.c
CFLAG = -c -O0 -fno-dce -static -Wall -W
INC = -I$(HEADER)

_DEPS = header.h
DEPS = $(patsubst %, $(HEADER)/%, $(_DEPS))
EXECS := $(addprefix question, 1 2 3) 
OBJS := $(addprefix OBJECTS/, $(addsuffix .o, $(EXECS)))

all 				: 	$(EXECS) 

OBJECTS				:
						mkdir -p $@

$(OBJS) 			: 	| OBJECTS

question%			:	OBJECTS/question%.o $(UOBJ)
						$(CC) -o $@ $^

OBJECTS/question%.o : 	question%.c $(DEPS)
						$(CC) $(INC) -o $@ $< $(CFLAG)

$(UOBJ)				:	$(UPROG) $(DEPS)
						$(CC) $(INC) -o $@ $< $(CFLAG)

clean				:
						rm -rf $(EXECS) OBJECTS


.PHONY 				: 	clean all
