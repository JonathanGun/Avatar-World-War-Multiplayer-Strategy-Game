#ifndef PLAYER_H
#define PLAYER_H

#include "../util/util.h"
#include "../skill/skill.h"
#include "../bangunan/list_bangunan.h"


#define Skill(P)    (P).Skill

void CopyPlayer(Player P, Player *Po);
/* Proses = Mengcopy isi Player P ke Po*/
/* I.S. P terdefinisi */
/* F.S. Isi P tersalin ke dalam Po*/

#endif

