/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarconfig.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen("config.txt","r");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}


void IgnoreLine()
/* Mengabaikan satu line */
{
    char ignore[1024];
    fgets(ignore,sizeof(ignore),pita);
}

boolean IsValidCharacter(char C) {
    if (
        CC == '1' || 
        CC == '2' || 
        CC == '3' || 
        CC == '4' || 
        CC == '5' ||
        CC == '6' ||
        CC == '7' ||
        CC == '8' ||
        CC == '9' ||
        CC == '0' ||
        CC == 'C' ||
        CC == 'T' ||
        CC == 'V' ||
        CC == 'F'
    ) return true;
    else return false; 
}