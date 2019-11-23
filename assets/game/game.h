#ifndef GAME_H
#define GAME_H

#include "../util/util.h"
#include "../util/gui.h"
#include "../peta/peta.h"
#include "../bangunan/list_bangunan.h"
#include "../bangunan/arraydin_bangunan.h"
#include "../game/game_stackt.h"
#include "../util/config_reader.h"
#include "game_command.h"

void InitData();

void InitPlayer();

void InitTurn();

void InitSave();

void InitData();

void InitGame(const char* config_file);
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade

// void SaveGame();
// void LoadGame();
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void LoadFromFile(Kata filename);

void StartGame();
void LoadGame(int NthData);

// Memulai permainan
void ExitGame();

boolean IsGameEnded();
boolean IsPlayerLose(int player);

#endif