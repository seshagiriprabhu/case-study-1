# Makefile

HEADER = ../header/
EXEC = question7 question8 question9
OBJECTS = question7.o question8.o question9.o
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W

OBJ1 = question7.o
PRG1 = question7.c
EXEC1 = question7

OBJ2 = question8.o
PRG2 = question8.c
EXEC2 = question8

OBJ3 = question9.o
PRG3 = question9.c
EXEC3 = question9

all 		: $(EXEC)
			test -d $(OBJECT_DIR) || mkdir $(OBJECT_DIR)
			mv $(OBJECTS) $(OBJECT_DIR)

$(EXEC1) 	: $(OBJ1)
			gcc -o $(EXEC1) $(OBJ1)

$(OBJ1) 	: $(PRG1) 
			gcc $(CFLAG) -I$(HEADER) $(PRG1)


$(EXEC2) 	: $(OBJ2)
			gcc -o $(EXEC2) $(OBJ2)

$(OBJ2) 	: $(PRG2) 
			gcc $(CFLAG) -I$(HEADER) $(PRG2)

$(EXEC3) 	: $(OBJ3)
			gcc -o $(EXEC3) $(OBJ3)

$(OBJ3) 	: $(PRG3) 
			gcc $(CFLAG) -I$(HEADER) $(PRG3)

clean: 
			rm -rf *.o $(EXEC) $(OBJECT_DIR)/*.o
			rmdir $(OBJECT_DIR)
