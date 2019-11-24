#include "game_condition.h"

void CopyGameConditions(GameCondition Gc, GameCondition *Go) 
/* I.S. GameConditions Gc dan Go Terdefinisi */
/* F.S. Data Gc Tersalin ke Go */
/* Menyalin data GameConditions dari Gc ke *Go */
{
    
    // salin turn
    (*Go).turn = Gc.turn;

    // salin data player
    CopyPlayer(GcPlayer(Gc, 1), &GcPlayer(*Go, 1));
    CopyPlayer(GcPlayer(Gc, 2), &GcPlayer(*Go, 2));

    // salin data bangunan
    CopyTabBangunan(Gc.ListBangunan, &(*Go).ListBangunan);
}