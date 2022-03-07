CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
LDLIBS=-lstack_fp
LIBS=-lm -pthread

all: libstack_fDoble.a p2_e1a p2_e1b

p2_e1a: p2_e1a.o point.o 
	$(CC) $(LDFLAGS) $(LIBS) p2_e1a.o point.o -g -o p2_e1a

p2_e1b: p2_e1b.o point.o libstack_fDoble.a
	$(CC) $(LDFLAGS) $(LIBS) p2_e1b.o point.o -g -o p2_e1b

point.o: point.c point.h types.h
	$(CC) $(LIBS) -ansi -pedantic -Wall -g -c point.c
	
map.o: map.c map.h types.h 
	$(CC) $(LIBS) -ansi -pedantic -Wall -g -c map.c

p2_e1a.o: p2_e1a.c point.h types.h
	$(CC) $(LIBS) -ansi -pedantic -Wall -g -c p2_e1a.c	

p2_e1b.o: p2_e1b.c point.h types.h
	$(CC) $(LIBS) -ansi -pedantic -Wall -g -c p2_e1b.c			