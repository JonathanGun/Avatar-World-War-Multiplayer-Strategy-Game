/* File: player.h */
/* Definisi ADT player */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "skill.h"
#include "bangunan.h"
#include <stdio.h>

typedef struct {
	Queue Skill; /* Skill yang dimiliki player */
	Bangunan X;
} Player;

#define Skill(P)    (P).Skill
#define Bangunan(P)    (P).Bangunan

#endif

