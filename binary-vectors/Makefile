# Makefile

HEADER = ../header/
EXEC = question1 question2 question3
OBJECTS = question1.o question2.o question3.o
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W

# I hate makefiles, so I won't comment too much, but...
# what is the point of the variables below? I ask because
# they don't seem (at least to me) to provide much value.
OBJ1 = question1.o
PRG1 = question1.c
EXEC1 = question1

OBJ2 = question2.o
PRG2 = question2.c
EXEC2 = question2

OBJ3 = question3.o
PRG3 = question3.c
EXEC3 = question3

.old_all		: $(EXEC)
# you can use 'mkdir -p' for the test below
			test -d $(OBJECT_DIR) || mkdir $(OBJECT_DIR)
			mv $(OBJECTS) $(OBJECT_DIR)
# About the line above :
# the whole point of using makefile is to automate the build, in
# an *efficient* manner, i.e. only rebuilduing what is strictly necessary
# If you move objects to a separate dir (which is nice in itself
# not to clutter the work dir), 'make' won't find them at the next invocation
# and will rebuild everything. Not really a problem here as this project
# compiles quickly, but still. You could have OBJ1=OBJECTS/question1.o, etc.
# (in this case having OBJ1 variable would seem to save more typing...)
# But there is a more automated way using 'patsubst', see e.g.
# http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
# Have a look also at make documentation ('info make'), there is a paragraph
# (paragraph '4.3 Types of Prerequisites' on my installation)
# on exactly this problem


#here is an example of better style makefile for the next rule
# Old:
# $(EXEC1) 	: $(OBJ1)
#			 gcc -o $(EXEC1) $(OBJ1)
# New:
# question1	: OBJECTS/question1.o
#			gcc -o $@ $<

# I also rewrite the 'all' rule and objects rules... and everything!

EXECS := $(addprefix question, 1 2 3)
OBJS := $(addprefix OBJECTS/, $(addsuffix .o, $(EXECS)))

all		: $(EXECS)

OBJECTS		:
			mkdir -p $@

$(OBJS)		: | OBJECTS

OBJECTS/%.o	: %.c
			gcc $(CFLAG) -I$(HEADER) -o $@ $<

# for the EXECS... not sure it is good style!
# (it matches any target)
%		: OBJECTS/%.o
			gcc -o $@ $<

# a better alternative?
#question%	: OBJECTS/question%.o
#			gcc -o $@ $<
# or name executables as question1.out etc.

# $(OBJ1) 	: $(PRG1)
#			 gcc $(CFLAG) -I$(HEADER) $(PRG1)


# $(EXEC2) 	: $(OBJ2)
#			 gcc -o $(EXEC2) $(OBJ2)

# $(OBJ2) 	: $(PRG2)
#			 gcc $(CFLAG) -I$(HEADER) $(PRG2)

# $(EXEC3) 	: $(OBJ3)
#			 gcc -o $(EXEC3) $(OBJ3)

# $(OBJ3) 	: $(PRG3)
#			 gcc $(CFLAG) -I$(HEADER) $(PRG3)

clean:
			rm -rf OBJECTS $(EXECS)

.PHONY		: all clean
