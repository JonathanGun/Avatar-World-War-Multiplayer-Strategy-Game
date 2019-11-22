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
void PushStackt (GameStack * S)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	GameCondition Gc = InfoTopStackt(*S);
	TopStackt(*S)++;
	InfoTopStackt(*S) = Gc; 
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackt (GameStack * S)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	TopStackt(*S)--;
}

void ResetStackt(GameStack *S) {
	CreateEmptyStackt(&(*S));
	PushStackt(S);
}

void TulisStacktTop(GameStack S) {
	GameCondition Gc = InfoTopStackt(S);
	printf("Daftar bangunan:\n");
	TulisIsiTabBangunan2();
	printf("player1 skill:\n");
	PrintAllSkill(Gc.Players[0].Skill);
	printf("player1 bangunan:\n");
	PrintList(Gc.Players[0].list_bangunan);
	printf("Att : %d\n", Gc.Players[0].AttUpActive);
	printf("Crit : %d\n", Gc.Players[0].CritHitActive);
	printf("Shield : %d\n", Gc.Players[0].ShieldActive);
	getchar();

	printf("player2 skill:\n");
	PrintAllSkill(Gc.Players[0].Skill);
	printf("player2 bangunan:\n");
	PrintList(Gc.Players[1].list_bangunan);
	printf("Att : %d\n", Gc.Players[1].AttUpActive);
	printf("Crit : %d\n", Gc.Players[1].CritHitActive);
	printf("Shield : %d\n", Gc.Players[1].ShieldActive);
}