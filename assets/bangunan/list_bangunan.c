#include "list_bangunan.h"

/************* SELEKTOR(TAMBAHAN) *************/
int ListElmt(ListBangunan L, int n)
// Selektor untuk ListBangunan, bekerja seperti array L indeks ke n (L[n])
{
    n--;
    address P = First(L);
    while(n--){
        P = Next(P);
    }
    return Info(P);
}

int NbList(ListBangunan L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P = First(L);
    int count = 0;
    while ( P != Nil ) {
        P = Next(P);
        count++;
    }
    return count;
}

int NbListType(ListBangunan L, char c)
/* Mengirimkan banyaknya elemen list dengan tipe bangunan c; mengirimkan 0 jika list kosong */
{
    address P = First(L);
    int count = 0;
    while ( P != Nil ) {
        if(Type(ElmtTB(Info(P))) == c) count++;
        P = Next(P);
    }
    return count;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (ListBangunan *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiList (int X)
/* Mengirimkan address hasil AlokasiList sebuah elemen */
/* Jika AlokasiList berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika AlokasiList gagal, mengirimkan Nil */
{
    address P;
    P = (ElmtList*) malloc((sizeof(ElmtList)+1));
    if(P!=Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DeAlokasiList (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan deAlokasiList/pengembalian address P */
{
    free(*P);
}

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (ListBangunan L)
/* Mengirim true jika list kosong */
{
    return First(L)==Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList(ListBangunan L, int X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    boolean found = false;
    while(P!=Nil && !found){
        if(Info(P) == X ){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    return P;
}

/*** PENAMBAHAN ELEMEN ***/
void InsertList (ListBangunan *L, int X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan AlokasiList sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika AlokasiList berhasil. Jika AlokasiList gagal: I.S.= F.S. */
{
    address P;
    P = AlokasiList(X);
    if(P!=Nil){
        if(IsEmptyList(*L)){
            Next(P) = Nil;
            First(*L) = P;
        }
        else{
            address last = First(*L);
            while(Next(last)!= Nil){
                last = Next(last);
            }
            Next(P) = Next(last);
            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelList (ListBangunan *L, int X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-deAlokasiList */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListBangunan mungkin menjadi kosong karena penghapusan */
{
    address P;
    boolean found = false;
    P = SearchList(*L,X);
    if(P!=Nil){//nyari idx prec
        address prec = First(*L);
        if(prec == P){
            P = First(*L);
            First(*L)= Next(First(*L));
        }
        while(!found && (prec!= Nil)){
            if(Next(prec) == P){
                Next(prec) = Next(P);
                found = true;
            }
            prec = Next(prec);
        }
        DeAlokasiList(&P);
    }
    
}

/****************** KELOMPOK BACA TULIS ******************/
void PrintList(ListBangunan L)
/* I.S. ListBangunan mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if(First(L) == Nil){
        printf("[]");
    }
    else{
        address A;
        A = First(L);
        printf("[");
        while(Next(A) != Nil){
            printf("%d,",Info(A));
            A = Next(A);
        }
        printf("%d",Info(A));
        printf("]");
    }
}


/*********************** OPERASI LAIN ***********************/
void CopyList(ListBangunan L, ListBangunan *Lo)
/* I.S. L terdefinisi (boleh kosong), Lo sembarang */
/* F.S. Lo identik dengan L tapi bukan ListBangunan yang sama */
{
    CreateEmptyList(Lo);

    address P = First(L);
    while ( P != Nil ) {
        InsertList(Lo, Info(P));
        P = Next(P);
    } 
}

void FilterListTanpa(ListBangunan* L, boolean (*f)(Bangunan))
// Memfilter L dimana semua elemennya tidak ada yg true jika dijadikan parameter fungsi f
// I.S: L terdefinisi (bisa kosong)
// F.S: L terfilter sesuai definisi
{
    // kalo kosong, return
    if(First(*L) == Nil) return;

    // selama elemen pertama tdk lolos filter, hapus
    while((*f)(ElmtTB(Info(First(*L))))){
        First(*L) = Next(First(*L));
        if(First(*L) == Nil) return;
    }
    // I.S sekarang: elemen pertama pasti lolos filter dan bukan Nil
    address P = Next(First(*L));
    address save = First(*L);
    while(P != Nil) {
        if((*f)(ElmtTB(Info(P)))){
            // elemen terakhir, delete aja trus return
            if(Next(P) == Nil){
                Next(save) = Nil;
                return;
            // bukan elmt terakhir, elmt sblm P disambung dengan stlh P
            } else {
                Next(save) = Next(P);
            }
        } else {
            save = Next(save);
        }
        P = Next(P);
    }
}

void ResetListBangunan()
// Mengembalikan status sudahserang dan sudahpindah pada list bangunan milik player saat ini
{
    address P = First(CurPlayer().list_bangunan);
    while(P != Nil){
        ElmtTB(Info(P)).sudahserang = false;
        ElmtTB(Info(P)).sudahpindah = false;
        P = Next(P);
    }
}
