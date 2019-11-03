/* Definisi Peta */

#ifndef peta_H
#define peta_H

#include "arraydinpos.h"
#include "bangunan.h"
#include "pcolor.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 20
#define KolMin 1
#define KolMax 30

#define IdxMin 1
#define IdxUndef -999

typedef struct {
	char kar;
	int color;
} ReprElmt;
typedef ReprElmt ReprType;
typedef struct {
    ReprType *Mem;
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matriks;
typedef struct {
	TabInt info; // info bangunan
	Matriks repr; //representasi
} Peta;

/* Selektor */
#define Mem(T) (T).Mem
#define MatElmt(T, i, j) (T).Mem[(i)*(NBrsEff(T)+1)+(j)]
#define Repr(P) (P).repr
#define Info(P) (P).info
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(Peta *P, int NB, int NK, int NBangunan);
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M.repr kosong dengan ukuran NBxNK
*/

/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (Matriks * M, int NB, int NK);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int NB, int NK);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* SELEKTOR */
boolean IsIdxEff (Matriks M, int i, int j);
/* Mengirimkan true jika i, j adalah int yang valid untuk matriks apa pun */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta(Peta P);
/* I.S. P terdefinisi */
/* F.S. Nilai P.repr(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P.repr sesuai dengan P.info, lalu menulis nilai setiap elemen P.repr ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks representasi peta 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*****
* C *
*T F*
*  C*
*****
*/

void ConvertToRepr(Peta P);
/* I.S. P terdefinisi */
/* F.S. Info(P) diubah menjadi Repr(R) yang bersesuaian.
/* Proses: untuk semua elemen Info(P), dicek kepemilikannya, lalu diassign warna dan karakter bersesuaian */
/* Contoh: Castle Player 1 : C Biru, Fort Player 2: F Merah
*****
* C *
*T F*
*  C*
*****
*/


#endif