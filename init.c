#include "compiler.h"

int main (){
    char Load[5] = "LOAD";
    char Start[6] = "START";
    char Exit[5] = "EXIT";
    Kata load;
    Kata start;
    Kata EXIT;
    MakeKata(&load,Load,4);
    MakeKata(&start,Start,5);
    MakeKata(&EXIT,Exit,4);
    char avatar[7] = "AVATAR";
    char game[6] = " GAME";
    int i;
    Kata command;
    printf("               ");
    for (i=0; i<6; i++){
        print_yellow(avatar[i]);
    }
    for (i=0; i<5; i++){
        print_green(game[i]);
    }
    printf("\n\n    Ketik \"START\" untuk memulai game\n");
    printf("Ketik \"LOAD\" jika sudah pernah save game\n");
    printf("Ketik \"EXIT\" untuk keluar dari permainan\n\n");
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
        command_Start(&main_game);
    }else{ 
        printf("Exiting the program...\n"); 
        exit(0); 
    }
}