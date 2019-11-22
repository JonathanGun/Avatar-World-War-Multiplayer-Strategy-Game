#ifndef SAVE_H
#define SAVE_H

#include "../util/mesinfile.h"
#include "../game/game_condition.h"

typedef struct {
    GameCondition data[4];
    TabBangunan TB;
    int Length;
} Save;

extern Save Saves;

void SaveGame(GameCondition Gc, TabBangunan list_bangunan);

void TulisSave(Save S);

int CountSave(const char* savefile);

void NthSave(const char* savefile, int *N);

void LoadSavedGame(const char* savefile);

void LoadGame(const char* savefile, GameCondition *G, TabBangunan *TB, int N);


#endif