#include "gui.h"

void PrintAll(){
    int cekblue = 0;
    int cekgreen = 0;
    int cekyellow = 0;
    while(!EOP){
        if(CC == '^' && cekyellow == 0){
            cekyellow = 1;
            ADV();
            yellow();
        }
        if(CC == '^' && cekyellow == 1){
            cekyellow = 0;
            ADV();
            normal();
        }
        if(CC == '*' && cekblue == 0){
            cekblue = 1;
            ADV();
            blue();
        }
        if(CC == '*' && cekblue == 1){
            cekblue = 0;
            ADV();
            normal();
        }
        if(CC == '{' && cekgreen == 0){
            cekgreen = 1;
            ADV();
            green();
        }
        if(CC == '{' && cekgreen == 1){
            cekgreen = 0;
            ADV();
            normal();
        }
        printf("%c",CC);
        ADV();
    }
    normal();
    CC = ' ';
}

void gui_logo(){
    START("resources/logo.txt");
    PrintAll();
    printf("\n\n\n");
}

void show_valid_command(){
    START("resources/show_command.txt");
    PrintAll();
    printf("\n\n");
}