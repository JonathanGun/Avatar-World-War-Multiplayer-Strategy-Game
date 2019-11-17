#ifndef matriks_H
#define matriks_H

#include "util/boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define KolMin 1

typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
    ElType Mem[5][5];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matriks;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (Matriks * M, int NB, int NK);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatElmt(M,i,j) (M).Mem[(i)][(j)]

#endif