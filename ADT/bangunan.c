#include "bangunan.h"

boolean AttackBerhasil;

void levelup(Bangunan *B){
/* Menaikkan level dari Bangunan Pemain */
    if(Level(*B) < 4){
        Level(*B) += 1;
        // "M" : 1, "A" : 2, "P" : 3
        if(Type(*B) == 'C'){
            MaxPasukan(*B) = MatElmt(AttCastle, 1, Level(*B)+1);
            RateTambah(*B) = MatElmt(AttCastle, 2, Level(*B)+1);
            Pertahanan(*B) = MatElmt(AttCastle, 3, Level(*B)+1);
        }
        else if(Type(*B) == 'T'){
            MaxPasukan(*B) = MatElmt(AttTower, 1, Level(*B)+1);
            RateTambah(*B) = MatElmt(AttTower, 2, Level(*B)+1);
            Pertahanan(*B) = MatElmt(AttTower, 3, Level(*B)+1);
        }
        else if(Type(*B) == 'F'){
            MaxPasukan(*B) = MatElmt(AttFort, 1, Level(*B)+1);
            RateTambah(*B) = MatElmt(AttFort, 2, Level(*B)+1);
            Pertahanan(*B) = MatElmt(AttFort, 3, Level(*B)+1);
        }
        else if(Type(*B) == 'V'){
            MaxPasukan(*B) = MatElmt(AttVillage, 1, Level(*B)+1);
            RateTambah(*B) = MatElmt(AttVillage, 2, Level(*B)+1);
            Pertahanan(*B) = MatElmt(AttVillage, 3, Level(*B)+1);
        }
    }
    else{
        printf("Level Bangunan sudah Maksimum, tidak dapat melakukan level up lagi\n");
    }
}

void attack(Bangunan *BAtt, Bangunan *BDef, int jumlah_penyerang){
    AttackBerhasil = false;
    if(Pasukan(*BAtt) < jumlah_penyerang){
        printf("Attack tidak dapat dilakukan karena pasukan tidak mencukupi.\n");
    }
    else{
        /* Perubahan Jumlah Pasukan saat melancarkan Penyerangan */
        Pasukan(*BAtt) -= jumlah_penyerang;
        if(!Pertahanan(*BDef)){
            Pasukan(*BDef) -= jumlah_penyerang;
        }
        else{
            Pasukan(*BDef) -= (3/4 * jumlah_penyerang);
        }
        /* STATE SETELAH PENYERANGAN */
        // Berhasil Diambil
        if(Pasukan(*BDef) < 0){
            printf("Bangunan berhasil diambil, pasukan yang tersisa sebanyak %d pasukan di dalam Bangunan.\n", -Pasukan(*BDef));
            Pasukan(*BDef) = -1 * Pasukan(*BDef);
            BangunanOwner(*BDef) = BangunanOwner(*BAtt);
        }
        else if(Pasukan(*BDef) == 0){
            printf("Bangunan berhasil diambil, tidak ada pasukan yang tersisa untuk menjaga bangunan.\n");
            BangunanOwner(*BDef) = BangunanOwner(*BAtt);
        }
        // Tidak Berhasil Diambil
        else{/* Pasukan(*BDef) > 0 setelah penyerangan, masih tersisa pasukan pertahanan */
            printf("Bangunan tidak berhasil diambil.\n");
        }
    }

}
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */

void move(Bangunan *BAwal, Bangunan *BAkhir, int jumlah_pasukan_pindah){
    if(Pasukan(*BAkhir) == MaxPasukan(*BAkhir)){
         printf("Bangunan yang dituju penuh, tidak dapat MatElmtindahkan pasukan\n");
    }
    else{ /*Bangunan Akhir tidak penuh, perpindahan dapat dilakukan */

        if(Pasukan(*BAwal) < jumlah_pasukan_pindah){ /* Jumlah pasukan di bangunan awal kurang dari jumlah pasukan yang akan dipindahkan */

            if((Pasukan(*BAwal) + Pasukan(*BAkhir)) > MaxPasukan(*BAkhir)){ /*Perpindahan melebihi kapasitas bangunan akhir */
                printf("Pasukan di bangunan awal kurang, MatElmtindahkan %d pasukan karena bangunan akhir sudah penuh\n", MaxPasukan(*BAkhir) - Pasukan(*BAkhir));
                Pasukan(*BAwal) -= MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
                Pasukan(*BAkhir) += MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
            }

            else{ /* Perpindahan masih dapat ditampung kapasitas bangunan akhir */
                printf("Pasukan di bangunan awal kurang, MatElmtindahkan %d pasukan\n", Pasukan(*BAwal));
                Pasukan(*BAwal) -= Pasukan(*BAwal);
                Pasukan(*BAkhir) += Pasukan(*BAwal);
            }
        }

        else{ /*Jumlah pasukan di bangunan awal lebih dari jumlah pasukan yang akan dipindahkan */

            if((jumlah_pasukan_pindah + Pasukan(*BAkhir)) > MaxPasukan(*BAkhir)){ /*Perpindahan melebihi kapasitas bangunan akhir */
                printf("MatElmtindahkan %d pasukan karena bangunan akhir sudah penuh\n", MaxPasukan(*BAkhir) - Pasukan(*BAkhir));
                Pasukan(*BAwal) -= MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
                Pasukan(*BAkhir) += MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
            }
            else{/* Perpindahan terjadi secara normal tanpa ada bangunan yang habis pasukannya atau penuh */
                Pasukan(*BAwal) -= jumlah_pasukan_pindah;
                Pasukan(*BAkhir) += jumlah_pasukan_pindah;
            }
        }
    }
}
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */

void add_pasukan(Bangunan *B){
    if((RateTambah(*B) + Pasukan(*B)) > MaxPasukan(*B)){
        Pasukan(*B) += (MaxPasukan(*B) - Pasukan(*B));
    }
    else{
        Pasukan(*B) += RateTambah(*B);
    }
}
/* Menghitung perubahan jumlah pasukan saat awal turn */
