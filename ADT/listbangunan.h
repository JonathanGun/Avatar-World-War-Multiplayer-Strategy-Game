/* File : listbangunan.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah Bangunan */

#ifndef listbangunan_H
#define listbangunan_H

#include "boolean.h"
#include "bangunan.h"

#define Nil NULL

typedef Bangunan infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
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
boolean IsEmpty (ListBangunan L);
/* Mengirim true jika ListBangunan kosong */

/****************** PEMBUATAN ListBangunan KOSONG ******************/
void CreateEmpty (ListBangunan *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListBangunan kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN ListBangunan ******************/
address Search (ListBangunan L, infotype *X);
/* Mencari apakah ada elemen ListBangunan dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListBangunan *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListBangunan *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListBangunan di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListBangunan *L, infotype *X);
/* I.S. ListBangunan L tidak kosong  */
/* F.S. Elemen pertama ListBangunan dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListBangunan *L, infotype *X);
/* I.S. ListBangunan tidak kosong */
/* F.S. Elemen terakhir ListBangunan dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListBangunan *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (ListBangunan *L, address P, address Prec);
/* I.S. Prec pastilah elemen ListBangunan dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListBangunan *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListBangunan *L, address *P);
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen pertama ListBangunan sebelum penghapusan */
/*      Elemen ListBangunan berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListBangunan *L, infotype *X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListBangunan beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ListBangunan dan di-dealokasi */
/* Jika ada lebih dari satu elemen ListBangunan dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen ListBangunan dengan Info(P)=X, maka ListBangunan tetap */
/* ListBangunan mungkin menjadi kosong karena penghapusan */
void DelLast (ListBangunan *L, address *P);
/* I.S. ListBangunan tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListBangunan sebelum penghapusan  */
/*      Elemen ListBangunan berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListBangunan *L, address *Pdel, address Prec);
/* I.S. ListBangunan tidak kosong. Prec adalah anggota ListBangunan  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListBangunan yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListBangunan ******************/
int NbElmt (ListBangunan L);
/* Mengirimkan banyaknya elemen ListBangunan; mengirimkan 0 jika ListBangunan kosong */


#endif