#ifndef LISTBANGUNAN_H
#define LISTBANGUNAN_H

#include "../util/util.h"
#include "bangunan.h"

/* STRUKTUR ADT */
/* Definisi ListBangunan : */
/* ListBangunan kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListBangunan : jika addressnya Last, maka Next(Last)=Nil */

/* SELEKTOR */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* SELEKTOR (TAMBAHAN) */
int NbList(ListBangunan L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbListType(ListBangunan L,char c);
/* Mengirimkan banyaknya elemen list dengan tipe bangunan c; mengirimkan 0 jika list kosong */
int ListElmt(ListBangunan L, int n);
// Selektor untuk ListBangunan, bekerja seperti array L indeks ke n (L[n])

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (ListBangunan *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address AlokasiList (int X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiList (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (ListBangunan L);
/* Mengirim true jika list kosong */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList (ListBangunan L, int X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/*** PENAMBAHAN ELEMEN ***/
void InsertList (ListBangunan *L, int X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/* PENGHAPUSAN ELEMEN */
void DelList (ListBangunan *L, int X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListBangunan mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintList(ListBangunan L);
/* I.S. ListBangunan mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

/*********************** OPERASI LAIN ***********************/
void CopyList(ListBangunan L, ListBangunan *Lo); 
/* I.S. L terdefinisi (boleh kosong), Lo sembarang */
/* F.S. Lo identik dengan L tapi bukan ListBangunan yang sama */
void FilterListTanpa(ListBangunan* L, boolean (*f)(Bangunan));
// Memfilter L dimana semua elemennya tidak ada yg true jika dijadikan parameter fungsi f
// I.S: L terdefinisi (bisa kosong)
// F.S: L terfilter sesuai definisi
void ResetListBangunan();
// Mengembalikan status sudahserang dan sudahpindah pada list bangunan milik player saat ini

#endif