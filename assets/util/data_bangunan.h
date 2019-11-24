#ifndef DATA_BANGUNAN_H
#define DATA_BANGUNAN_H

#include "../util/util.h"

typedef struct {
    int Mem[5][5];
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

extern Matriks AttCastle,AttTower,AttFort,AttVillage;
/* Masing - masing Matriks Merepresentasikan Tipe-tipe Bangunan sesuai Nama Matriks */

void MakeData();
/* Membentuk Matriks yang berisi Atribut Bangunan untuk keperluan LEVEL UP */
/* I.S. Sembarang */
/* F.S. Terbentuk 4 Matriks yang memuat atribut atribut Bangunan Dengan Ketentuan : Nomor Baris
merepresentasikan Level Bangunan, dan Nomor Kolom Merepresentasikan Atribut Bangunan yang berbeda
dimana Kolom 1 merepresentasikan A, Kolom 2 merepresentasikan M, Kolom 3 merepresentasikan P, dan
Kolom 4 merepresentasikan U */

#endif