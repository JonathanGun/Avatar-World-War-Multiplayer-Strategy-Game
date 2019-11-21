#include "compiler.h"

void command_in_game(Game* G){
    char Attack[7] = "ATTACK";
    char Level[9] = "LEVEL_UP";
    char Skill[6] = "SKILL";
    char Undo[5] = "UNDO";
    char End[9] = "END_TURN";
    char Save[5] = "SAVE";
    char Move[5] = "MOVE";
    char Exit[5] = "EXIT";
    Kata attack;
    Kata level;
    Kata skill;
    Kata undo;
    Kata end;
    Kata save;
    Kata move;
    Kata EXIT;
    MakeKata(&attack,Attack,6);
    MakeKata(&level,Level,8);
    MakeKata(&skill,Skill,5);
    MakeKata(&undo,Undo,4);
    MakeKata(&end,End,8);
    MakeKata(&save,Save,4);
    MakeKata(&move,Move,4);
    MakeKata(&EXIT,Exit,4);
    
    TulisPeta((*G).ListBangunan, (*G).map);
    printf("Player "); print(CurTurn(*G)); ENDL;
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan((*G).ListBangunan, CurPlayer(*G).list_bangunan);
    TulisSkill(CurPlayer(*G).Skill);
    printf("ENTER COMMAND: ");
    Kata command;
    InputKata(&command);
    
    while((CompareKata(command,attack) == 0) && (CompareKata(command,level) == 0) &&(CompareKata(command,skill) == 0)
    && (CompareKata(command,undo) == 0) && (CompareKata(command,end) == 0) && (CompareKata(command,save) == 0)
    && (CompareKata(command,move) == 0) && (CompareKata(command,EXIT) == 0)) {
        printf("Masukan salah, tolong input kembali !\n");
        printf("Berikut daftar Command yang dapat digunakan:\n");
        printf("ATTACK\nLEVEL_UP\nSKILL\nUNDO\nEND_TURN\nSAVE\nMOVE\nEXIT\n\n");
        printf("ENTER COMMAND: ");
        InputKata(&command);
    }
    if(CompareKata(command,attack)){
        command_Attack(G);
    }else if (CompareKata(command,level)){
        command_Level_up(G);
    }else if (CompareKata(command,skill)){
        command_Skill(G);
        printf("Skill Berhasil\n");
    }else if (CompareKata(command,undo)){
        command_Undo(G);
        printf("Undo berhasil\n");
    }else if (CompareKata(command,end)){
        command_End_turn(G);
        // printf("End Turn berhasil\n");
    }else if (CompareKata(command,save)){
        command_Save(G);
        printf("Save berhasil\n");
    }else if (CompareKata(command,move)){
        command_Move(G);
        printf("Move Berhasil\n");
    }else{ //Ketika menulis EXIT
        printf("Exiting the program...\n"); 
        exit(0); 
    }
}