#include "game_condition.h"

void CopyGameConditions(GameCondition Gc, GameCondition *Go) {
    // *Go = Gc;
    (*Go).turn = Gc.turn;
    CopyPlayer(GcPlayer(Gc, 1), &GcPlayer(*Go, 1));
    CopyPlayer(GcPlayer(Gc, 2), &GcPlayer(*Go, 2));
    CopyTabBangunan(Gc.ListBangunan, &(*Go).ListBangunan);
}