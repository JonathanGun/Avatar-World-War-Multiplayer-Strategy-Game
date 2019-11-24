#ifndef GAME_STACKT_H
#define GAME_STACKT_H

#include "../util/util.h"
#include "game_condition.h"

/* game_stackt adalah variabel yang menyimpan tiap kondisi permainan dalam bentuk stackt */
/* Infotype game_stackt berupa GameCondition */
/* Saat permainan berlangsung GameCondition yang digunakan adalah yang berada pada top stack */
/* Setiap melakukan aksi, dilakukan push pada stackt untuk menyimpan kondisi permainan sebelumnya */
/* Saat ingin melakukan undo, lakukan pop pada stackt untuk mengembalikan kondisi sebelumnya */
/* Akan dilakukan reset pada stackt jika pemain melakukan "END_TURN" atau "SKILL" */
/* Pemain tidak dapat melakukan "UNDO" jika elemen stackt hanya 1 */ 

void CreateEmptyStackt (GameStack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah GameStack S yang kosong berkapasitas StackMaxEl */
/* Membuat sebuah stackt kosong : TopStackt bernilai Nil */

boolean IsEmptyStackt (GameStack S);
/* Mengirim true jika Stack kosong: TopStackt bernilai Nil */

void PushStackt ();
/* Melakukan push info pada top stackt */
/* digunakan jika aksi pada permainan menyebabkan perubahan kondisi permainan */

void PopStackt ();
/* Menghapus elemen top pada stackt */
/* digunakan saat melakukan "UNDO" , untuk mengembalikan kondisi sebelumnya */

void ResetStackt();
/* Menghapus seluruh elemen stackt dan melakukan push elemen top sebelum penghapusan */
/* digunakan ketika pemain melakukan "END_TURN" atau "SKILL" */

#endif