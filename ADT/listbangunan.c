#include "listbangunan.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (ListBangunan L)
/* Mengirim true jika list kosong */
{
    return First(L)==NULL;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListBangunan *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L)=NULL;
}

/****************** Manajemen Memori ******************/
address Alokasi (int X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    address P;
    P = (ElmtList*) malloc((sizeof(ElmtList)));
    if(P!=NULL){
        Info(P) = X;
        Next(P) = NULL;
    }
    return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
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
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address A;
    A = Alokasi(X);
    if(A!=NULL){
        InsertFirst(L,A);
    }
}
void InsVLast (ListBangunan *L, int X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P = Alokasi(X);
    if(P!=NULL){
        InsertLast(L,P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListBangunan *L, int *X)
/* I.S. ListBangunan L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address A;
    DelFirst(L,&A);
    *X = Info(A);
    Dealokasi(&A);
}
void DelVLast (ListBangunan *L, int *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListBangunan *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (ListBangunan *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (ListBangunan *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmpty(*L)){
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

void DelP (ListBangunan *L, int X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
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
        Dealokasi(&P);
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
void PrintInfo (ListBangunan L)
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
int NbElmt (ListBangunan L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address A = First(L);
    while(A!=NULL){
        count++;
        A = Next(A);
    }
    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : ListBangunan tidak kosong ***/
int Max (ListBangunan L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    int maks = Info(First(L));
    address A = Next(First(L));
    while(A!= NULL){ //kalo A udah nil berarti 1 elmt
        if(Info(A) > maks){
            maks = Info(A);
        }
        A = Next(A);
    }
    return maks;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (ListBangunan *L1, ListBangunan *L2, ListBangunan *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    int N;
    CreateEmpty(L3);
    while(!IsEmpty(*L1)){
        DelVFirst(L1,&N);
        InsVLast(L3,N);
    }
    while(!IsEmpty(*L2)){
        DelVFirst(L2,&N);
        InsVLast(L3,N);
    }
}