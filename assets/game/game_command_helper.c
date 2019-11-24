#include "game_command_helper.h"

Kata LOAD, START_W, EXIT;
void MakeCommand()
// Konstruktor command yaitu laod start dan exit
{
    MakeKata(&LOAD,"LOAD",4);
    MakeKata(&START_W,"START",5);
    MakeKata(&EXIT,"EXIT",4);
}

Kata ATTACK, LEVEL, SKILL, UNDO, END_TURN, SAVE, MOVE;
void MakeAksi()
// Konstruktor aksi yaitu attack,skill, level_up, undo, end_turn, save, dan move
{
    MakeKata(&ATTACK,"ATTACK",6);
    MakeKata(&LEVEL,"LEVEL_UP",8);
    MakeKata(&SKILL,"SKILL",5);
    MakeKata(&UNDO,"UNDO",4);
    MakeKata(&END_TURN,"END_TURN",8);
    MakeKata(&SAVE,"SAVE",4);
    MakeKata(&MOVE,"MOVE",4);
}

boolean valid_command(Kata input)
// Mengembalikan apakah input adalah command yang valid (load/start/exit)
{
    return(
        CompareKata(input,LOAD)     ||
        CompareKata(input,START_W)  ||
        CompareKata(input,EXIT)
    );
}

boolean valid_aksi(Kata input)
// Mengembalikan apakah input adalah aksi yang valid (attack/level_up/skill/undo/end_turn/save/move/exit)
{
    return(
        CompareKata(input,ATTACK)     ||
        CompareKata(input,LEVEL)      ||
        CompareKata(input,SKILL)      ||
        CompareKata(input,UNDO)       ||
        CompareKata(input,END_TURN)   ||
        CompareKata(input,SAVE)       ||
        CompareKata(input,MOVE)       ||
        CompareKata(input,EXIT)
    );
}

void input_between_msg(int s, int e)
// menampilkan pesan untuk menginput angka antara s dan e (inklusif)
{
    printf("Masukkan input antara "); print(s); printf(" dan "); print(e); printf("!"); ENDL;
    printf(">>> ");
}

boolean valid_range(int s, int x, int e)
// mengembalikan apakah x berada di antara s dan e (inklusif)
{
    return s <= x && x <= e;
}

int InputValidIntBetween(int s, int e)
// mengembalikan input angka yang telah divalidasi (di antara s dan e)
{
    int tmp;
    do{
        InputInt(&tmp);
        if(!valid_range(s, tmp, e))
            input_between_msg(s, e);
    } while(!valid_range(s, tmp, e));
    return tmp;
}

boolean bangunan_same_owner(Bangunan B)
// mengembalikan true jika B milik pemain saat ini
{
    return B.owner == CurTurn();
}

boolean bangunan_diff_owner(Bangunan B)
// mengembalikan true jika B bukan milik pemain saat ini
{
    return !bangunan_same_owner(B);
}

boolean bangunan_sudah_serang(Bangunan B)
// mengembalikan true jika B sudah menyerang di turn ini 
{
    return B.sudahserang;
}

boolean bangunan_sudah_pindah(Bangunan B)
// mengembalikan true jika B sudah pindah pasukan di turn ini
{
    return B.sudahpindah;
}

boolean bangunan_level_maks(Bangunan B)
// mengembalikan true jika B sudah memiliki level maksimal
{
    return B.level == MAX_LEVEL_BANGUNAN;
}

void wait_next_command()
// Menampilkan pesan bahwa game menunggu input ENTER dari user
{
    printf("<Press ENTER to continue>"); getchar();
}

void TriggerSkill()
// I.S. kondisi skill player sembarang
// F.S. kondisi skill player terupdate setelah end_turn
{
    if(CurPlayer().AttUpActive){
        CurPlayer().AttUpActive = false;
    }
    if(CurPlayer().CritHitActive){
        CurPlayer().CritHitActive = false;
    }
    if(OtherPlayer().ShieldActive){
        OtherPlayer().ShieldActive -= 1;
        if(OtherPlayer().ShieldActive == 0){
            printf("<Shield> Player "); print(OtherTurn()); printf(" habis"); ENDL;
        }
    }

    // IR - semua bangunan lv 4
    boolean CekLvl = true;
    int CountBangunan = NbList(CurPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        int idBLvl = ListElmt(CurPlayer().list_bangunan, i);
        Bangunan *BLvl = &ElmtTB(idBLvl);
        if(Level(*BLvl) != 4){
            CekLvl = false;
        }
    }
    //Jika semua bangunan level 4 maka player mendapatkan skill Instant Reinforcement
    if(CekLvl){
        //Jika kapasitas skill tidak penuh
        if(Add(&CurPlayer().Skill,6)){
            printf("Player ");print(CurTurn());printf(" mendapatkan skill Instant Reinforcement ...");ENDL;
        }else{
            printf("Player ");print(CurTurn());
            printf(" tidak dapat menambahkan skill Instant Reinforcement ...");ENDL;
        }
    }
}
