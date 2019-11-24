#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == QueueNil) && (Tail(Q) == QueueNil);
}

boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak QueueMaxEl */
{
	return !(Head(Q) - (Tail(Q)%QueueMaxEl(Q)) - 1);
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
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


/* *** Primitif Add/Delete *** */
boolean Add (Queue * Q, int X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if (IsEmptyQueue(*Q)){
		Head(*Q)=1;
		Tail(*Q)++;
		InfoTail(*Q)=X;
	}else{
		if(!IsFullQueue(*Q)){
			if(Tail(*Q) == QueueMaxEl(*Q)) Tail(*Q) = 1;
			else Tail(*Q)++;
			InfoTail(*Q)=X;
			return true;
		}else{
			printf("Kapasitas Skill sudah mencapai maksimum tidak dapat bertambah lagi !");ENDL;
			return false;
		}
	}
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

void CopyQueue(Queue Q, Queue * Qo) {
/* Proses: Membuat salinan Q ke Qo
   I.S. Q terdefinisi
   F.S. isi Queue di Q tersalin ke Qo*/
	CreateEmptyQueue(Qo, Q.MaxEl);
	int X;
	while ( !IsEmptyQueue(Q) ) {
		Del(&Q, &X);
		Add(Qo, X);
	}
}

int CountQueue(Queue Q) {
/* Proses: Mendapatkan banyaknya isi Q dan mendelete isi Q
   I.S. Q terdefinisi
   F.S. isi Q di delete dan menghasilkan banyaknya queue*/
	int X, Count;
	Count = 0;
	while ( !IsEmptyQueue(Q) ) {
		Del(&Q, &X);
		Count++;
	}
	return Count;
}