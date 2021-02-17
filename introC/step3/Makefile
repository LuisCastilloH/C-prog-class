# Makefile para fracciones
# @author Luis Castillo

CC=gcc
CFLAGS=-g -Wall

fracc3: funciones.o fracc3.o
	$(CC) $(CFLAGS) -o fracc3 funciones.o fracc3.o
	@echo Ejecutable fracc3 ha sido compilado exitosamente

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c

fracc3.o: fracc3.c
	$(CC) $(CFLAGS) -c fracc3.c

clean:
	rm funciones.o fracc3.o fracc3
