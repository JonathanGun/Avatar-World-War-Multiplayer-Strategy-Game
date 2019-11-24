#ifndef GAME_CONDITION_H
#define GAME_CONDITION_H

#include "../util/util.h"
#include "../player/player.h"

#define GcPlayer(Gc, n) (Gc).Players[n-1]

/* GameCondition adalah variabel yang memuat data bangunan, player, dan turn */

void CopyGameConditions(GameCondition Gc, GameCondition *Go);
/* I.S. GameConditions Gc dan Go Terdefinisi */
/* F.S. Data Gc Tersalin ke Go */
/* Menyalin data GameConditions dari Gc ke *Go */

#endif