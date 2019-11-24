#include "game_stackt.h"

void CreateEmptyStackt (GameStack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah GameStack S yang kosong berkapasitas StackMaxEl */
/* Membuat sebuah stackt kosong : TopStackt bernilai Nil */
{
	TopStackt(*S) = 0;
}

boolean IsEmptyStackt (GameStack S)
/* Mengirim true jika Stack kosong: TopStackt bernilai Nil */
{
	return (TopStackt(S) == 0);
}

void PushStackt ()
/* Melakukan push info pada top stackt */
/* Digunakan jika aksi pada permainan menyebabkan perubahan kondisi permainan */
{
	GameCondition newGc;
	CopyGameConditions(InfoTopStackt(G.GameConditions), &newGc);
	TopStackt(G.GameConditions)++;
	InfoTopStackt(G.GameConditions) = newGc; 
}

void PopStackt ()
/* Menghapus elemen top pada stackt */
/* Digunakan saat melakukan "UNDO" , untuk mengembalikan kondisi sebelumnya */
{
	TopStackt(G.GameConditions)--;
}

void ResetStackt() 
/* Menghapus seluruh elemen stackt dan melakukan push elemen top sebelum penghapusan */
/* Digunakan ketika pemain melakukan "END_TURN" atau "SKILL" */
{
	G.GameConditions.T[0] = InfoTopStackt(G.GameConditions);
	TopStackt(G.GameConditions) = 0;
}