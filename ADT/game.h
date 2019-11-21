#ifndef GAME_H
#define GAME_H

#include "peta.h"
#include "listbangunan.h"
#include "arraydin_bangunan.h"
#include "game_stackt.h"
#include "baca_config/config_reader.h"

typedef struct {
    Peta map; // Menyimpan peta
    TabBangunan ListBangunan; // Array of bangunan, menyimpan data bangunan
    Graph Relasi;
    GameStack GameConditions; // Stackt of GameCondition, menyimpan kondisi dari setiap aksi dilakukan (dikosongkan setelah endturn)
} Game;
// GameCondition yang digunakan adalah yang berada di Top
// setiap melakukan aksi lakukan Push pada stackt
// saat melakukan UNDO lakukan Pop pada stackt 

#define Player(G, n) InfoTopStackt((G).GameConditions).Players[n-1]
#define CurTurn(G) InfoTopStackt((G).GameConditions).turn
#define OtherTurn(G) ((InfoTopStackt((G).GameConditions).turn)%2)+1
#define CurPlayer(G) Player((G), CurTurn((G)))
#define OtherPlayer(G) Player((G), OtherTurn((G)))

void InitGame(Game* G);
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade

void InitPlayer(Game* G);

void InitMap(Game* G, Config conf);

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void LoadFromFile(Game* G, Kata filename);

void StartGame(Game* G);
// Memulai permainan

// Command
void command_Start(Game *G);
void command_in_game(Game* G);
void command_Attack(Game* G);
void command_Level_up(Game* G);
void command_Skill(Game* G);
void command_Undo(Game* G);
void command_End_turn(Game* G);
void command_Save(Game* G);
void command_Move(Game* G);

boolean IsGameEnded(Game G);
boolean IsPlayerLose(Game G, int player);

#endif