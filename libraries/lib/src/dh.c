// Archivo: dh.c
// prototipos

#include "distancias.h"

int dh( int x1, int y1, int x2, int y2 ) {
      int r; 
      r = abs( x1 - x2 );
      return r;
}