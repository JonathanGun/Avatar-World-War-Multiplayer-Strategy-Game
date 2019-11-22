/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include "pcolor.h"

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}
void red(){
    printf("%s", RED);
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
void magenta(){
    printf("%s", MAGENTA);
}

void print_cyan(char c) {
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
}
void cyan(){
    printf("%s", CYAN);
}

void normal(){
    printf("%s", NORMAL);
}