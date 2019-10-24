/* File: player.h */
/* Definisi ADT player */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "skill.h"
#include "bangunan.h"
#include "listbangunan.h"
#include <stdio.h>

typedef struct {
	Queue Skill; /* Skill yang dimiliki player */
	ListBangunan X;
} Player;

#define Skill(P)    (P).Skill
#define Bangunan(P)    (P).Bangunan

void startTurn(Player P);
/* Digunakan ketika startTurn seorang Player untuk menambahkan pasukan setiap bangunan yang dimiliki player s*/

void printDaftarbangunan(Player P);
/* Menampilkan Daftar bangunan yang dimiliki Player */

#endif

