#include "ADT/game/game.h"

int main (){
    init_gambar();
    char Load[5] = "LOAD";
    char Start[6] = "START";
    char Exit[5] = "EXIT";
    Kata load;
    Kata start;
    Kata EXIT;
    MakeKata(&load,Load,4);
    MakeKata(&start,Start,5);
    MakeKata(&EXIT,Exit,4);
    int i;
    Kata command;
    printf("ENTER COMMAND: ");
    InputKata(&command);
    while((CompareKata(command,load) == 0) && (CompareKata(command,start) == 0) &&(CompareKata(command,EXIT) == 0)) {
        printf("Masukan salah, tolong input kembali !\n\n");
        printf("ENTER COMMAND: ");
        InputKata(&command); 
    }
    Game main_game;
    if(CompareKata(command,load)){
        Kata loadfile;
        printf("Ketikkan nama file: "); InputKata(&loadfile);
        LoadFromFile(&main_game, loadfile);
        printf("Load berhasil!\n");
        StartGame(&main_game);
    }else if (CompareKata(command,start)){
        InitGame(&main_game);
    }else{ 
        printf("Exiting the program...\n"); 
        exit(0); 
    }
}