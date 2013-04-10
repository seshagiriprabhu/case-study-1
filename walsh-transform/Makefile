# Makefile

CC = gcc
HEADER = ../header
UOBJ = $(HEADER)/util.o
UPROG = $(HEADER)/util.c
CFLAG = -c -O0 -fno-dce -static -Wall -W
INC = -I$(HEADER)

_DEPS = header.h
DEPS = $(patsubst %, $(HEADER)/%, $(_DEPS))
EXECS := $(addprefix question, 7 8 9) 
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
