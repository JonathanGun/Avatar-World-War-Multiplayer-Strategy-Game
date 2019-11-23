#include "arraydin_bangunan.h"

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

void AddBangunan(Bangunan B)
/* Memasukan bangunan B sebagai bangunan terakhir di TB */
{
    NeffTB(InfoTopStackt(G.GameConditions).ListBangunan)++;
    ElmtTB((NeffTB(InfoTopStackt(G.GameConditions).ListBangunan))) = B;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbBangunan(TabBangunan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return NeffTB(T);
}

void SplitBangunan(ListBangunan *L1, ListBangunan *L2)
/* Akan memisahkan setiap bangunan di TabBangunan TAll bila */
/* ownernya 1 ke p1, kalo ownernya 2 ke p2 */
{
    int i = 1;
    while(i <= InfoTopStackt(G.GameConditions).ListBangunan.NeffTB){
        if(BangunanOwner(ElmtTB(i)) == 1){
            InsertList(L1,i);
        } else if(BangunanOwner(ElmtTB(i)) == 2){
            InsertList(L2,i);
        }
    }
}

/*************** ALGORITMA SEARCHING ****************/
Point GetPosFrom(int idx)
/* I.S. idx terdefinisi di TAll, bangunan TAll.TB[i] terdefinisi */
/* Mengambil posisi dari suatu indeks bangunan */
{
    return ElmtTB(idx).posisi;
}

int GetIdxFromPosBangunan(int Baris, int Kolom)
/* Pencarian indeks bangunan */
{
    boolean found = false;
    int i = 1;
    while(!found && i<= NeffTB(InfoTopStackt(G.GameConditions).ListBangunan)){
        if(Row(ElmtTB(i).posisi) == Baris && Col(ElmtTB(i).posisi) == Kolom){
            found = true;
        }
    }
    if(i <= NeffTB(InfoTopStackt(G.GameConditions).ListBangunan)){
        return i;
    } else {
        return -1; //Kalau tidak ada bangunan di baris atau kolom tsb, dikembalikan nilai -1
    }
}

void TulisIsiTabBangunan(){
    printf("[");
    for(int i = 1; i <= NbBangunan(InfoTopStackt(G.GameConditions).ListBangunan); ++i){
        TulisBangunan(ElmtTB(i));
        if (i != NbBangunan(InfoTopStackt(G.GameConditions).ListBangunan)) printf(",");
    }
    printf("]");
}

void TulisIsiTabBangunan2(TabBangunan T) {
    int i;
    for ( i = 1; i <= NbBangunan(T); i++ ) {
        printf("id %d\n", i);
        printf("level %d\n", T.TB[i].level);
        printf("pasukan %d\n", T.TB[i].jumlah_pasukan);
        printf("maks %d\n", T.TB[i].maksimum_tambah_pasukan);
        printf("tambah %d\n",T.TB[i].nilai_tambah_pasukan);
        printf("owner %d\n", T.TB[i].owner);
        printf("pertahanan %d\n", T.TB[i].pertahanan);
        printf("sudahpidah %s\n", T.TB[i].sudahpindah ? "Ya" : "Tidak");
        printf("sudahserang %s\n", T.TB[i].sudahserang ? "Ya" : "Tidak");
        getchar();
    } 
}

void TulisDaftarBangunan(ListBangunan L) {
    int i = 1;
    address P = First(L);
    while(P != Nil) {
        printf("%d. ", i);
        if (Type(ElmtTB(Info(P))) == 'C') printf("Castle ");
        else if (Type(ElmtTB(Info(P))) == 'T') printf("Tower ");
        else if (Type(ElmtTB(Info(P))) == 'F') printf("Fort ");
        else if (Type(ElmtTB(Info(P))) == 'V') printf("Village ");

        printf("(%d,%d) ", ElmtTB(Info(P)).posisi.r, ElmtTB(Info(P)).posisi.c);
        printf("%d ", ElmtTB(Info(P)).jumlah_pasukan);
        printf("lv. %d\n", ElmtTB(Info(P)).level);

        P = Next(P);
        i++;
    }
}

void FilterListTanpa(ListBangunan* L, boolean (*f)(Bangunan)){
    while((*f)(ElmtTB(Info(First(*L))))){
        First(*L) = Next(First(*L));
        if(First(*L) == Nil) break;
    }
    address P = First(*L);
    if(P == Nil) return;
    while(Next(P) != Nil) {
        if((*f)(ElmtTB(Info(Next(P))))){
            if(Next(Next(P)) = Nil) Next(P) = Nil;
            else Next(P) = Next(Next(P));
        }
        if(Next(P) != Nil) P = Next(P);
    }
    if((*f)(ElmtTB(Info(P)))){
        P = Nil;
        First(*L) = Nil;
    }
}

void ResetListBangunan(){
    address P = First(CurPlayer().list_bangunan);
    while(P != Nil){
        ElmtTB(Info(P)).sudahserang = false;
        ElmtTB(Info(P)).sudahpindah = false;
        P = Next(P);
    }
}

void CopyTabBangunan(TabBangunan T, TabBangunan *To) {
    CreateEmptyTabBangunan(To, T.MaxElTB);
    int i;
    for ( i = 1; i <= T.NeffTB; i++ ) {
        (*To).TB[i] = T.TB[i];
    }
    (*To).NeffTB = T.NeffTB;
}