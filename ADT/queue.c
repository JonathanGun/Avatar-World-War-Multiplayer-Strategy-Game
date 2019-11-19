#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == QueueNil) && (Tail(Q) == QueueNil);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak QueueMaxEl */
{
	return !(Head(Q) - (Tail(Q)%QueueMaxEl(Q)) - 1);
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if(IsEmpty(Q)) return 0;
	if(IsFull(Q)) return QueueMaxEl(Q);
	return ((Tail(Q) - Head(Q) + 1) % QueueMaxEl(Q));
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg QueueMaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (int*) malloc ((Max+1) * sizeof(int));
	QueueMaxEl(*Q) = Max;
	Head(*Q) = QueueNil;
	Tail(*Q) = QueueNil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, QueueMaxEl(Q) diset 0 */
{
	QueueMaxEl(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, int X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if (IsEmpty(*Q)) Head(*Q)=1;
	if(Tail(*Q) == QueueMaxEl(*Q)) Tail(*Q) = 1;
	else Tail(*Q)++;
	InfoTail(*Q)=X;
}

void Del (Queue * Q, int * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
		Head(*Q)=QueueNil;
		Tail(*Q)=QueueNil;
	} else {
		if (Head(*Q) > QueueMaxEl(*Q)) Head(*Q) = 1;
		else Head(*Q)++;
	}
}