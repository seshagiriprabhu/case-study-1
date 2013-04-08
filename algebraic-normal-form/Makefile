# Makefile

HEADER = ../header/
EXEC = question14 question15 question16
OBJECTS = question14.o question15.o question16.o
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W

OBJ1 = question14.o
PRG1 = question14.c
EXEC1 = question14

OBJ2 = question15.o
PRG2 = question15.c
EXEC2 = question15

OBJ3 = question16.o
PRG3 = question16.c
EXEC3 = question16

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
