#include "player.h"

typedef struct {
    Player* Players; // Array of player, menyimpan data player1 dan player2
    unsigned int turn;  // Bernilai 1 atau 2, yaitu id player yang sedang memiliki turn
} GameCondition;