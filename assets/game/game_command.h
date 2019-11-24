#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "../save/save.h"
#include "game_command_helper.h"

void get_next_command();
void command_Start();
void command_Load();
void command_Attack();
void command_Level_up();
void command_Skill();
void command_Undo();
void command_End_turn();
void command_Save();
void command_Move();
void command_Exit();

#endif