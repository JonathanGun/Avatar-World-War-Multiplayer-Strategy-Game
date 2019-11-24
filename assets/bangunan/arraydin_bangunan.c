#include "arraydin_bangunan.h"

/*********************** KONSTRUKTOR ************************/
void CreateEmptyTabBangunan(TabBangunan *T, int MaxElTB)
/* I.S. T sembarang, MaxElTB > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElTB + 1 */
{
    TB(*T) =(Bangunan*) malloc((MaxElTB+1) * sizeof(Bangunan));
    NeffTB(*T) = 0;
    MaxElTB(*T) = MaxElTB;
}

void DealokBang(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TB(T) dikembalikan ke system, MaxElTB(T)=0; NeffTB(T)=0 */
{
    free(TB(*T));
    MaxElTB(*T) = 0;
    NeffTB(*T) = 0;
}

/***************** KELOMPOK BACA TULIS *****************/
void TulisDaftarBangunan(ListBangunan L)
/* I.S. L Terdefinisi */
/* F.S. elemen L tertulis di layar sesuai format di spek */
{
    int i = 1;
    address P = First(L);
    while(P != Nil) {
        printf("%d. ", i);
        printTypeBangunan(ElmtTB(Info(P)));
        printf("(%d,%d) ", ElmtTB(Info(P)).posisi.r, ElmtTB(Info(P)).posisi.c);
        printf("%d ", ElmtTB(Info(P)).jumlah_pasukan);
        printf("lv. %d\n", ElmtTB(Info(P)).level);

        P = Next(P);
        i++;
    }
}

/********** OPERASI LAIN ***********/
void AddBangunan(Bangunan B)
/* Memasukan bangunan B sebagai bangunan terakhir di arraydin_bangunan global */
{
    NeffTB(InfoTopStackt(G.GameConditions).ListBangunan)++;
    ElmtTB((NeffTB(InfoTopStackt(G.GameConditions).ListBangunan))) = B;
}

void CopyTabBangunan(TabBangunan T, TabBangunan *To)
/* I.S. T terdefinisi (boleh kosong), To sembarang */
/* F.S. To identik dengan T tapi bukan TabBangunan yang sama */
{
    CreateEmptyTabBangunan(To, T.MaxElTB);
    int i;
    for ( i = 1; i <= T.NeffTB; i++ ) {
        (*To).TB[i] = T.TB[i];
    }
    (*To).NeffTB = T.NeffTB;
}
