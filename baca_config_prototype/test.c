#include "config_reader.h"
#include <stdio.h>

int main() {

    printf("test dimensi peta:\n");
    Peta peta;
    extract_dimensi_peta(&peta);
    printf("%d %d\n", peta.dimensi.x, peta.dimensi.y);

    printf("test banyak bangunan:\n");
    int banyak_bangunan;
    extract_banyak_bangunan(&banyak_bangunan);
    printf("banyak bangunan: %d\n", banyak_bangunan);

    printf("test list bangunan:\n");
    ListBangunan list_bangunan;
    extract_listBangunan(banyak_bangunan, &list_bangunan);
    int i;
    for ( i = 0; i < banyak_bangunan; i++ ) {
        printf("%c %d %d\n",list_bangunan.bangunan[i].C,list_bangunan.bangunan[i].posisi.x,list_bangunan.bangunan[i].posisi.y);
    }

    printf("test relasi:\n");
    Graph relasi;
    extract_relasi(banyak_bangunan, &relasi);
    int j;
    for ( i = 0; i < banyak_bangunan; i++ ) {
        for ( j = 0; j < banyak_bangunan; j++ ) {
            printf("%d ", relasi.Mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}