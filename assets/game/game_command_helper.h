#ifndef GAMECOMMANDHELPER_H
#define GAMECOMMANDHELPER_H

#include "../util/util.h"
#include "../util/mesinkata.h"
#include "../skill/skill.h"

extern Kata ATTACK, LEVEL, SKILL, UNDO, END_TURN, SAVE, MOVE, LOAD, START_W, EXIT;

void MakeCommand();
// Konstruktor command yaitu laod start dan exit
void MakeAksi();
// Konstruktor aksi yaitu attack,skill, level_up, undo, end_turn, save, dan move
boolean valid_command(Kata input);
// Mengembalikan apakah input adalah command yang valid (load/start/exit)
boolean valid_aksi(Kata input);
// Mengembalikan apakah input adalah aksi yang valid (attack/level_up/skill/undo/end_turn/save/move/exit)
void input_between_msg(int s, int e);
// menampilkan pesan untuk menginput angka antara s dan e (inklusif)
boolean valid_range(int s, int x, int e);
// mengembalikan apakah x berada di antara s dan e (inklusif)
int InputValidIntBetween(int s, int e);
// mengembalikan input angka yang telah divalidasi (di antara s dan e)
boolean bangunan_same_owner(Bangunan B);
// mengembalikan true jika B milik pemain saat ini
boolean bangunan_diff_owner(Bangunan B);
// mengembalikan true jika B bukan milik pemain saat ini
boolean bangunan_sudah_serang(Bangunan B);
// mengembalikan true jika B sudah menyerang di turn ini 
boolean bangunan_sudah_pindah(Bangunan B);
// mengembalikan true jika B sudah pindah pasukan di turn ini
boolean bangunan_level_maks(Bangunan B);
// mengembalikan true jika B sudah memiliki level maksimal
void wait_next_command();
// Menampilkan pesan bahwa game menunggu input ENTER dari user
void TriggerSkill();
// I.S. kondisi skill player sembarang
// F.S. kondisi skill player terupdate setelah end_turn

#endif