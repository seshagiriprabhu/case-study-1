# Makefile

# Bonus question:
# the Makefile now seems correct but does not work as intended:
# after 'make clean && make', the last output line
# is 'rm OBJECTS/question3.o'. Do we want that?
# I spent a certain amount of time finding the error. It is just this
# kind of problems which contribute to make me hate make!
# Please, don't spend much time on this.
CC = gcc
HEADER = ../header/
## If we keep this variable below, let's not use OBJECTS
## directly anymore. Or use OBJECTS only.
OBJECT_DIR = OBJECTS
UOBJ = $(HEADER)util.o
CFLAG = -c -O0 -fno-dce -static -Wall -W
INC = -I$(HEADER)

EXECS := $(addprefix question, 1 2 3)
OBJS := $(addprefix OBJECTS/, $(addsuffix .o, $(EXECS))))

all 				: 	$(EXECS) 
#						 test -d $(OBJECT_DIR) || mkdir -p $(OBJECT_DIR)

# we don't need line above (with 'test'), the corresponding
# action is taken care of by the next rule. Furthermore,
# I think it does not work as it creates the dir *after*
# the execs are asked to be built

OBJECTS				:
						mkdir -p $@

$(OBJS) 			: 	| OBJECTS

question%			:	OBJECTS/question%.o $(UOBJ)
						$(CC) -o $@ $^

# you write (on purpose?) UOBJ instead of $(UOBJ), so this rule was
# ignored... luckily! because your util.c is the dest file
# (option '-o') of gcc, so this source file is overwritten
# So I add the intended rule after
# Oh... and I finally found this rule is also broken because
# of the typo in '$(CLFAG)'
# In the end, it allows to compile util.c with warning flags,
# which will allow you to spot an important error!

UOBJ				:	$(HEADER)/util.c
						$(CC) $(INC) -o $(HEADER)/util.c $(CLFAG)


$(UOBJ)				:	$(HEADER)/util.c $(HEADER)/header.h
						$(CC) $(INC) -o $@ $< $(CFLAG)


# no need to be dependant on util.c
OBJECTS/question%.o : 	question%.c $(HEADER)/header.h
						$(CC) $(INC) -o  $@ $< $(CFLAG)

clean				:
						rm -rf OBJECTS $(EXECS) $(UOBJ)

.PHONY 				: 	all clean
