#ifndef PLAYER_H
#define PLAYER_H

#include "util/boolean.h"
#include "skill.h"
#include "bangunan.h"
#include "arraydin_bangunan.h"
#include <stdio.h>

typedef struct {
	Queue Skill; /* Skill yang dimiliki player */
	ListBangunan list_bangunan;
} Player;

#define Skill(P)    (P).Skill

void startTurn(Player P);
/* Digunakan ketika startTurn seorang Player untuk menambahkan pasukan setiap bangunan yang dimiliki player s*/

void printDaftarbangunan(Player P);
/* Menampilkan Daftar bangunan yang dimiliki Player */

#endif

