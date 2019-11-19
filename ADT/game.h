#ifndef GAME_H
#define GAME_H

#include "peta.h"
#include "listbangunan.h"
#include "game_stackt.h"
#include "baca_config/config_reader.h"

typedef struct {
    Peta map; // Menyimpan peta
    Bangunan* ListBangunan; // Array of bangunan, menyimpan data bangunan
    GameStack GameConditions; // Stackt of GameCondition, menyimpan kondisi dari setiap aksi dilakukan (dikosongkan setelah endturn)
} Game;
// GameCondition yang digunakan adalah yang berada di Top
// setiap melakukan aksi lakukan Push pada stackt
// saat melakukan UNDO lakukan Pop pada stackt 

#define P1(G) InfoTop((G).GameConditions).Players[0]
#define P2(G) InfoTop((G).GameConditions).Players[1]

void InitGame(Game* G);
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade

void InitPlayer(Game *G, Config conf);

void InitMap(Game *G, Config conf)

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void Start(Game* G);
// Memulai permainan

// Command
void command_Attack();
void command_Level_up();
void command_Skill();
void command_Undo();
void command_End_turn();
void command_Save();
void command_Move();

#endif