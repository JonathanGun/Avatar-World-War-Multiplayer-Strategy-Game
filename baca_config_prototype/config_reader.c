#include "config_reader.h"
#include <stdio.h>
#include <stdlib.h>

void extract_dimensi_peta(Peta *peta) {
    START_config(1);
    (*peta).dimensi.x = Token.Bil;
    ADV_config();
    (*peta).dimensi.y = Token.Bil;
}

void extract_banyak_bangunan(int *banyak_bangunan) {
    START_config(2);
    *banyak_bangunan = Token.Bil;
}

void extract_listBangunan(int banyak_bangunan, ListBangunan *list_bangunan) {
    int i;
    for ( i = 0; i < banyak_bangunan+1; i++ ) {
        START_config(3 + i);
        (*list_bangunan).bangunan[i].C = Token.Val;
        ADV_config();
        (*list_bangunan).bangunan[i].posisi.x = Token.Bil;
        ADV_config();
        (*list_bangunan).bangunan[i].posisi.y = Token.Bil;
    }
}

void extract_relasi(int banyak_bangunan, Graph *relasi) {
    int i, j;
    for ( i = 0; i < banyak_bangunan-1; i++ ) {
        START_config(3 + banyak_bangunan + i);
        for ( j = 0; j < banyak_bangunan-1; j++ ) {
            (*relasi).Mat[i][j] = Token.Bil;
            ADV_config();
        }
    }

}


