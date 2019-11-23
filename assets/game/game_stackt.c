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
void PushStackt ()
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	GameCondition newGc;
	CopyGameConditions(InfoTopStackt(G.GameConditions), &newGc);
	TopStackt(G.GameConditions)++;
	InfoTopStackt(G.GameConditions) = newGc; 
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackt ()
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	TopStackt(G.GameConditions)--;
}

void ResetStackt() {
	G.GameConditions.T[1] = InfoTopStackt(G.GameConditions);
	TopStackt(G.GameConditions) = 0;
}

void TulisStacktTop() {
	GameCondition Gc = InfoTopStackt(G.GameConditions);
	printf("Daftar bangunan:\n");
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