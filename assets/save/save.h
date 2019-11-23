#ifndef SAVE_H
#define SAVE_H

#include "../util/config_reader.h"
#include "../game/game_condition.h"

#define MaxSaveData 4

typedef struct {
    GameCondition Gc;
    boolean not_empty;
    char* config_file;
} Data;

typedef struct {
    Data data[MaxSaveData+1];
    int Max;
} SaveData;

extern SaveData Save_data;

void SaveGame(int NthData);

void TulisSave();

void CheckSaveFile();

void LoadSavedGame();



#endif