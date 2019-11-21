#ifndef SAVE_H
#define SAVE_H

#include "../util/mesinfile.h"
#include "../game/game_condition.h"

void SaveGame(GameCondition Gc, TabBangunan list_bangunan, int Turn);

// void LoadGame(const char* savefile, GameCondition *G);

#endif