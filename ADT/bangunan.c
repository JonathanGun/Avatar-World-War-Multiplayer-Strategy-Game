#include "bangunan.h"
#include "matriks.h"

Matriks AttCastle,AttTower,AttFort,AttVillage;
MakeMatriks(&AttCastle);
MakeMatriks(&AttCastle);
MakeMatriks(&AttFort);
MakeMatriks(&AttVillage);

void levelup(Bangunan *B){
/* Menaikkan level dari Bangunan Pemain */
    if(Level(*B) < 4){
        Level(*B) += 1;

        if(Type(*B) == "C"){
            MaxPasukan(*B) = AttCastle["M"][Level(*B)+1]
            RateTambah(*B) = AttCastle["A"][Level(*B)+1]
            Pertahanan(*B) = AttCastle["P"][Level(*B)+1]
        }
        else if(Type(*B) == "T"){
            MaxPasukan(*B) = AttTower["M"][Level(*B)+1]
            RateTambah(*B) = AttTower["A"][Level(*B)+1]
            Pertahanan(*B) = AttTower["P"][Level(*B)+1]
        }
        else if(Type(*B) == "F"){
            MaxPasukan(*B) = AttFort["M"][Level(*B)+1]
            RateTambah(*B) = AttFort["A"][Level(*B)+1]
            Pertahanan(*B) = AttFort["P"][Level(*B)+1]
        }
        else if(Type(*B) == "V"){
            MaxPasukan(*B) = AttVillage["M"][Level(*B)+1]
            RateTambah(*B) = AttVillage["A"][Level(*B)+1]
            Pertahanan(*B) = AttVillage["P"][Level(*B)+1]
        }
    }
    else{
        printf("Level Bangunan sudah Maksimum, tidak dapat melakukan level up lagi\n")
    }
}

void attack(Bangunan *BAtt, Bangunan *BDef, int jumlah_penyerang){
    extern boolean AttackBerhasil = false;
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
        }
        else if(Pasukan(*BDef) == 0){
            prinf("Bangunan berhasil diambil, tidak ada pasukan yang tersisa untuk menjaga bangunan.\n");
        }
        // Tidak Berhasil Diambil
        else{/* Pasukan(*BDef) > 0 setelah penyerangan, masih tersisa pasukan pertahanan */
            printf("Bangunan tidak berhasil diambil.\n")
        }
    }

}
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */

void move(Bangunan *BAwal, Bangunan *BAkhir, int jumlah_pasukan_pindah){
    if(Pasukan(*BAkhir) == MaxPasukan(*BAkhir)){
         printf("Bangunan yang dituju penuh, tidak dapat memindahkan pasukan\n");
    }
    else{ /*Bangunan Akhir tidak penuh, perpindahan dapat dilakukan */

        if(Pasukan(*BAwal) < jumlah_pasukan_pindah){ /* Jumlah pasukan di bangunan awal kurang dari jumlah pasukan yang akan dipindahkan */

            if((Pasukan(*BAwal) + Pasukan(*BAkhir)) > MaxPasukan(*B)){ /*Perpindahan melebihi kapasitas bangunan akhir */
                printf("Pasukan di bangunan awal kurang, Memindahkan %d pasukan karena bangunan akhir sudah penuh\n", MaxPasukan(*BAkhir) - Pasukan(*BAkhir));
                Pasukan(*BAwal) -= MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
                Pasukan(*BAkhir) += MaxPasukan(*BAkhir) - Pasukan(*BAkhir);
            }

            else{ /* Perpindahan masih dapat ditampung kapasitas bangunan akhir */
                printf("Pasukan di bangunan awal kurang, Memindahkan %d pasukan\n", Pasukan(*BAwal))
                Pasukan(*BAwal) -= Pasukan(*BAwal);
                Pasukan(*BAkhir) += Pasukan(*BAwal);
            }
        }

        else{ /*Jumlah pasukan di bangunan awal lebih dari jumlah pasukan yang akan dipindahkan */

            if((jumlah_pasukan_pindah + Pasukan(*BAkhir)) > MaxPasukan(*B)){ /*Perpindahan melebihi kapasitas bangunan akhir */
                printf("Memindahkan %d pasukan karena bangunan akhir sudah penuh\n", MaxPasukan(*BAkhir) - Pasukan(*BAkhir));
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

Bangunan GetBangunanByID(int id){
    
}
/* Mendapat Bangunan Dari IDnya */