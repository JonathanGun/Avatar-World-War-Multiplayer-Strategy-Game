#include "list_bangunan.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (ListBangunan L)
/* Mengirim true jika list kosong */
{
    return First(L)==NULL;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (ListBangunan *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L)=NULL;
}

/****************** Manajemen Memori ******************/
address AlokasiList (int X)
/* Mengirimkan address hasil AlokasiList sebuah elemen */
/* Jika AlokasiList berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika AlokasiList gagal, mengirimkan NULL */
{
    address P;
    P = (ElmtList*) malloc((sizeof(ElmtList)+1));
    if(P!=NULL){
        Info(P) = X;
        Next(P) = NULL;
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (ListBangunan L, int X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    address P = First(L);
    boolean found = false;
    while(P!=NULL && !found){
        if(Info(P) == X ){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListBangunan *L, int X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan AlokasiList sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika AlokasiList berhasil */
{
    address A;
    A = AlokasiList(X);
    if(A!=NULL){
        InsertFirst(L,A);
    }
}

void InsertList (ListBangunan *L, int X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan AlokasiList sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika AlokasiList berhasil. Jika AlokasiList gagal: I.S.= F.S. */
{
    address P;
    P = AlokasiList(X);
    if(P!=NULL){
        InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListBangunan *L, int *X)
/* I.S. ListBangunan L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-deAlokasiList */
{
    address A;
    DelFirst(L,&A);
    *X = Info(A);
    DeAlokasiList(&A);
}

void DelVLast (ListBangunan *L, int *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-deAlokasiList */
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    DeAlokasiList(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListBangunan *L, address P)
/* I.S. Sembarang, P sudah diAlokasiList  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (ListBangunan *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah diAlokasiList  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (ListBangunan *L, address P)
/* I.S. Sembarang, P sudah diAlokasiList  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmptyList(*L)){
        Next(P) = NULL;
        First(*L) = P;
    }
    else{
        address last = First(*L);
        while(Next(last)!= NULL){
            last = Next(last);
        }
        InsertAfter(L,P,last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListBangunan *L, address *P)
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L)= Next(First(*L));
}

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
    P = Search(*L,X);
    if(P!=NULL){//nyari idx prec
        address prec = First(*L);
        if(prec == P){
            DelFirst(L,&P);
        }
        while(!found && (prec!= NULL)){
            if(Next(prec) == P){
                Next(prec) = Next(P);
                found = true;
            }
            prec = Next(prec);
        }
        DeAlokasiList(&P);
    }
    
}

void DelLast (ListBangunan *L, address *P)
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    *P = First(*L);
    address prec = *P;
    if(Next(*P) == NULL){ //cuma 1 elmt
        DelFirst(L,P);
    }
    else{
        while(Next(*P)){
            *P = Next(*P);
            if(Next(*P) != NULL){
                prec = *P;
            }
        }
        Next(prec) = NULL;
    }
}

void DelAfter (ListBangunan *L, address *Pdel, address Prec)
/* I.S. ListBangunan tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if(*Pdel != NULL){
        Next(Prec) = Next(Next(Prec));
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintList(ListBangunan L)
/* I.S. ListBangunan mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if(First(L) == NULL){
        printf("[]");
    }
    else{
        address A;
        A = First(L);
        printf("[");
        while(Next(A) != NULL){
            printf("%d,",Info(A));
            A = Next(A);
        }
        printf("%d",Info(A));
        printf("]");
    }
}

int CountList(ListBangunan L) {
    address P = First(L);
    int count = 0;
    while ( P != NULL ) {
        P = Next(P);
        count++;
    }
    return count;
}

int ListElmt(ListBangunan L, int n){
    n--;
    address P = First(L);
    while(n--){
        P = Next(P);
    }
    return Info(P);
}

void UpdateList(ListBangunan* L, Bangunan B, int milik){
    // kalau bukan pny dia tapi ada di list, hapus bangunannya
    if(B.owner != milik && Search(*L, B.id) != NULL){
        DelList(L, B.id);
    } // kalau punya dia tapi tidak ada di list, tambah bangunannya
    else if(B.owner == milik && Search(*L, B.id) == NULL){
        InsertList(L, B.id);
    }
}