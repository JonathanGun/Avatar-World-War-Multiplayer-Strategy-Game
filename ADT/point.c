#include <stdio.h>
#include <math.h>
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

void TulisPoint (Point P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	printf("(%d,%d)", Row(P), Col(P));
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