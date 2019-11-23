#include "bangunan.h"

Point MakePoint(int X, int Y)
/* Membentuk sebuah Point dari komponen-komponennya */
{
    Point P;
    Row(P) = X;
    Col(P) = Y;
    return P;
}

void CreateBangunanEmpty(Bangunan *B)
/* */
{
    (*B).id = -1;
    (*B).jumlah_pasukan = 0;
    (*B).level = 0;
    (*B).nilai_tambah_pasukan = 0;
    (*B).maksimum_tambah_pasukan = 0;
    (*B).owner = -1;
    (*B).pertahanan = false;
    (*B).sudahserang = false;
    (*B).sudahpindah = false;
    (*B).posisi.r = 0;
    (*B).posisi.c = 0;
    (*B).type = ' ';
}

void CopyBangunan(Bangunan Bin, Bangunan *B)
/* */
{
    (*B).id = Bin.id;
    (*B).jumlah_pasukan = Bin.jumlah_pasukan;
    (*B).level = Bin.level;
    (*B).nilai_tambah_pasukan = Bin.nilai_tambah_pasukan;
    (*B).maksimum_tambah_pasukan = Bin.maksimum_tambah_pasukan;
    (*B).owner = Bin.owner;
    (*B).pertahanan = Bin.pertahanan;
    (*B).sudahserang = Bin.sudahserang;
    (*B).sudahpindah = Bin.sudahpindah;
    (*B).posisi.r = Bin.posisi.r;
    (*B).posisi.c = Bin.posisi.c;
    (*B).type = Bin.type;
}

boolean IsBangunanEmpty(Bangunan B)
/* Mengecek apakah bangunan merupakan bangunan kosong */
{
    return B.id == -1;
}

boolean IsLvlUpValid(Bangunan B)
/* Mengecek apakah bangunan valid untuk di level up, syarat level up adalah jumlah pasukan >= M/2 */
{
    if(Type(B) == 'C' ){
        return(Pasukan(B) >= (MatElmt(AttCastle,Level(B),2)/2));
    }
    else if(Type(B) == 'T'){
        return(Pasukan(B) >= (MatElmt(AttTower,Level(B),2)/2));
    }
    else if(Type(B) == 'F'){
        return(Pasukan(B) >= (MatElmt(AttFort,Level(B),2)/2));
    }
    else if(Type(B) == 'V'){
        return(Pasukan(B) >= (MatElmt(AttVillage,Level(B),2)/2));
    }
}

boolean not_IsLevelUpValid(Bangunan B){
    return !IsLvlUpValid(B);
}

void levelup(int idB)
/* Menaikkan level dari Bangunan Pemain */
{
    Bangunan *B = &ElmtTB(idB);
    // level maks
    if(Level(*B) == 4){
        printf("Level "); printTypeBangunan(*B);
        printf(" (%d,%d) ", (*B).posisi.r, (*B).posisi.c);  
        printf("sudah Maksimum, tidak dapat melakukan level up lagi !\n");
        return;
    }

    // jumlah pasukan kurang
    if(!IUActive && !IsLvlUpValid(*B)){
        printf("Jumlah pasukan "); printTypeBangunan(*B);
        printf(" kurang untuk Level up !"); ENDL;
        return;
    }

    // if not from IU
    if(!IUActive){
        Pasukan(*B) -= (MaxPasukan(*B)/2);
    }

    // do levelup
    Level(*B) += 1;
    // "A" : 1, "M" : 2, "P" : 3
    if(Type(*B) == 'C'){
        RateTambah(*B) = MatElmt(AttCastle, Level(*B), 1);
        MaxPasukan(*B) = MatElmt(AttCastle, Level(*B), 2);
        Pertahanan(*B) = MatElmt(AttCastle, Level(*B), 3);
        if(Level(*B) == 1) Pasukan(*B) = MatElmt(AttCastle, Level(*B), 4);
    } else if(Type(*B) == 'T'){
        RateTambah(*B) = MatElmt(AttTower, Level(*B), 1);
        MaxPasukan(*B) = MatElmt(AttTower, Level(*B), 2);
        Pertahanan(*B) = MatElmt(AttTower, Level(*B), 3);
        if(Level(*B) == 1) Pasukan(*B) = MatElmt(AttTower, Level(*B), 4);
    } else if(Type(*B) == 'F'){
        RateTambah(*B) = MatElmt(AttFort, Level(*B), 1);
        MaxPasukan(*B) = MatElmt(AttFort, Level(*B), 2);
        Pertahanan(*B) = MatElmt(AttFort, Level(*B), 3);
        if(Level(*B) == 1) Pasukan(*B) = MatElmt(AttFort, Level(*B), 4);
    } else if(Type(*B) == 'V'){
        RateTambah(*B) = MatElmt(AttVillage, Level(*B), 1);
        MaxPasukan(*B) = MatElmt(AttVillage, Level(*B), 2);
        Pertahanan(*B) = MatElmt(AttVillage, Level(*B), 3);
        if(Level(*B) == 1) Pasukan(*B) = MatElmt(AttVillage, Level(*B), 4);
    }

    // feedback
    if((*B).level != 1){
        printf("Level ");printTypeBangunan(*B);
        printf(" (%d,%d) ", (*B).posisi.r, (*B).posisi.c); 
        printf("meningkat menjadi %d !\n", Level(*B));
    }
}

void attack(int idBAtt, int idBDef, int jumlah_penyerang)
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh idBAtt kepada idBDef */
{
    Bangunan *BAtt = &ElmtTB(idBAtt);
    Bangunan *BDef = &ElmtTB(idBDef);

    (*BAtt).sudahserang = true;
    Pasukan(*BAtt) -= jumlah_penyerang;
    printf("Bangunan pertahanan memiliki %d pasukan\n", Pasukan(*BDef));
    printf("Melakukan penyerangan dengan jumlah pasukan %d pasukan\n\n", jumlah_penyerang);

    if(CurPlayer().CritHitActive){
        CurPlayer().CritHitActive = false;
        printf("Kamu punya skill critical hit dan/atau critical hit aktif! Damage pasukanmu menjadi 2x lipat!\n");
        if(2*jumlah_penyerang >= Pasukan(*BDef)){
            TakeOwnership(BDef);
            BangunanOwner(*BDef) = BangunanOwner(*BAtt);
            Pasukan(*BDef) = jumlah_penyerang - ((Pasukan(*BDef)-1)/2) - 1;
            printf("Bangunan berhasil direbut!\n");
            printf("Pasukan yang tersisa sejumlah %d orang siap mati menjaga bangunan ini!\n", Pasukan(*BDef));
        } else {
            Pasukan(*BDef) -= 2*jumlah_penyerang;
            printf("Namun bangunan tetap gagal direbut. "); ENDL;
            printf("Pasukan yang masih tersisa di bangunan lawan berjumlah %d orang", Pasukan(*BDef)); ENDL;
        }
    } else {
        if((!CurPlayer().AttUpActive) && (OtherPlayer().ShieldActive || Pertahanan(*BDef))){
            /* Bangunan memiliki pertahanan */
            printf("Bangunan musuh memiliki pertahanan! Damage pasukanmu hanya efektif 75%% saja!"); ENDL;
            if((3*jumlah_penyerang/4) >= Pasukan(*BDef)){
                TakeOwnership(BDef);
                Pasukan(*BDef) = jumlah_penyerang - ((4*Pasukan(*BDef)-1)/3) - 1;

                printf("Bangunan berhasil direbut!\n");
                printf("Pasukan yang tersisa sejumlah %d orang siap mati menjaga bangunan ini!\n", Pasukan(*BDef));
            } else {
                Pasukan(*BDef) -= 3*jumlah_penyerang/4;
                printf("Bangunan gagal direbut.\n");
                printf("Pasukan yang masih tersisa di bangunan lawan berjumlah %d orang\n", Pasukan(*BDef));
            }
        } else {
            /* Bangunan tidak memiliki pertahanan */
            Pasukan(*BDef) -= jumlah_penyerang;
            
            if(Pasukan(*BDef) <= 0){
                TakeOwnership(BDef);
                Pasukan(*BDef) = -Pasukan(*BDef);
                printf("Bangunan berhasil diambil, ");
                if(Pasukan(*BDef) > 0){
                    printf("pasukan yang tersisa sebanyak %d pasukan di dalam bangunan.\n", Pasukan(*BDef));
                } else {
                    printf("tidak ada pasukan yang tersisa untuk menjaga bangunan.\n");
                }
            } else {
                printf("Bangunan gagal direbut.\n");
                printf("Pasukan yang masih tersisa di bangunan lawan berjumlah %d orang\n", Pasukan(*BDef));
            }
        }
    }
}

void move(int idBAwal, int idBAkhir, int jumlah_pasukan_pindah)
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */
{
    Bangunan *BAwal = &ElmtTB(idBAwal);
    Bangunan *BAkhir = &ElmtTB(idBAkhir);
    
    if((*BAwal).sudahpindah){
        printf("Bangunan sudah melakukan pemindahan pasukan pada turn ini\n");
    }
    else{
        (*BAwal).sudahpindah = true;
        /*Jumlah pasukan di bangunan awal lebih dari jumlah pasukan yang akan dipindahkan */
        Pasukan(*BAwal) -= jumlah_pasukan_pindah;
        Pasukan(*BAkhir) += jumlah_pasukan_pindah;
        printf("Sejumlah %d pasukan berhasil dipindahkan\n", jumlah_pasukan_pindah);
        if(Pasukan(*BAwal) == 0){
            printf("Tidak ada pasukan tersisa di bangunan awal\n");
        } else{
            printf("Pasukan di bangunan awal menjadi %d pasukan\n", Pasukan(*BAwal));
        }
        printf("Pasukan di bangunan yang dituju menjadi %d pasukan\n", Pasukan(*BAkhir));
    }
}

void add_pasukan()
/* Menghitung perubahan jumlah pasukan saat awal turn */
{
    int CountBangunan = CountList(CurPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        int idB = ListElmt(CurPlayer().list_bangunan, i);
        Bangunan *B = &ElmtTB(idB);
        if(Pasukan(*B) < MaxPasukan(*B)){
            Pasukan(*B) += RateTambah(*B);
        }
    }
}

void TulisBangunan(Bangunan B)
/* */
{
    printf("<%d> %c at (%d,%d)\n", B.id, B.type, B.posisi.r, B.posisi.c);
    printf("Milik player "); println(B.owner);
    printf("Level: "); println(B.level);
    printf("Jumlah Pasukan: "); println(B.jumlah_pasukan);
    printf("Shield active? ");
    if(B.pertahanan) printf("yes");
    else printf("no");
    ENDL;
    printf("Sudah serang? ");
    if(B.sudahserang) printf("yes");
    else printf("no");
    ENDL;
}

void printTypeBangunan(Bangunan B)
/* Mengeprint Type sebuah bangunan */
{
    if (Type(B) == 'C') printf("Castle");
    else if (Type(B) == 'T') printf("Tower");
    else if (Type(B) == 'F') printf("Fort");
    else if (Type(B) == 'V') printf("Village");
}

void TakeOwnership(Bangunan* B){
    (*B).owner %= 2;
    (*B).owner++;
    DelList(&OtherPlayer().list_bangunan, (*B).id);
    InsertList(&CurPlayer().list_bangunan, (*B).id);
}