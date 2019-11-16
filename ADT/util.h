#ifndef __UTIL_H_
#define __UTIL_H_

#define max(a, b) 	a>b?a:b
#define min(a, b) 	a<b?a:b
#define abs(a) 		a<0?-a:a 
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

#endif