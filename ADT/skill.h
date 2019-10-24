/* File: skill.h */
/* Definisi ADT Skill */


#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "queue.h"
#include <stdio.h>

/* *** Add/Delete Skill *** */
void startSkill(Queue *Skill);
/* Kondisi Awal yaitu mempunyai Queue dengan skill Instant Upgrade */

void useSkill(Queue Skill);
/* Menggunakan Skill sesuai Head dari queue*/

/****************** PROSES SKILL ******************/
void printSkill(Queue Skill);
/* Mengeprint Skill di bagian Head Queue*/

void useSkill(Queue Skill);
/* Menggunakan Skill sesuai Head dari queue*/

void useIU();
/* Menggunakan Skill IU, Seluruh bangunan yang dimiliki pemain akan naik 1 level.*/

void useShield();
/* Menggunakan Skill Shield, Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
   turn.*/

void useExtraTurn();
/* Menggunakan Skill ExtraTurn, Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
   yang sama.*/

void useAttackUp();
/* Menggunakan Skill Attack Up, Pada giliran ini, setelah skill ini diaktifkan, 
   pertahanan bangunan musuh tidak akan mempengaruhi penyerangan.*/

void useCriticalHit();
/* Menggunakan Skill Critical Hit, Pada giliran ini, setelah skill diaktifkan, jumlah 
   pasukan pada bangunan yang melakukan serangan tepat selanjutnya 
   hanya berkurang ½ dari jumlah seharusnya.*/

void useInstantReinforcement();
/* Menggunakan Skill Instant Reinforcement, Seluruh bangunan mendapatkan tambahan 5 pasukan.*/

void useBarrage();
/* Menggunakan Skill Barrage, Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
   pasukan.*/

#endif

