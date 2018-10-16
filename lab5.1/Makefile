CC= gcc
OBJ= memory1 memory2 memory3 memory4 memory5a memory5b memory6

all: $(OBJ)

$(OBJ): %: %.c
	$(CC) $^ -o $@ 
clean:
	rm -r *.o
