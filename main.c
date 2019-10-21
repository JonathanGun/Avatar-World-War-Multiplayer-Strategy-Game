// Tubes Alstrukdat K3 - Kelompok 1
// Dibuat oleh:
// 0. Nama - NIM
// 1.
// 2.
// 3.
// 4.
// 5.

// g++ main.c ADT/point.c ADT/arraydinpos.c ADT/matriks.c ADT/mesinkata.c ADT/mesinkar.c ADT/queue.c ADT/stackt.c ADT/listlinier.c ADT/game.c -lm
// ADT/graph.c ADT/bangunan.c ADT/player.c ADT/peta.c ADT/skill.c

// Import Dependencies
#include <stdio.h>
#include <stdlib.h>
#include "ADT/boolean.h"

#include "ADT/point.h"
#include "ADT/arraydinpos.h"
#include "ADT/matriks.h"
#include "ADT/mesinkata.h"
#include "ADT/queue.h"
#include "ADT/stackt.h"
#include "ADT/listlinier.h"
#include "ADT/peta.h"
#include "ADT/player.h"
#include "ADT/game.h"
#include "ADT/skill.h"

// Macros
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {auto tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define ENDL          printf("\n")

// Algorithm
int main(){
	Game game;
	Init(game);
	Start(game);

	return 0;
}