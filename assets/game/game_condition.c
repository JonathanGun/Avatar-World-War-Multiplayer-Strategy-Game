#include "game_condition.h"

void CopyGameConditions(GameCondition Gc, GameCondition *Go) {
    
    // salin turn
    (*Go).turn = Gc.turn;

    // salin data player
    CopyPlayer(GcPlayer(Gc, 1), &GcPlayer(*Go, 1));
    CopyPlayer(GcPlayer(Gc, 2), &GcPlayer(*Go, 2));

    // salin data bangunan
    CopyTabBangunan(Gc.ListBangunan, &(*Go).ListBangunan);
}