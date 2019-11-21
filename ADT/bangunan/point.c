#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
Point MakePoint(int X, int Y)
/* Membentuk sebuah Point dari komponen-komponennya */
{
	Point P;
	Row(P) = X;
	Col(P) = Y;
	return P;
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean PointEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return ((Row(P1) == Row(P2)) && (Col(P1) == Col(P2)));
}

boolean PointNEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return !PointEQ(P1, P2);
}