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
    count = 0;
    CreateEmptyList(&LB);
    do{
        printf("\nDaftar command : \n");
        printf("1. Memasukan bilangan kedalam list\n");
        printf("2. Melihat isi list\n");
        printf("3. Menghapus satu elemen dari list\n");
        printf("4. Mengetes kekosongan list\n");
        printf("9. Keluar dari driver\n >> ");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            count++;
            printf("Masukan bilangan ke-%d : ",count);scanf("%d",&L);
            InsertList(&LB,L);
            break;
        case 2:
            PrintList(LB);ENDL;
            break;
        case 3:
            printf("Masukan bilangan yang ingin dihapus : ",count);scanf("%d",&L);
            if(SearchList(LB,L) != Nil){
                DelList(&LB,L);
                count--;
                printf("Bilangan %d berhasil dihapus\n",L);
            }
            else{
                printf("Bilangan tidak terdapat dalam list\n");
            }
            break;
        case 4:
            IsEmptyList(LB)? printf("Ya list kosong\n") : printf("List tidak kosong\n");
            break;
        case 9:
            printf("Terimakasih telah menggunakan driver ini! \n");
            break;
        default:
            break;
        }
    } while(input != 9);
    return 0;
}