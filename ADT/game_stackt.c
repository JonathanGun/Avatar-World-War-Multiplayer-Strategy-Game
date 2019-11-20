#include "game_stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackt (GameStack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas StackMaxEl */
/* jadi indeksnya antara 1.. StackMaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai StackNil */
{
	TopStackt(*S) = StackNil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackt (GameStack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	return (TopStackt(S) == StackNil);
}
boolean IsFullStackt (GameStack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return TopStackt(S) == StackMaxEl;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackt (GameStack * S, GameCondition X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	TopStackt(*S)++;
	InfoTopStackt(*S) = X; 
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackt (GameStack * S, GameCondition* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTopStackt(*S);
	TopStackt(*S)--;
}