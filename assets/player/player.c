#include "player.h"

void CopyPlayer(Player P, Player *Po) {
    (*Po).AttUpActive = P.AttUpActive;
    (*Po).CritHitActive = P.CritHitActive;
    (*Po).ShieldActive = P.ShieldActive;
    CopyQueue(P.Skill, &(*Po).Skill);
    CopyList(P.list_bangunan, &(*Po).list_bangunan);
}