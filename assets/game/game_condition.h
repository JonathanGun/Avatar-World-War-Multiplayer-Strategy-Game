#ifndef GAME_CONDITION_H
#define GAME_CONDITION_H

#include "../util/util.h"
#include "../player/player.h"

#define GcPlayer(Gc, n) (Gc).Players[n-1]

void CopyGameConditions(GameCondition Gc, GameCondition *Go);

#endif