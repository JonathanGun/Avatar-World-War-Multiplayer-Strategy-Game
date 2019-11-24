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

/* Game adalah variabel  yang mengendalikan jalannya permainan */
/* memuat inisialisai */

void MainMenu(); 

void InitData();
// Inisialisasi data permainan

void InitPlayer();
// Inisialisai player
// pada awal permainan masing-masing player memiliki satu bangunan dengan id 1 dan 2
// masing-masing player memiliki satu skill instant upgrade

void InitTurn();
// Inisialisasi turn
// turn dimulai dari player pertama

void InitSave();
// Melakukan load data save

void InitGame(char* config_file);
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade

void StartGame();
// Memulai permainan

void LoadGame(int NthData);
// Load data ke-NthData

void ExitGame();
// Keluar dari permainan

boolean IsGameEnded();
// IsGameEnded true jika permainan berakhir

boolean IsPlayerLose(int player);
// IsPlayeLose(n) true jika player ke-n kalah (tidak memiliki bangunan)

#endif