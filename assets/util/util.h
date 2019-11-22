#ifndef UTIL_H
#define UTIL_H
#define boolean unsigned char
#define true 1
#define false 0

#define max(a, b) 	a>b?a:b
#define min(a, b) 	a<b?a:b
#define selisih(a,b) abs(a-b)
#define swapint(a,b) {int tmp; tmp = b; b = a; a = tmp;}
#define swapc(a,b) {char tmp; tmp = b; b = a; a = tmp;}

#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define printc(a)     printf("%c", a)
#define printcs(a)    printf("%c ", a)
#define printcln(a)   printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(i, n)    for(int i = 0; i < n; ++i)
#define forii(i,s,e)  for(int i = s; i < e; i++)

#define Nil NULL
#ifndef DEBUG
#define DEBUG false
#endif

#include <stdio.h>
#include <stdlib.h>
#include "pcolor.h"
#include "global.h"

#endif 