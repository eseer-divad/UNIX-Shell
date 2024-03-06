# David's Shell Makefile, 256 thread limit.
CC=gcc
CFLAGS=-Wall -g
all: shell

# shell compile target
shell : shell.o
	$(CC) $(CFLAGS) -o shell shell.o

# compiles shell.c to shell.o
shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

# clean target (removes a lot)
clean:
	$(RM) *.o *~ shell

# run target
run: all
	ulimit -u 256; \
	./shell