#include "../bangunan/list_bangunan.h"
#include "../util/util.h"
#include "../bangunan/bangunan.h"

int main(){
    address P = AlokasiList(11);
    address G = AlokasiList(5);
    Next(P) = G;
    ListBangunan L;
    First(L) = P;
    InsertList(&L,12);
    PrintList(L);
    if(IsEmptyList(L)){
        printf("hehe");
    } else printf("xd\n");
    address A = SearchList(L,5);
    println(Info(A));
    return 0;
}