/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TyPE Point *** */

#ifndef Point_H
#define Point_H

#include "boolean.h"

typedef struct {
	int x; /* absis   */
	int y; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define Absis(P) (P).x
#define Ordinat(P) (P).y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point MakePoint (int x, int y);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPoint (Point * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen x dan y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(x,y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output x dan y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(x,y)" */

/* *** Kelompok operasi relasional terhadap Point *** */
boolean EQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (Point P);
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbx (Point P);
/* Menghasilkan true jika P terletak Pada sumbu x */
boolean IsOnSby (Point P);
/* Menghasilkan true jika P terletak pada sumbu y */
int Kuadran (Point P);
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TyPE *** */
Point Nextx (Point P);
/* Mengirim salinan P dengan absis ditambah satu */
Point Nexty (Point P);
/* Mengirim salinan P dengan ordinat ditambah satu */
Point PlusDelta (Point P, int deltax, int deltay);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltax dan ordinatnya adalah Ordinat(P) + deltay */
Point MirrorOf (Point P, boolean Sbx);
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika Sbx bernilai true, maka dicerminkan terhadap sumbu x */
/* Jika Sbx bernilai false, maka dicerminkan terhadap sumbu y */

#endif
