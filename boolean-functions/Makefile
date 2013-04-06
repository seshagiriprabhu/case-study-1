# Makefile

HEADER = ../header/
EXEC = question4 question5 question6
OBJECTS = question4.o question5.o question6.o
OBJECT_DIR = OBJECTS
CFLAG = -c -O0 -fno-dce -static -Wall -W

OBJ1 = question4.o
PRG1 = question4.c
EXEC1 = question4

OBJ2 = question5.o
PRG2 = question5.c
EXEC2 = question5

OBJ3 = question6.o
PRG3 = question6.c
EXEC3 = question6

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
