/* File: mesintoken.c */
/* Definisi Mesin Bilangan: Model Akuisisi Versi I */

//#define NMax 50
//#define BLANK ' '
#include "mesinbilangan.h"
#include <stdio.h>

/* State Mesin Kata */
boolean EndBilangan;
char CC;
int CBilangan;

void IgnoreBlank(){
	while((CC == BLANK||CC == Newline) && CC!=MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTBILANGAN(){
	START();
    IgnoreBlank();
	if(CC == MARK){
		EndBilangan = true;
	}
	else{
		EndBilangan = false;
		SalinBilangan();
    }
}
/* I.S. : CC sembarang
   F.S. : EndBilangan = true, dan CC = MARK;
          atau EndBilangan = false, CBilangan adalah Bilangan yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Bilangan */

void ADVBILANGAN(){
	IgnoreBlank();
    if(CC == MARK){
        EndBilangan = true;
    } 
    else{
        SalinBilangan();
        IgnoreBlank();
    }    
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CBilangan adalah Bilangan terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndBilangan = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinBilangan(){
	int a = 0;
    while((CC!=MARK) && (CC!= BLANK) && (CC!= Newline)){
        CBilangan = a*10 + (CC-'0');
        a = CBilangan;
        ADV();
	}
}
/* Mengakuisisi Bilangan dan menyimpan hasilnya dalam CBilangan
   I.S. : CC adalah karakter pertama dari Bilangan
   F.S. : CBilangan berisi Bilangan yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
