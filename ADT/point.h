#ifndef Point_H
#define Point_H

#include "util/boolean.h"
#include <stdio.h>

typedef struct {
	int x; /* absis   */
	int y; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Absis(P) (P).x
#define Ordinat(P) (P).y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint (int X, int Y)
/* Membentuk sebuah Point dari komponen-komponennya */
{
	Point P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

void TulisPoint (Point P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	printf("(%d,%d)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean PointEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean PointNEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return !PointEQ(P1, P2);
}

#endif