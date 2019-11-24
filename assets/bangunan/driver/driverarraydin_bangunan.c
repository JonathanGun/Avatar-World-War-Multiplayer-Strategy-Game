#include "../arraydin_bangunan.h"

int main(){
    TabBangunan TB;
    ListBangunan LB;
    CreateEmptyList(&LB);
    CreateEmptyTabBangunan(&TB,5);
    Bangunan A,B;
    CreateBangunanEmpty(&A);
    CreateBangunanEmpty(&B);
    Id(A) = 5;
    Type(A) = 'C';
    Id(B) = 10;
    Type(B) = 'V';
    TB.TB[0] = A;
    TB.TB[1] = B;
    printf("tipe bangunan pertama: ");
    printTypeBangunan(TB.TB[0]);
    printf("\ntipe bangunan kedua: ");
    printTypeBangunan(TB.TB[1]);
    return 0;
}