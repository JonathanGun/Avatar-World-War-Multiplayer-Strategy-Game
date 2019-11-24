#ifndef GAME_STACKT_H
#define GAME_STACKT_H

#include "../util/util.h"
#include "game_condition.h"

/* game_stackt adalah variabel yang menyimpan tiap kondisi permainan dalam bentuk stackt */
/* infotype game_stackt berupa GameCondition */
/* saat permainan berlangsung GameCondition yang digunakan adalah yang berada pada top stack */
/* setiap melakukan aksi, dilakukan push pada stackt untuk menyimpan kondisi permainan sebelumnya */
/* saat ingin melakukan undo, lakukan pop pada stackt untuk mengembalikan kondisi sebelumnya */
/* akan dilakukan reset pada stackt jika pemain melakukan "END_TURN" atau "SKILL" */
/* pemain tidak dapat melakukan "UNDO" jika elemen stackt hanya 1 */ 

void CreateEmptyStackt (GameStack *S);
// Membuat sebuah stackt kosong

boolean IsEmptyStackt (GameStack S);
// Menghasilkan true jika stackt kosong

void PushStackt ();
// Melakukan push info pada top stackt
// digunakan jika aksi pada permainan menyebabkan perubahan kondisi permainan

void PopStackt ();
// Menghapus elemen top pada stackt
// digunakan saat melakukan "UNDO" , untuk mengembalikan kondisi sebelumnya

void ResetStackt();
// Menghapus seluruh elemen stackt dan melakukan push elemen top sebelum penghapusan
// digunakan ketika pemain melakukan "END_TURN" atau "SKILL"

#endif