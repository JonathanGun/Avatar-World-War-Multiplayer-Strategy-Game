#include "../list_bangunan.h"
#include "../../util/util.h"
#include "../bangunan.h"

int main(){
/* KAMUS LOKAL */
    int L,count,input;
    char Char;
    address G;
    ListBangunan LB;
/* ALGORITMA */
    printf("=====================DRIVER LIST BANGUNAN======================");
    do{
        printf("Daftar command : \n");
        printf("1. Memasukan bilangan kedalam list\n");
        printf("2. Melihat isi list\n");
        printf("3. Menghapus satu elemen dari list\n");
        printf("9. Menghapus satu elemen dari list\n");
        printf("%d")
        printf("Masukan bilangan ke - %d : ");scanf("%d",&L);
        G = AlokasiList(L);
        First(LB) = P;
        printf("Masukan bilangan terakhir list : ");scanf("%d",&L);
        InsertList(&LB,L);
        printf("Ini list yang dihasilkan : "); PrintList(LB);
        if IsEmptyList(LB) printf("List ini kosong");
        else printf("List tidak kosong");
        printf("Masukan bilangan yang ingin didelete : "); scanf("%d",&L);
        if(SearchList(LB,L) != Nil){
            DelList(&LB,L);
            printf("%d telah dihapus dari list, isi list sekarang: ",L);
        }
        println(Info(A));
    } while(input != 9);
    return 0;
}