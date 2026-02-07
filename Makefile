CC = gcc

OBJ_FILES = TaskManager.o

all: output

output: $(OBJ_FILES)
	$(CC) $<  -o $@

TaskManager.o: TaskManager.c
	$(CC) -c $< -o $@

clean:
	rm output *.o
