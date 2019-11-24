#include "player.h"

void CopyPlayer(Player P, Player *Po) {    
/* Proses = Mengcopy isi Player P ke Po*/
/* I.S. P terdefinisi */
/* F.S. Isi P tersalin ke dalam Po*/
    (*Po).AttUpActive = P.AttUpActive;
    (*Po).CritHitActive = P.CritHitActive;
    (*Po).ShieldActive = P.ShieldActive;
    CopyQueue(P.Skill, &(*Po).Skill);
    CopyList(P.list_bangunan, &(*Po).list_bangunan);
}