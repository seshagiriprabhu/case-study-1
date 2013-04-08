# Makefile

CC = gcc
HEADER = ../header/
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W
INC = -I$(HEADER)

EXECS := $(addprefix question, 7 8 9)
OBJS := $(addprefix OBJECTS/, $(addsuffix .o, $(EXECS))))

all 				: 	$(EXECS)
						test -d $(OBJECT_DIR) || mkdir -p $(OBJECT_DIR)

OBJECTS				:
						mkdir -p $@

$(OBJS) 			: 	| OBJECTS

question%			:	OBJECTS/question%.o
						$(CC) -o $@ $<

OBJECTS/question%.o : 	question%.c $(HEADER)/header.h
						$(CC) -c $(INC) -o $@ $< $(CFLAG)

clean				: 
						rm -rf OBJECTS $(EXECS) 

.PHONY 				: 	all clean
