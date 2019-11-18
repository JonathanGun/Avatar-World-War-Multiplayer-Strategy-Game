/* 

    Nama : Muh.Muslim Al Mujahid
    NIM : 13518054
    Tgl : 2 Oktober 2019
    Topik : Pattern Matching

*/
#include "ADT/mesinkar.h"
#include "ADT/mesinconfig.h"
#include <stdio.h>

int main() {
    int i;
    STARTCONFIG(2);
    if ( CConfig.Bil == -1 ) printf("%c",CConfig.C);
    else printf("%d",CConfig.Bil); 

    return 0;
}