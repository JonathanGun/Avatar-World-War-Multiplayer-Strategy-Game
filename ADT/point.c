/* File: point.c */
// NAMA / NIM : Jonathan Yudi GUnawan / 13518084
/* Tanggal: 28 Agustus 2019 */
/* *** Definisi ABSTRACT DATA TYPE Point *** */
#include <stdio.h>
#include <math.h>
#include "point.h"
#define	PI		3.141592654
#define	DEG(rad)	(rad*180.0/PI)
#define RAD(deg)	(deg*PI/180)

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

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPoint (Point * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	int x, y;
    scanf("%d %d", &x, &y);
    Absis(*P) = x;
    Ordinat(*P) = y;
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
	printf("(%.2f,%.2f)", Absis(P)*1.0, Ordinat(P)*1.0);
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return !EQ(P1, P2);
}


/* *** Kelompok menentukan di mana P berada *** */
boolean IsOnSbX (Point P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	return !Ordinat(P);
}

boolean IsOnSbY (Point P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	return !Absis(P);
}

boolean IsOrigin (Point P)
/* Menghasilkan true jika P adalah titik origin */
{
	return (IsOnSbX(P) && IsOnSbY(P));
}

int Kuadran (Point P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	if (Absis(P) > 0){
		if (Ordinat(P) > 0){
			return 1;
		} else {
			return 4;
		}
	} else {
		if (Ordinat(P) > 0){
			return 2;
		} else {
			return 3;
		}
	}
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
Point NextX (Point P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	++Absis(P);
	return P;
}

Point NextY (Point P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	++Ordinat(P);
	return P;
}

Point PlusDelta (Point P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	Absis(P) += deltaX;
	Ordinat(P) += deltaY;
	return P;
}

Point MirrorOf (Point P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	if (SbX){
		if (!IsOnSbX(P)){
			Ordinat(P) = -Ordinat(P);
		}
	} else {
		if (!IsOnSbY(P)){
			Absis(P) = -Absis(P);
		}	
	}
	return P;
}