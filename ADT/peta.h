#ifndef peta_H
#define peta_H

#include "util/pcolor.h"
#include "util/macro.h"
#include "bangunan.h"
#include <stdio.h>
#include <stdlib.h>

/* Ukuran minimum dan maksimum baris dan PetaKolom */
#define PetaBrsMin 1
#define PetaBrsMax 20
#define PetaKolMin 1
#define PetaKolMax 30

#define IdxMin 1
#define IdxUndef -999

typedef struct {
    int *Mem; // arr of ID Bangunan
    int NPetaBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NPetaKolEff; /* banyaknya/ukuran PetaKolom yg terdefinisi */
} Peta;

/* Selektor */
#define Mem(T) (T).Mem
#define PetaElmt(T, i, j) (T).Mem[(i)*(NPetaBrsEff(T)+1)+(j)]
#define NPetaBrsEff(M) (M).NPetaBrsEff
#define NPetaKolEff(M) (M).NPetaKolEff
#define forpeta(P, r, c) fori(r, NPetaBrsEff(P)) fori(c, NPetaKolEff(P))

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(Peta *P, int NB, int NK)
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M. kosong dengan ukuran NBxNK
*/
{
	NPetaBrsEff(*P) = NB;
	NPetaKolEff(*P) = NK;
	Mem(*P) = (int *) malloc (sizeof(int) * NB * NK);
	forpeta(*P, r, c) PetaElmt(*P, r, c) = -1;
}


/* SELEKTOR */
boolean IsIdxEff (Peta M, int i, int j)
/* Mengirimkan true jika i, j adalah int yang valid untuk matriks apa pun */
{
	return (((PetaBrsMin <= i) && (i <= NPetaBrsEff(M))) && ((PetaKolMin <= j) && (j <= NPetaKolEff(M))));
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta(Peta P)
/* I.S. P terdefinisi */
/* F.S. Nilai P.(i,j) ditulis ke layar per baris per PetaKolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P. sesuai dengan P.info, lalu menulis nilai setiap elemen P. ke layar dengan traversal per baris dan per PetaKolom */
/* Contoh: menulis matriks esentasi peta 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*****
* C *
*T F*
*  C*
*****
*/
{
	fori(i, NPetaKolEff(P)+2) printf("*"); ENDL;
	fori(i, NPetaBrsEff(P)){
		printf("*");
		fori(j, NPetaKolEff((P))){
			Bangunan* cur = GetBangunanByID(PetaElmt(P, i, j));
			if (BangunanOwner(*cur) == 1)
				print_red(Type(*cur));
			else if (BangunanOwner(*cur) == 2)
				print_blue(Type(*cur));
			else
				printf("%c", Type(*cur));
		}
		printf("*");
		ENDL;
	}
	fori(i, NPetaKolEff(P)+2) printf("*"); ENDL;
}

#endif