#ifndef GAME_CONDITION_H
#define GAME_CONDITION_H

#include "../util/util.h"
#include "../player/player.h"

typedef struct {
    Player Players[2]; // Array of player, menyimpan data player1 dan player2
    unsigned int turn;  // Bernilai 1 atau 2, yaitu id player yang sedang memiliki turn
} GameCondition;

#define GcPlayer(G, n) (G).Players[n-1]

#endif