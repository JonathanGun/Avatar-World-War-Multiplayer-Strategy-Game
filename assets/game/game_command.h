#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "game.h"

extern Kata ATTACK, LEVEL, SKILL, UNDO, END_TURN, SAVE, MOVE, LOAD, START_W, EXIT;

boolean valid_command(Kata input);
void MakeCommand();
boolean valid_aksi(Kata input);
void MakeAksi();
void input_between_msg(int s, int e);
boolean valid_range(int s, int x, int e);
int InputValidIntBetween(int s, int e);

boolean bangunan_same_owner(Bangunan B);
boolean bangunan_diff_owner(Bangunan B);
boolean bangunan_sudah_serang(Bangunan B);
boolean bangunan_sudah_pindah(Bangunan B);

void command_in_game();
void command_Start();
void command_Attack();
void command_Level_up();
void command_Skill();
void command_Undo();
void command_End_turn();
void command_Save();
void command_Move();
void command_Exit();

#endif