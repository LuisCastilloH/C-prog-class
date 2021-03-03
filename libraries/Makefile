# Makefile para fracciones
# @author Luis Castillo

CC=gcc
CFLAGS=-g -Wall
SFOLDER=lib/static
DFOLDER=lib/dynamic
libname=distancias
targs=bin/main1.out bin/main2.out

all: $(targs)

bin/main1.out:
	$(CC) $(CFLAGS) src/main1.c -L$(SFOLDER) -l$(libname) -o bin/main1.out -lm

bin/main2.out:
	$(CC) $(CFLAGS) src/main2.c -L$(DFOLDER) -l$(libname) -o bin/main2.out -lm

clean:
	rm bin/main1.out bin/main2.out
