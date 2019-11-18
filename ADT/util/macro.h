#ifndef __MACRO_H_
#define __MACRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) 	a>b?a:b
#define min(a, b) 	a<b?a:b
#define selisih(a,b) abs(a-b)
#define swapint(a,b) {int tmp; tmp = b; b = a; a = tmp;}
#define swapc(a,b) {char tmp; tmp = b; b = a; a = tmp;}

#define charput(a)    scanf(" %c", &a)
#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define printc(a)     printf("%c", a)
#define printcs(a)    printf("%c ", a)
#define printcln(a)   printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(i, n)    for(int i = 1; i <= n; ++i)
#define forii(i,s,e)  for(int i = s; i < e;  i++)

#endif