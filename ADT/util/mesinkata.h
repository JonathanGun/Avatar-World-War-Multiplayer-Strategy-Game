#ifndef __MESIN_KATA_H_
#define __MESIN_KATA_H_

#include "boolean.h"
#include "macro.h"
#include <stdio.h>

#define NMaxKata 10000
#define BLANK ' '
#define NL '\n'
#define MARK '$'

typedef struct {
	char TabKata[NMaxKata+1];
	int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

/* State Mesin */
char CC;
boolean EOP;
boolean FirstTimeLoad = true;

static FILE * pita;
static int retval;

// MESIN KARAKTER //
void ADV(){
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) fclose(pita);
}

boolean IsBlank() {
  return CC == BLANK || CC == NL;
}

void IgnoreBlank(){
  while(IsBlank()) ADV();
}

boolean START(char* filename) {
    EOP = false;
    if (filename == 0) pita = stdin;
    else pita = fopen(filename, "r");
    if(FirstTimeLoad){
      FirstTimeLoad = false;
      ADV();
    } 
    return (pita != 0);
}

// MESIN KATA //
boolean STARTKATA(char* filename) {
  boolean valid = (START(filename) != 0);
  if (!valid) {
    EndKata = true;
    return valid;
  }

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
}

void ADVKATA(){
  IgnoreBlank();
  SalinKata();
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

void BacaInt(int *X){
  ADVKATA();
  *X = Char2Int();
}

void InputInt(int* X) {
  STARTKATA(0);
  BacaInt(X);
}

void BacaKata(Kata *K){
  ADVKATA();
  for (int i = 1; i <= CKata.Length; i++) {
    (*K).TabKata[i] = CKata.TabKata[i];
  }
  (*K).TabKata[CKata.Length+1] = 0;
  (*K).Length = CKata.Length+1;
}

void InputKata(Kata* K) {
  STARTKATA(0);
  BacaKata(K);
}

void PrintKata(Kata K){
  for(int i = 1; i <= K.Length; i++){
    printf("%c", K.TabKata[i]);
  }
}

void MakeKata(Kata* K, char C[], int length){
  (*K).Length = length+1;
  for (int i = 1; i < length+1; i++){
    (*K).TabKata[i] = C[i-1];
  }
}

boolean CompareKata(Kata K1, Kata K2){
  if(K1.Length != K2.Length) return false;
  for(int i = 1; i <= K1.Length; i++){
    if(K1.TabKata[i] != K2.TabKata[i]) return false;
  }
  return true;
}

#endif