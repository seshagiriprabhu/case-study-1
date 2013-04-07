# Makefile

HEADER = ../header/
EXEC = question11 question13
OBJECTS = question11.o question13.o
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W

OBJ1 = question11.o
PRG1 = question11.c
EXEC1 = question11

OBJ2 = question13.o
PRG2 = question13.c
EXEC2 = question13

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
