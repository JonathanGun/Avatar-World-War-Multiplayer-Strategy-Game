/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"
#include "mesinkata.h"
#include <stdlib.h>

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}
void green(){
    printf("%s",GREEN);
}

void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
}
void yellow(){
    printf("%s",YELLOW);
}

void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}
void blue(){
    printf("%s",BLUE);
}
void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_cyan(char c) {
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
}
void cyan(){
    printf("%s",CYAN);
}

void normal(){
    printf("%s",NORMAL);
}

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

void init_gambar(){
    START("Gambar2/GUI.txt");
    PrintAll();
    printf("\n\n\n");
}
