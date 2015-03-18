# from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS=#-I.
OBJS=main.o serial.o parallel.o
SRCDIR=src
BINDIR=bin
EXE=labexe

DEPS=

all: $(EXE)

clean:
	rm $(EXE)
	rm *.o

%.o: %.c $(DEPS) makefile
	$(CC) -g -c -Wall -o ../$@ $< $(CFLAGS)

$(EXE): $(OBJS) makefile
	@cd $(SRCBIN)
	$(CC) -o ../$@ ../$(OBJS)
	@echo 'Built executable "labexe"'
