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
#define RED "\x1B[0;31m"
#define GREEN "\x1B[0;32m"
#define ORANGE "\x1B[0;33m"
#define BLUE "\x1B[0;34m"
#define PURPLE "\x1B[0;35m"
#define CYAN "\x1B[0;36m"
#define LIGHT_GRAY "\x1B[0;37m"
#define PINK "\x1B[1;31m"
#define LIGHT_GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define LIGHT_BLUE "\x1B[1;34m"
#define LIGHT_PURPLE "\x1B[1;35m"
#define LIGHT_CYAN "\x1B[1;36m"
#define DARK_GRAY "\x1B[1;37m"
#include <stdio.h>

void red();
void green();
void orange();
void blue();
void purple();
void cyan();
void light_gray();
void pink();
void light_green();
void yellow();
void light_blue();
void light_purple();
void light_cyan();
void dark_gray();
void normal();

#endif