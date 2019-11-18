/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "mesinconfig.h"
#include <stdio.h>

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%c", a)
#define prints(a)     printf("%c ", a)
#define ENDL          printf("\n")

#define forall(i) for(int i = 1; i <= CKata.Length; i++)
#define printkata() forall(i) print(CKata.TabKata[i])

boolean EndToken = false;
Token CConfig;

void IgnoreNotValidCharacter()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while ( !IsValidCharacter(CC) ) ADV();
}

void STARTCONFIG( int LineNumber )
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START();

  int i;
  for ( i = 1; i < LineNumber; i++ ) {
    IgnoreLine();
  }

  IgnoreNotValidCharacter();
  ADVKATACONFIG();
}

void ADVKATACONFIG()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  if(CC == MARK) EndToken = true;
  else {
    SalinKataConfig();
    IgnoreNotValidCharacter();
  }
}

void SalinKataConfig()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  CConfig.Bil = 0;
  CConfig.Val = ValUndef;
  while ( IsValidCharacter(CC) ) {
    printf("salin : %c\n",CC);
    if ( CC == 'C' || CC == 'T' || CC == 'V' || CC == 'F' ) {
      CConfig.Val = CC;
      CConfig.Bil = BilUndef;
    } else {
      CConfig.Bil = CConfig.Bil*10 + (CC-'0');
    }
    ADV();
  }
}