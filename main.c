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
        LoadGame(1);
        // InitGame("resources/config.txt");
        StartGame();
    } else if (CompareKata(command,START_W)){
        InitGame("resources/config.txt");
        command_Start();
    } else { 
        ExitGame();
    } 
}