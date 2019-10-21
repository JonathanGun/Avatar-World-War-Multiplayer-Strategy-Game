#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

#define Second(L) Next(First(L))
#define IsOneElmt(L) Second(L) == Nil

List* NextList(List *L){
	List* T = (List*) malloc(sizeof(List));
	First(*T) = Second(*L);
	return T;
}

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
queueAddress Alokasi (infotype X)
/* Mengirimkan queueAddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka queueAddress tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	queueAddress P = (queueAddress) malloc(sizeof(queueAddress)+1);
	Info(P) = X;
	Next(P) = Nil;
	return P;
}

void Dealokasi (queueAddress *P) // 4
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian queueAddress P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
queueAddress Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan queueAddress elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if(IsEmpty(L)) return Nil;
	if(Info(First(L)) == X) return First(L);
	return Search(*NextList(&L), X);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	queueAddress P = Alokasi(X);
	Next(P) = First(*L);
	First(*L) = P;
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if(IsEmpty(*L)) InsVFirst(L, X);
	else {
		List* tmp = NextList(L);
		InsVLast(tmp, X);
		Next(First(*L)) = First(*tmp);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	First(*L) = Second(*L);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	if(IsOneElmt(*L)) DelVFirst(L, X);
	else {
		List* tmp = NextList(L);
		DelVLast(tmp, X);
		Next(First(*L)) = First(*tmp);
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, queueAddress P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-queueAddress P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, queueAddress P, queueAddress Prec) // 19
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if(First(*L) == Next(Prec)) InsertFirst(L, P);
	else {
		List* tmp = NextList(L);
		InsertAfter(tmp, P, Prec);
		Next(First(*L)) = First(*tmp);
	}
}
void InsertLast (List *L, queueAddress P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(IsEmpty(*L)) InsertFirst(L, P);
	else {
		List* tmp = NextList(L);
		InsertLast(tmp, P);
		Next(First(*L)) = First(*tmp);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, queueAddress *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Second(*L);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berqueueAddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if(IsEmpty(*L)) return;
	if(Info(First(*L)) == X) {
		queueAddress P;
		DelFirst(L, &P);
	} else {
		List* tmp = NextList(L);
		DelP(tmp, X);
		Next(First(*L)) = First(*tmp);
	}
}

void DelLast (List *L, queueAddress *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	if(IsOneElmt(*L)) DelFirst(L, P);
	else {
		List* tmp = NextList(L);
		DelLast(tmp, P);
		Next(First(*L)) = First(*tmp);
	}
}

void DelAfter (List *L, queueAddress *Pdel, queueAddress Prec) // 24-26
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	if(First(*L) == Next(Prec)) DelFirst(L, Pdel);
	else {
		List* tmp = NextList(L);
		DelAfter(tmp, Pdel, Prec);
		Next(First(*L)) = First(*tmp);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) // 27
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	while(!IsEmpty(L)){
		print(Info(First(L)));
		First(L) = Second(L);
		if (!IsEmpty(L)) printf(",");
	}
	printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	if(IsEmpty(L)) return 0;
	return NbElmt(*NextList(&L))+1;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	if(IsOneElmt(L)) return Info(First(L));
	return max(Info(First(L)), Max(*NextList(&L)));
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3) // 33 37
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(L3);
	if(IsEmpty(*L1)) First(*L3) = First(*L2);
	else {
		First(*L3) = First(*L1);
		while(!IsOneElmt(*L1)) First(*L1) = Second(*L1);
		Next(First(*L1)) = First(*L2);
	}
	CreateEmpty(L1);
	CreateEmpty(L2);
}