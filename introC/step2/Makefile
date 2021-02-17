# Makefile para fracciones
# @author Luis Castillo

CC=gcc
CFLAGS=-g -Wall

fracc2: funciones.o fracc2.o
	$(CC) $(CFLAGS) -o fracc2 funciones.o fracc2.o
	@echo Ejecutable fracc2 ha sido compilado exitosamente

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c

fracc2.o: fracc2.c
	$(CC) $(CFLAGS) -c fracc2.c

clean:
	rm funciones.o fracc2.o fracc2
