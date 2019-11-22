#include "gui.h"

void PrintAll(){
    int cekblue = 0;
    int cekgreen = 0;
    int cekyellow = 0;
    int cekorange = 0;
    while(!EOP){
        if(CC == '^' && cekyellow == 0){
            cekyellow = 1;
            yellow();
        } else if(CC == '^' && cekyellow == 1){
            cekyellow = 0;
            normal();
        } else if(CC == '*' && cekblue == 0){
            cekblue = 1;
            blue();
        } else if(CC == '*' && cekblue == 1){
            cekblue = 0;
            normal();
        } else if(CC == '{' && cekgreen == 0){
            cekgreen = 1;
            green();
        } else if(CC == '{' && cekgreen == 1){
            cekgreen = 0;
            normal();
        } else if(CC == '&' && cekorange == 0){
            cekorange = 1;
            orange();
        } else if(CC == '&' && cekorange == 1){
            normal();
        } else {
            printf("%c",CC);
        }
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