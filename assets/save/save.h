#ifndef SAVE_H
#define SAVE_H

#include "../util/config_reader.h"
#include "../game/game_condition.h"

typedef struct {
    GameCondition Gc;
    char* config_file;
} Data;

typedef struct {
    Data data[10];
    int Length;
} SaveData;

extern SaveData Save_data;

void SaveGame();

void TulisSave();

int CountSave(const char* savefile);

void NthSave(const char* savefile, int *N);

void LoadSavedGame(const char* savefile);


#endif