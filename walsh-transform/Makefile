# Makefile

CC = gcc
HEADER = ../header/
OBJECT_DIR = OBJECTS
UOBJ = $(HEADER)util.o
CFLAG = -c -O0 -fno-dce -static -Wall -W
INC = -I$(HEADER)

EXECS := $(addprefix question, 7 8 9)
OBJS := $(addprefix OBJECTS/, $(addsuffix .o, $(EXECS))))

all 				: 	$(EXECS) 
						test -d $(OBJECT_DIR) || mkdir -p $(OBJECT_DIR)

OBJECTS				:
						mkdir -p $@

$(OBJS) 			: 	| OBJECTS

question%			:	OBJECTS/question%.o $(UOBJ)
						$(CC) -o $@ $< $(UOBJ)

UOBJ				:	$(HEADER)/util.c
						$(CC) $(INC) -o $(HEADER)/util.c $(CLFAG)

OBJECTS/question%.o : 	question%.c $(HEADER)/header.h $(HEADER)/util.c
						$(CC) $(INC) -o  $@ $< $(CFLAG)

clean				: 
						rm -rf OBJECTS $(EXECS) 

.PHONY 				: 	all clean
