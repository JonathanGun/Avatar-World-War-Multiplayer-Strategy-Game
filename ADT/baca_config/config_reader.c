#include "config_reader.h"
#include <stdio.h>
#include <stdlib.h>

void extract_config(Config conf) {
    extract_dimensi_peta(&conf.conf_peta);
    extract_banyak_bangunan(&conf.conf_banyak_bangunan);
    extract_listBangunan(conf.conf_banyak_bangunan ,conf.conf_list_bangunan);
    extract_relasi(conf.conf_banyak_bangunan, conf.conf_relasi);
}

void extract_dimensi_peta(Peta *peta) {

    START_config(1);
    (*peta).NPetaBrsEff = Token.Bil;
    ADV_config();
    (*peta).NPetaKolEff = Token.Bil;
}

void extract_banyak_bangunan(int *banyak_bangunan) {
    START_config(2);
    *banyak_bangunan = Token.Bil;
}

void extract_listBangunan(int banyak_bangunan, ListBangunan list_bangunan) {

    int i;
    address P = list_bangunan.First;
    for ( i = 1; i < banyak_bangunan+1; i++ ) {
        START_config(2 + i);

        Bangunan B; 
        B.type = Token.Val;
        ADV_config();
        B.posisi.x = Token.Bil;
        ADV_config();
        B.posisi.y = Token.Bil;

        B.level = 1;
        if ( B.type == 'C' ) {
            B.nilai_tambah_pasukan = 10;
            B.maksimum_tambah_pasukan = 40;
            B.pertahanan = false;
            B.jumlah_pasukan = 40;
        } else if ( B.type == 'T' ) {
            B.nilai_tambah_pasukan = 5;
            B.maksimum_tambah_pasukan = 20;
            B.pertahanan = true;
            B.jumlah_pasukan = 30;
        } else if ( B.type == 'F') {
            B.nilai_tambah_pasukan = 10;
            B.maksimum_tambah_pasukan = 20;
            B.pertahanan = false;
            B.jumlah_pasukan = 80;
        } else if ( B.type == 'V' ) {
            B.nilai_tambah_pasukan = 5;
            B.maksimum_tambah_pasukan = 20;
            B.pertahanan = false;
            B.jumlah_pasukan = 20;
        }

        if ( i == 1) P = Alokasi(B);
        else {
            P->next = Alokasi(B);
            P = P->next;
        }
    }
}

void extract_relasi(int banyak_bangunan, Graph relasi) {

    int i, j;
    relasi = CreateGraph(banyak_bangunan, banyak_bangunan);
    for ( i = 1; i <= banyak_bangunan; i++ ) {
        START_config(2 + banyak_bangunan + i);
        for ( j = 1; j <= banyak_bangunan; j++ ) {
            if ( Token.Bil == 1) SetBangunanTerhubung(relasi, i, j);
            ADV_config();
        }
    }
}




