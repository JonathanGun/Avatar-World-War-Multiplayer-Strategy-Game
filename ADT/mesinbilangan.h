/* File: mesinbilangan.h */
/* Definisi Mesin Bilangan: Model Akuisisi Versi I */

#ifndef __MESINBILANGAN_H__
#define __MESINBILANGAN_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define Newline '\n'

/* State Mesin Kata */
extern boolean EndBilangan;
extern int CBilangan;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK atau */

void STARTBILANGAN();
/* I.S. : CC sembarang
   F.S. : EndBilangan = true, dan CC = MARK;
          atau EndBilangan = false, CBilangan adalah Bilangan yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Bilangan */

void ADVBILANGAN();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CBilangan adalah Bilangan terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndBilangan = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinBilangan();
/* Mengakuisisi Bilangan dan menyimpan hasilnya dalam CBilangan
   I.S. : CC adalah karakter pertama dari Bilangan
   F.S. : CBilangan berisi Bilangan yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


#endif

