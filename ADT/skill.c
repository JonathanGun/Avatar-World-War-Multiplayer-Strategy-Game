/* File: skill.c */
/* Definisi ADT Skill */

#include <stdio.h>
#include "skill.h"
#include "player.h"
#include "listbangunan.h"

/* *** Add/Delete Skill *** */
void startSkill(Queue *Skill)
/* Kondisi Awal yaitu mempunyai Queue dengan skill Instant Upgrade */
{
    CreateEmpty(Skill, 10);// Maksimal 10 skill
    Add(Skill,1); //1 sebagai IU(instant Upgrade)
}

void useSkill(Player *P)
/* Menggunakan Skill sesuai Head dari queue*/
{
    int x;
    Del(&Skill(*P), &x);
    if(x == 1){         //Using IU
        useIU(P);
    }
    else if (x ==2){    //Using Shield
        useShield;
    }
    else if (x == 3){   //Using Extra Turn
        useExtraTurn;
    }
    else if (x == 4){   //Using Attack Up
        useAttackUp;
    }
    else if (x == 5){   //Using Critical Hit
        useCriticalHit;
    }
    else if (x == 6){   //Using Instant Reinforcement
        useInstantReinforcement;
    }
    else if (x == 7){   //Using Barrage
        useBarrage;
    }
}

/****************** PROSES SKILL ******************/
void printSkill(Queue Skill)
/* Mengeprint Skill di bagian Head Queue*/
{
    int x;
    if (IsEmpty(Skill))
    {
        printf("-");
    }
    else /*  not IsEmpty */
    {
        Del(&Skill, &x);
        if(x == 1){
            printf("IU");
        }
        else if (x ==2){
            printf("Shield");
        }
        else if (x == 3){
            printf("Extra Turn");
        }
        else if (x == 4){
            printf("Attack Up");
        }
        else if (x == 5){
            printf("Critical Hit");
        }
        else if (x == 6){
            printf("Instant Reinforcement");
        }
        else if (x == 7){
            printf("Barrage");
        }
        Add(&Skill,x);
    }
}

void useIU(Player *P)
/* Menggunakan Skill IU, Seluruh bangunan yang dimiliki pemain akan naik 1 level.*/
{
    while(First(ListBangunan(*P))!=Nil){
        levelup(Info(First(ListBangunan(*P))));
        First(ListBangunan(*P)) = Next(First(ListBangunan(*P)));
    }
}

void useShield();
/* Menggunakan Skill Shield, Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
   turn lawan.*/

void useExtraTurn();
/* Menggunakan Skill ExtraTurn, Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
   yang sama.*/

void useAttackUp();
/* Menggunakan Skill Attack Up, Pada giliran ini, setelah skill ini diaktifkan, 
   pertahanan bangunan musuh(termasuk Shield) tidak akan mempengaruhi penyerangan.*/

void useCriticalHit();
/* Menggunakan Skill Critical Hit, Pada giliran ini, setelah skill diaktifkan, jumlah 
   pasukan pada bangunan yang melakukan serangan tepat selanjutnya a (hanya berlaku 1 serangan) 
   hanya efektif sebanyak 2 kali lipat pasukan. Skill ini akan menonaktifkan Shield 
   maupun pertahanan bangunan, seperti Attack Up.*/

void useInstantReinforcement();
/* Menggunakan Skill Instant Reinforcement, Seluruh bangunan mendapatkan tambahan 5 pasukan.*/

void useBarrage();
/* Menggunakan Skill Barrage, Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
   pasukan.*/
