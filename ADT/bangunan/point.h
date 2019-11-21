#ifndef POINT_H
#define POINT_H

#include "../util/util.h"

typedef struct {
	int r; /* absis   */
	int c; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Row(P) (P).r
#define Col(P) (P).c

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint (int X, int Y);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** Kelompok operasi relasional terhadap Point *** */
boolean PointEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean PointNEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

#endif