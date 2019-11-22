#include "config_reader.h"

void extract_config(const char* fileconfig) {
    START_file(fileconfig, 0);
    extract_peta();
    int n = extract_banyak_bangunan();
    extract_listBangunan(n);
    extract_relasi(n);
    CC = ' ';
}

void extract_peta(){
    int r = Token.Bil;
    ADV_file();
    int c = Token.Bil;
    MakePeta(r, c);
}

int extract_banyak_bangunan() {
    ADV_file();
    return Token.Bil;
}

void extract_listBangunan(int banyak_bangunan) {
    CreateEmptyTabBangunan(&G.ListBangunan, banyak_bangunan);
    Bangunan B; 
    for(int i = 1; i < banyak_bangunan+1; i++) {
        CreateBangunanEmpty(&B);
        B.id = i;
        if(i <= 2) B.owner = i;
        else B.owner = 0;

        ADV_file();
        B.type = Token.Val;
        ADV_file();
        B.posisi.r = Token.Bil;
        ADV_file();
        B.posisi.c = Token.Bil;

        B.level = 0;
        levelup(&B);
        AddBangunan(B, &G.ListBangunan);
    }
}

void extract_relasi(int banyak_bangunan) {
    G.Relasi = CreateGraph(banyak_bangunan);
    for(int i = 1; i <= banyak_bangunan; i++ ) {
        for(int j = 1; j <= banyak_bangunan; j++ ) {
            ADV_file();
            if(Token.Bil) SetBangunanTerhubung(&G.Relasi, i, j);
        }
    }
}
