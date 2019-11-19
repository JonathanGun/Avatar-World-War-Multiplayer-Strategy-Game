#ifndef Point_H
#define Point_H

#include "util/boolean.h"
#include <stdio.h>

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

void TulisPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap Point *** */
boolean PointEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

boolean PointNEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

#endif