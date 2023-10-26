SRCDIR = src/
EXESRCDIR = exesrc/

SRC=$(wildcard $(SRCDIR)/*c$ $(wildcard $(EXESRCDIR)*.c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/

CFLAGS=-I $(INC)
EXE=exe/app.elf

all: $(EXE)

%.elf: $(OBJ)
	gcc $(OBJ) -o $@

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXE)