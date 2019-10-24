

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "peta.h"
#include "Bangunan.h"
#include "stackt.h"

typedef struct {
    Player* Players; // Array of player, menyimpan data player1 dan player2
    unsigned int turn;  // Bernilai 1 atau 2, yaitu id player yang sedang memiliki turn
} GameCondition;

typedef struct {
    Peta map; // Menyimpan peta
    Bangunan* ListBangunan; // Array of bangunan, menyimpan data bangunan
    stackt GameCondition; // Stackt of GameCondition, menyimpan kondisi dari setiap aksi dilakukan (dikosongkan setelah endturn)
} Game;
// GameCondition yang digunakan adalah yang berada di Top
// setiap melakukan aksi lakukan Push pada stackt
// saat melakukan UNDO lakukan Pop pada stackt 

void Init(Game* G);
// Membaca file config dan menginisialisasi attribut pada Game G

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void Start(Game* G);
// Memulai permainan


#endif