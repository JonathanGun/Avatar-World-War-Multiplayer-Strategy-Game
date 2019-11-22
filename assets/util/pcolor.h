#ifndef PCOLOR_H
#define PCOLOR_H
/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

/**
print_xxx(c) will print c with xxx color.
xxx() will set next char be printed with xxx color.
**/

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#include <stdio.h>

void print_red(char c);
void red();
void print_green(char c);
void green();
void print_yellow(char c);
void yellow();
void print_blue(char c);
void blue();
void print_magenta(char c);
void magenta();
void print_cyan(char c);
void cyan();
void normal();

#endif