#include "assets/game/game.h"

Kata LOAD, START_W, EXIT;
int main (){

    InitData();

    gui_logo();
    
    Kata command;
    MakeCommand();
    do{
        printf(">>> ");
        InputKata(&command);
        if(!valid_command(command)){
            printf("Masukan salah, tolong input kembali!\n"); ENDL;
        }
    } while(!valid_command(command));

    if(CompareKata(command,LOAD)){
        command_Load();
    } else if (CompareKata(command,START_W)){
        command_Start();
    } else { 
        ExitGame();
    } 
}