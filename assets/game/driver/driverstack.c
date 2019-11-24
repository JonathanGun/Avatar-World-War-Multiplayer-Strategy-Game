#include "../game_stackt.h"

int main(){
    int i,X;
    CreateEmptyStackt (&G.GameConditions);
    if(IsEmptyStackt(G.GameConditions))
    {
        printf("Kosong\n");
    }else{
        printf("tidak kosong\n");
    }
    for(i = 1; i <= 10 ; i++){
        printf("Push ke-%d\n",i);
        PushStackt();
    }
    if(IsEmptyStackt(G.GameConditions))
    {
        printf("Kosong\n");
    }else{
        printf("tidak kosong\n");
    }
    printf("Pop stack 3 kali\n");
    for(i = 1; i <= 3 ; i++){
        printf("Pop ke-%d\n",i);
        PopStackt();
    }
    if(IsEmptyStackt(G.GameConditions))
    {
        printf("Kosong\n");
    }else{
        printf("tidak kosong\n");
    }
    printf("Reset stack jadi 0\n");
    ResetStackt();
    if(IsEmptyStackt(G.GameConditions))
    {
        printf("Kosong\n");
    }else{
        printf("tidak kosong\n");
    }
    return 0;
}