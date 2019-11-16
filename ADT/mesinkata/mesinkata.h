#ifndef __MESIN_KATA_H_
#define __MESIN_KATA_H_

#include "../boolean.h"
#include <stdio.h>

#define NMax 10000
#define BLANK ' '
#define MARK '$'

typedef struct {
	char TabKata[NMax+1];
	int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

/* State Mesin */
char CC;
boolean EOP;

static FILE * pita;
static int retval;

// MESIN KARAKTER //
void ADV(){
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) fclose(pita);
}

boolean START(char* filename) {
    EOP = false;
    if (filename == 0) {
        pita = stdin;
    } else {
        pita = fopen(filename, "r");
    }
    ADV();
    return (pita != 0);
}

boolean IsBlank() {
  return (CC == BLANK || CC == 10);
}

void IgnoreBlank(){
  while(!CC==BLANK) ADV();
}

// MESIN KATA //
boolean STARTKATA(char* filename) {
  boolean valid = (START(filename) != 0);
  if (!valid) {
    EndKata = true;
    return valid;
  }

  if (filename != 0) IgnoreBlank();

  EndKata = (CC == MARK);
  return valid;
}

void SalinKata(){
  int i = 0;
  while(!IsBlank()){
    i++;
    CKata.TabKata[i] = CC;
    ADV();
  }
  CKata.Length = i;
  EndKata = (CC == MARK);
}

void ADVKATA(){
  SalinKata();
  IgnoreBlank();
}

int Char2Int(){    
    int n = CKata.Length+1;
    char *array = CKata.TabKata;
    int number = 0;
    int mult = 1;

    while (n--) {
        if ((array[n] < '0' || array[n] > '9') && array[n] != '-') {
            if (number) break;
            else continue;
        }

        if (array[n] == '-') {
            if (number) {
                number = -number;
                break;
            }
        } else {
            number += (array[n] - '0') * mult;
            mult *= 10;
        }
    }
    return number;
}

void InputInt(int* X) {
  if(pita == stdin && EndKata) STARTKATA(0);
  ADVKATA();
  *X = Char2Int();
  if (pita == stdin) EndKata = true;
}

void InputKata(Kata* K) {
  if(pita == stdin && EndKata) STARTKATA(0);
  ADVKATA();
  for (int i = 1; i <= CKata.Length; i++) {
    (*K).TabKata[i] = CKata.TabKata[i];
  }
  (*K).TabKata[CKata.Length+1] = 0;
  (*K).Length = CKata.Length;
  if(pita == stdin) EndKata = true;
}

void PrintKata(Kata K){
  for(int i = 1; i <= K.Length; i++){
    printf("%c", K.TabKata[i]);
  }
}

#endif