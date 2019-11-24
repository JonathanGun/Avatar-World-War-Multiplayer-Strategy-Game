#ifndef ARRAYDIN_BANGUNAN_H
#define ARRAYDIN_BANGUNAN_H

#include "../util/util.h"
#include "bangunan.h"
#include "list_bangunan.h"

/* STRUKTUR ADT */
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

/***************** KELOMPOK BACA TULIS *****************/
void PrintDaftarBangunan(ListBangunan L);
/* I.S. L Terdefinisi */
/* F.S. elemen L tertulis di layar sesuai format di spek */

/********** OPERASI LAIN ***********/
void AddBangunan(Bangunan B);
/* Memasukan bangunan B sebagai bangunan terakhir di TB */
void CopyTabBangunan(TabBangunan T, TabBangunan *To);
/* I.S. T terdefinisi (boleh kosong), To sembarang */
/* F.S. To identik dengan T tapi bukan TabBangunan yang sama */

#endif