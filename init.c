#include "ADT/util/pcolor.c"
#include "ADT/util/mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

int main (){
    char Load[4] = "LOAD";
    char Start[5] = "START";
    Kata load;
    Kata start;
    MakeKata(&load,Load,4);
    MakeKata(&start,Start,5);
    char avatar[6] = "AVATAR";
    char game[5] = " GAME";
    int i;
    Kata command;
    printf("               ");
    for (i=0; i<6; i++){
        print_yellow(avatar[i]);
    }
    for (i=0; i<5; i++){
        print_blue(game[i]);
    }
    printf("\n\n    Ketik \"START\" untuk memulai game\nJika sudah pernah save file ketik \"LOAD\"\n\n");
    printf("ENTER COMMAND: ");
    InputKata(&command); 
    while((CompareKata(command,load) == false) && (CompareKata(command,start) == false)) {
        printf("Masukan salah, tolong input kembali !\n\n");
        printf("ENTER COMMAND: ");
        InputKata(&command); 
    }
    if(CompareKata(command,load)) printf("Load berhasil masukkan file loadmu");
    else printf("new game berhasil");
}