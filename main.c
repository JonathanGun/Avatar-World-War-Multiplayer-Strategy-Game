#include "assets/game/game.h"
#include "assets/game/game_command.h"

Kata LOAD, START_W, EXIT;
int main (){
    gui_logo();
    
    Kata command;
    MakeCommand();
    do{
        printf(">>> ");
        InputKata(&command);
        if(!valid_command(command)){
            printf("Masukan salah, tolong input kembali!\n");
            ENDL;
        }
    } while(!valid_command(command));

    if(CompareKata(command,LOAD)){
        Kata loadfile;
        printf("Ketikkan nama file: "); InputKata(&loadfile);
        LoadFromFile(loadfile);
        StartGame();
    } else if (CompareKata(command,START_W)){
        InitGame();
        command_Start();
    } else { 
        printf("Exiting the program...\n"); 
        exit(0); 
    } 
}