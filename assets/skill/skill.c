#include "skill.h"

void useIU()
/* Menggunakan Skill IU, Seluruh bangunan yang dimiliki pemain akan naik 1 level.*/
{
    // traverse semua bangunan, if milik == player, level up
    int CountBangunan = NbList(CurPlayer().list_bangunan);
    IUActive = true;
    for (int i = 1; i <= CountBangunan ; i++){
        int idB = ListElmt(CurPlayer().list_bangunan, i);
        levelup(idB);
    }
    IUActive = false;
}

void useShield()
/* Menggunakan Skill Shield, Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
   turn lawan.*/
{
    CurPlayer().ShieldActive = 2;
    printf("<Shield> activated ..."); ENDL;
    printf("+ Seluruh bangunanmu akan terlindungi selama 2 giliran musuh!"); ENDL;
}

void useExtraTurn()
/* Menggunakan Skill ExtraTurn, Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
   yang sama.*/
{
    ExtraTurnActive = true;
    printf("Player ");  print(CurTurn()); 
    printf(" memiliki turn tambahan ..."); ENDL;
    if(Add(&OtherPlayer().Skill,5)){ //Menambahkan skill CritHit di skill musuh
        printf("Player "); print(OtherTurn());
        printf(" mendapatkan <Critical Hit> ...");ENDL;
    }else{
        printf("Player ");print(OtherTurn());
        printf(" tidak dapat menambahkan <Critical Hit>!");ENDL;
    }
}

void useAttackUp()
/* Menggunakan Skill Attack Up, Pada giliran ini, setelah skill ini diaktifkan, 
   pertahanan bangunan musuh(termasuk Shield) tidak akan mempengaruhi penyerangan.*/
{
    CurPlayer().AttUpActive = true;
    printf("<Attack Up> activated ...");ENDL;
    printf("+ Pertahanan musuh akan diabaikan"); ENDL;
}

void useCriticalHit()
/* Menggunakan Skill Critical Hit, Pada giliran ini, setelah skill diaktifkan, jumlah 
   pasukan pada bangunan yang melakukan serangan tepat selanjutnya a (hanya berlaku 1 serangan) 
   hanya efektif sebanyak 2 kali lipat pasukan. Skill ini akan menonaktifkan Shield 
   maupun pertahanan bangunan, seperti Attack Up.*/
{
    CurPlayer().CritHitActive = true;
    printf("<Critical Hit> activated ...");ENDL;
    printf("+ Attack selanjutnya pada giliran ini akan meningkat"); ENDL;
    printf("+ Pertahanan musuh juga akan diabaikan"); ENDL;
}

void useInstantReinforcement()
/* Menggunakan Skill Instant Reinforcement, Seluruh bangunan mendapatkan tambahan 5 pasukan.*/
{
    int CountBangunan = NbList(CurPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        int idB = ListElmt(CurPlayer().list_bangunan, i);
        Bangunan *B = &ElmtTB(idB);
        Pasukan(*B) += 5;
    }
    printf("<Instant Reinforcement> activated ..."); ENDL;
    printf("+ Seluruh pasukan di setiap bangunan bertambah 5..."); ENDL;
}

void useBarrage()
/* Menggunakan Skill Barrage, Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
   pasukan.*/
{
    int CountBangunan = NbList(OtherPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        int idB = ListElmt(OtherPlayer().list_bangunan, i);
        Bangunan *B = &ElmtTB(idB);
        Pasukan(*B) -= 10;
        if(Pasukan(*B) < 0) Pasukan(*B) = 0;
    }
    printf("<Barrage> activated ..."); ENDL;
    printf("+ Semua bangunan musuh berkurang 10 pasukan!"); ENDL;
}


/* *** Add/Delete Skill *** */
void startSkill(Queue* Skill)
/* Kondisi Awal yaitu mempunyai Queue dengan skill Instant Upgrade */
{
    CreateEmptyQueue(Skill, 10);// Maksimal 10 skill
    Add(Skill,1); //1 sebagai IU(instant Upgrade)
}

void useSkill(Queue* Skill)
/* Menggunakan Skill sesuai Head dari queue*/
{
    int x;
    Del(Skill, &x);
    if(x == 1){         //Using IU
        useIU();
    }
    else if (x ==2){    //Using Shield
        useShield();
    }
    else if (x == 3){   //Using Extra Turn
        useExtraTurn();
    }
    else if (x == 4){   //Using Attack Up
        useAttackUp();
    }
    else if (x == 5){   //Using Critical Hit
        useCriticalHit();
    }
    else if (x == 6){   //Using Instant Reinforcement
        useInstantReinforcement();
    }
    else if (x == 7){   //Using Barrage
        useBarrage();
    }
}

/****************** PROSES SKILL ******************/
void PrintOneSkill(Queue Skill)
/* Mengeprint Skill di bagian Head Queue*/
{
    int x;
    if (IsEmptyQueue(Skill)) {
        printf("-");
    } else {
        Del(&Skill, &x);
        if(x == 1){
            printf("<Instant Upgrade>");
        }
        else if (x ==2){
            printf("<Shield>");
        }
        else if (x == 3){
            printf("<Extra Turn>");
        }
        else if (x == 4){
            printf("<Attack Up>");
        }
        else if (x == 5){
            printf("<Critical Hit>");
        }
        else if (x == 6){
            printf("<Instant Reinforcement>");
        }
        else if (x == 7){
            printf("<Barrage>");
        }
        Add(&Skill,x);
    }
    ENDL;
}

void PrintSkill(Queue Skill){
/* Mengeprint Skill available player */
    printf("Current Skill Available: "); PrintOneSkill(Skill);
}