# Makefile para librerias
# @author Luis Castillo

CC=gcc
CFLAGS=-g -Wall
AR=ar
ARFLAGS=rcs
SOBJ=static/abs.o static/dh.o static/dlr.o static/dv.o
DOBJ=dynamic/abs.o dynamic/dh.o dynamic/dlr.o dynamic/dv.o
targs=dynamic/libdistancias.so static/libdistancias.a

all: $(targs)

dynamic/libdistancias.so: $(DOBJ)
	$(CC) $(CFLAGS) -shared -o dynamic/libdistancias.so $(DOBJ)

static/libdistancias.a: $(SOBJ)
	$(AR) $(ARFLAGS) static/libdistancias.a $(SOBJ)


# static libraries
static/abs.o: src/abs.c
	$(CC) $(CFLAGS) -c src/abs.c -o static/abs.o

static/dh.o: src/dh.c
	$(CC) $(CFLAGS) -c src/dh.c -o static/dh.o

static/dlr.o: src/dlr.c
	$(CC) $(CFLAGS) -c src/dlr.c -o static/dlr.o

static/dv.o: src/dv.c
	$(CC) $(CFLAGS) -c src/dv.c -o static/dv.o

# dynamic libraries...
dynamic/abs.o: src/abs.c
	$(CC) $(CFLAGS) -fPIC -c src/abs.c -o dynamic/abs.o

dynamic/dh.o: src/dh.c
	$(CC) $(CFLAGS) -fPIC -c src/dh.c -o dynamic/dh.o

dynamic/dlr.o: src/dlr.c
	$(CC) $(CFLAGS) -fPIC -c src/dlr.c -o dynamic/dlr.o

dynamic/dv.o: src/dv.c
	$(CC) $(CFLAGS) -fPIC -c src/dv.c -o dynamic/dv.o

clean:
	find static/ -name "*.o" -delete
	find static/ -name "*.a" -delete
	find dynamic/ -name "*.o" -delete
	find dynamic/ -name "*.so" -delete
