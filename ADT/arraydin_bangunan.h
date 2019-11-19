#include "bangunan.h"
#include "listbangunan.h"

#ifndef arraydinbangunan_H
#define arraydinbangunan_H


/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef struct
{
  Bangunan *TITB; /* memori tempat penyimpan elemen (container) */
  int NeffTB;   /* >=0, banyaknya elemen efekTITBf */
  int MaxElTB;
} TabBangunan;
/* Indeks yang digunakan [IdxMin..MaxElTB] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.NeffTB  untuk mengetahui banyaknya elemen
   T.TITB    untuk mengakses seluruh nilai elemen tabel
   T.TITB[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.NeffTB = 0
  Definisi elemen pertama : T.TITB[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TITB[i] dengan i=T.NeffTB */

/* ********** SELEKTOR ********** */
#define NeffTB(T) (T).NeffTB
#define TITB(T) (T).TITB
#define ElmtTB(T, i) (T).TITB[(i)]
#define MaxElTB(T) (T).MaxElTB

void CreateEmptyTabBangunan(TabBangunan *T, int MaxElTB)
/* I.S. T sembarang, MaxElTB > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElTB + 1 */
{
    TITB(*T) =(Bangunan*) malloc((MaxElTB+1) * sizeof(Bangunan));
    NeffTB(*T) = 0;
    MaxElTB(*T)=MaxElTB;
}
void DealokBang(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TITB(T) dikembalikan ke system, MaxElTB(T)=0; NeffTB(T)=0 */
{
    free(TITB(*T));
    MaxElTB(*T) = 0;
    NeffTB(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbBangunan(TabBangunan T)
/* Mengirimkan banyaknya elemen efekTITBf tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    if(NeffTB(T) == 0){
        return 0;
    }
    return (NeffTB(T));
}
int NbOwned(TabBangunan T, int Player)
/* Mengirimkan bangunan milik player(1 atau 2) ada berapa dari tab bangunan */
{
    int i = 1;
    int count = 0;
    while(i <= NeffTB(T){
        if(BangunanOwner(ElmtTB(T,i)) == Player){
            count++;
        }
        i++;
    }
    return count;
}

void SplitBangunan(TabBangunan TAll, ListBangunan *L1, ListBangunan *L2)
/* Akan memisahkan seTITBap bangunan di TabBangunan TAll bila */
/* ownernya 1 ke p1, kalo ownernya 2 ke p2 */
{
    int i = 1;
    while(i <= TAll.NeffTB){
        if(BangunanOwner(ElmtTB(TAll,i)) == 1){
            InsVLast(L1,i);
        }
        else if(BangunanOwner(ElmtTB(TAll,i)) == 2){
            InsVLast(L2,i);
        }
    }
}

void AddBangunan(Bangunan B, TabBangunan *TB)
/* Memasukan bangunan B sebagai bangunan terakhir di TB */
{
    
}
#endif