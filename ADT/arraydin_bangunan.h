#include "bangunan.h"
#include "listbangunan.h"
#include <stdlib.h>

#ifndef arraydinbangunan_H
#define arraydinbangunan_H


/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
  Bangunan *TB; /* memori tempat penyimpan elemen (container) */
  int NeffTB;   /* >=0, banyaknya elemen efekTITBf */
  int MaxElTB; 
} TabBangunan;
/* Indeks yang digunakan [IdxMin..MaxElTB] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.NeffTB  untuk mengetahui banyaknya elemen
   T.TB    untuk mengakses seluruh nilai elemen tabel
   T.TB[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffTB = 0
  Definisi elemen pertama : T.TB[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TB[i] dengan i=T.NeffTB */

/* ********** SELEKTOR ********** */
#define NeffTB(T) (T).NeffTB
#define TB(T) (T).TB
#define ElmtTB(T, i) (T).TB[(i)]
#define MaxElTB(T) (T).MaxElTB

/*********** KONSTRUKTOR ************/
void CreateEmptyTabBangunan(TabBangunan *T, int MaxElTB);
/* I.S. T sembarang, MaxElTB > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElTB + 1 */
void DealokBang(TabBangunan *T);
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke system, MaxElTB(T)=0; NeffTB(T)=0 */
void AddBangunan(Bangunan B, TabBangunan *TB);
/* Memasukan bangunan B sebagai bangunan terakhir di TB */


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbBangunan(TabBangunan T);
/* Mengirimkan banyaknya elemen efekTITBf tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int NbOwned(TabBangunan T, int Player);
/* Mengirimkan bangunan milik player(1 atau 2) ada berapa dari tab bangunan */

void SplitBangunan(TabBangunan TAll, ListBangunan *L1, ListBangunan *L2);
/* Akan memisahkan seTITBap bangunan di TabBangunan TAll bila */
/* ownernya 1 ke p1, kalo ownernya 2 ke p2 */

void AttBangunanIdx(TabBangunan *TAll, int T1, int T2, int jml_Penyerang);
/* I.S. Semua argumentasi dianggap valid */
/* F.S. Bangunan T1 menyerang bangunan T2 */

/*************** ALGORITMA SEARCHING ****************/
Point GetPosFrom(TabBangunan TAll, int idx);
/* I.S. idx terdefinisi di TAll, bangunan TAll.TB[i] terdefinisi */
/* Mengambil posisi dari suatu indeks bangunan */

int GetIdxFromPosBangunan(TabBangunan TAll, int Baris, int Kolom );
/* Pencarian indeks bangunan */

void GetBangunanByID(TabBangunan TAll, int id, Bangunan* B);
/* pencarian bangunan berdasarkan id nya */

// void TulisIsiTab(TabBangunan TAll);

#endif