/* File : listbangunan.h */
/* contoh ADT ListBangunan berkait dengan representasi fisik pointer  */
/* Representasi queueAddress dengan pointer */
/* infotype adalah Bangunan */

#include <stdio.h>
#include "listbangunan.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST ListBangunan KOSONG ******************/
boolean IsEmptyBangunan (ListBangunan L){
    return(First(L)== Nil);
}
/* Mengirim true jika ListBangunan kosong */

/****************** PEMBUATAN ListBangunan KOSONG ******************/
void CreateEmptyBangunan (ListBangunan *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk ListBangunan kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address New = (address) malloc (sizeof(ElmtList));
    if(New != Nil){
        Info(New) = X;
        Next(New) = Nil;
        return New;
    }
    else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN ListBangunan ******************/
address Search (ListBangunan L, infotype *X){
    address P = First(L);
    while((P != Nil) && (&Info(P) != X)){
        P = Next(P);
    }
    return P;
}
/* Mencari apakah ada elemen ListBangunan dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListBangunan *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListBangunan *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListBangunan di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListBangunan *L, infotype *X){
    address P = First(*L);
    First(*L) = Next(First(*L));
    Next(P)=Nil;
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. ListBangunan L tidak kosong  */
/* F.S. Elemen pertama ListBangunan dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListBangunan *L, infotype *X){
    address prec;
    address P = First(*L);
    if(NbElmt(*L) == 1){
        *X = Info(P);
        Next(P) = Nil;
        CreateEmpty(L);
    }
    else{
        while(Next(P) != Nil){
            prec = P;
            P = Next(P);
        }
        *X = Info(P);
        Next(prec) = Nil;
        Dealokasi(&P);
    }    
}
/* I.S. ListBangunan tidak kosong */
/* F.S. Elemen terakhir ListBangunan dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListBangunan *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (ListBangunan *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen ListBangunan dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListBangunan *L, address P){
    if(IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        address Last = First(*L);
        while(Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);   
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListBangunan *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen pertama ListBangunan sebelum penghapusan */
/*      Elemen ListBangunan berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListBangunan *L, infotype *X){
    address Y = First(*L);
    address prec;
    int count = 0;
    if(!IsEmpty(*L)){
        while(&Info(Y) != X && Next(Y) != Nil){
            prec = Y;
            Y = Next(Y);
            count++;
        }
        if(&Info(Y) == X){
            if(count != 0){
                Next(prec) = Next(Y);
                Dealokasi(&Y);
            }
            else{
                if(NbElmt(*L) != 1){
                    First(*L) = Next(First(*L));
                }
                else{
                    CreateEmpty(L);
                }
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListBangunan beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ListBangunan dan di-dealokasi */
/* Jika ada lebih dari satu elemen ListBangunan dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen ListBangunan dengan Info(P)=X, maka ListBangunan tetap */
/* ListBangunan mungkin menjadi kosong karena penghapusan */
void DelLast (ListBangunan *L, address *P){
    address Last, PrecLast;

    Last = First(*L);
    PrecLast = Nil;
    while(Next(Last)!=Nil){
        PrecLast = Last;
        Last = Next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        Next(PrecLast) = Nil;
    }
}
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListBangunan sebelum penghapusan  */
/*      Elemen ListBangunan berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListBangunan *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. ListBangunan tidak kosong. Prec adalah anggota ListBangunan  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListBangunan yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListBangunan ******************/
int NbElmt (ListBangunan L){
    int count = 0;
    address Y = First(L);
    while(Y != Nil){
        Y = Next(Y);
        count++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen ListBangunan; mengirimkan 0 jika ListBangunan kosong */
