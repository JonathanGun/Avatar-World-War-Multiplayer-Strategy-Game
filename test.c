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