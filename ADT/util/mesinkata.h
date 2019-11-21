#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "../util/util.h"

#define NMaxKata 10000
#define BLANK ' '
#define NL '\n'
#define MARK '$'

typedef struct {
	char TabKata[NMaxKata+1];
	int Length;
} Kata;

extern boolean EndKata;
extern Kata CKata;
extern Kata Save;
extern char CC;
extern boolean EOP;

// MESIN KARAKTER //
void ADV();

boolean IsBlank();

void IgnoreBlank();

boolean START(char const *filename);

// MESIN KATA //
boolean STARTKATA(char const *filename);

void SalinKata();

void ADVKATA();

int Char2Int();

void BacaInt(int *X);

void InputInt(int* X);

void BacaKata(Kata *K);

void InputKata(Kata* K);

void PrintKata(Kata K);

void MakeKata(Kata* K, char C[], int length);

boolean CompareKata(Kata K1, Kata K2);

void PrintAll();
// MESIN SAVE 
void SalinKata_Save();

void ADVKATA_Save();

#endif