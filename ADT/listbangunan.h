#ifndef listbangunan_H
#define listbangunan_H

#include "util/boolean.h"
#include "bangunan.h"
#include <stdlib.h>

#define Nil NULL

typedef struct tElmtlist *address;
typedef struct tElmtlist {
	Bangunan info;
	address next;
} ElmtList;
typedef struct {
	address First;
} ListBangunan;

/* Definisi ListBangunan : */
/* ListBangunan kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListBangunan : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

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
address Alokasi (Bangunan X){
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
address Search (ListBangunan L, Bangunan *X){
    address P = First(L);
    while((P != Nil) && (&Info(P) != X)){
        P = Next(P);
    }
    return P;
}
/* Mencari apakah ada elemen ListBangunan dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */


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

#endif