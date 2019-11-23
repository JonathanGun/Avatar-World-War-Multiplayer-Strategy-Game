#ifndef ARRAYDIN_BANGUNAN_H
#define ARRAYDIN_BANGUNAN_H

#include "../util/util.h"
#include "bangunan.h"
#include "list_bangunan.h"


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
#define ElmtTB(i) (InfoTopStackt(G.GameConditions).ListBangunan).TB[(i)] 
#define MaxElTB(T) (T).MaxElTB

/*********** KONSTRUKTOR ************/
void CreateEmptyTabBangunan(TabBangunan *T, int MaxElTB);
/* I.S. T sembarang, MaxElTB > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElTB + 1 */
void DealokBang(TabBangunan *T);
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke system, MaxElTB(T)=0; NeffTB(T)=0 */
void AddBangunan(Bangunan B);
/* Memasukan bangunan B sebagai bangunan terakhir di TB */


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbBangunan(TabBangunan T);
/* Mengirimkan banyaknya elemen efekTITBf tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void SplitBangunan(ListBangunan *L1, ListBangunan *L2);
/* Akan memisahkan seTITBap bangunan di TabBangunan TAll bila */
/* ownernya 1 ke p1, kalo ownernya 2 ke p2 */

/*************** ALGORITMA SEARCHING ****************/
Point GetPosFrom(int idx);
/* I.S. idx terdefinisi di TAll, bangunan TAll.TB[i] terdefinisi */
/* Mengambil posisi dari suatu indeks bangunan */

int GetIdxFromPosBangunan(int Baris, int Kolom );
/* Pencarian indeks bangunan */

void TulisIsiTabBangunan();

void TulisIsiTabBangunan2(TabBangunan T);

void TulisDaftarBangunan(ListBangunan L);

void FilterListTanpa(ListBangunan* L, boolean (*f)(Bangunan));

void ResetListBangunan();

void CopyTabBangunan(TabBangunan T, TabBangunan *To);

#endif