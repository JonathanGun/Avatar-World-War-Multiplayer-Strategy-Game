#include "arraydin_bangunan.h"
#include <stdio.h>
/*********** KONSTRUKTOR ************/
void CreateEmptyTabBangunan(TabBangunan *T, int MaxElTB)
/* I.S. T sembarang, MaxElTB > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElTB + 1 */
{
    TB(*T) =(Bangunan*) malloc((MaxElTB+1) * sizeof(Bangunan));
    NeffTB(*T) = 0;
    MaxElTB(*T)=MaxElTB;
}
void DealokBang(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke system, MaxElTB(T)=0; NeffTB(T)=0 */
{
    free(TB(*T));
    MaxElTB(*T) = 0;
    NeffTB(*T) = 0;
}
void AddBangunan(Bangunan B, TabBangunan *TB)
/* Memasukan bangunan B sebagai bangunan terakhir di TB */
{
    if(NeffTB(*TB) != MaxElTB(*TB)){
        ElmtTB(*TB,(NeffTB(*TB)+1)) = B;
        NeffTB(*TB)++;
    }
    else{
        printf("Bangunan sudah Full\n");
    }
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
    while(i <= NeffTB(T)){
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

void AttBangunanIdx(TabBangunan *TAll, int T1, int T2, int jml_Penyerang)
/* I.S. Semua argumentasi dianggap valid */
/* F.S. Bangunan T1 menyerang bangunan T2 */
{
    attack(&(ElmtTB(*TAll,T1)),&ElmtTB(*TAll,T2),jml_Penyerang);
}

/*************** ALGORITMA SEARCHING ****************/
Point GetPosFrom(TabBangunan TAll, int idx)
/* I.S. idx terdefinisi di TAll, bangunan TAll.TB[i] terdefinisi */
/* Mengambil posisi dari suatu indeks bangunan */
{
    return ElmtTB(TAll,idx).posisi;
}

int GetIdxFromPosBangunan(TabBangunan TAll, int Baris, int Kolom )
/* Pencarian indeks bangunan */
{
    boolean found = false;
    int i = 1;
    while(!found && i<= NeffTB(TAll)){
        if(Row(ElmtTB(TAll,i).posisi) == Baris && Col(ElmtTB(TAll,i).posisi) == Kolom){
            found = true;
        }
    }
    if(i <= NeffTB(TAll)){
        return i;
    }
    else{
        return -1; //Kalau tidak ada bangunan di baris atau kolom tsb, dikembalikan nilai -1
    }
}

void GetBangunanByID(TabBangunan TAll, int id, Bangunan* B)
/* pencarian bangunan berdasarkan id nya */
{
    // loop ke semua bangunan, cari yg Elmt(TAll, i).id = id, return Elmt(TAll, i).
    *B = ElmtTB(TAll, 1);
}

void TulisIsiTab(TabBangunan TAll){
  printf("[");
  for(int i = 1; i <= NbBangunan(TAll); ++i)
    if (i != NbBangunan(TAll)) printf("%d,",ElmtTB(TAll, i));
    else (printf("%d",ElmtTB(TAll, i)));
  printf("]");
}