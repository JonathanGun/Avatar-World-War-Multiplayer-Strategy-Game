#ifndef PLAYER_H
#define PLAYER_H

#include "../util/util.h"
#include "../skill/skill.h"
#include "../bangunan/bangunan.h"
#include "../bangunan/arraydin_bangunan.h"

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

