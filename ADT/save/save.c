#include "save.h"

void SaveGame(GameCondition Gc, TabBangunan list_bangunan, int Turn) {
    Player P1 = Gc.Players[0];
    Player P2 = Gc.Players[1];

    // temporary variable
    Queue Skill;
    int X;
    Bangunan B;
    address P;

    int i;
    FILE *fp;
    /* open the file for writing*/
    fp = fopen ("ADT/save/save.txt","a");

    // pembatas dengan save lain
    fprintf (fp, "-\n");

    // simpan turn
    fprintf (fp, "%d\n", Turn);

    //---------------------- simpan data player 1 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, 10);
    CopyQueue(P1.Skill, &Skill);
    if ( IsEmptyQueue(Skill) ) {
        fprintf(fp, "%d ", 0);
    }
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");

    // simpan banyak bangunan
    fprintf(fp, "%d\n", CountList(P1.list_bangunan));

    // simpan bangunan
    // format : 
    // id level sudahserang pertahanan pasukan  
    // id level sudahserang pertahanan pasukan
    // ..........   
    P = First(P1.list_bangunan);
    while ( P != NULL ) {
        CreateBangunanEmpty(&B);
        GetBangunanByID(list_bangunan, Info(P), &B);
        fprintf(fp, "%d %d %d %d %d\n", Id(B), Level(B), SudahSerang(B), Pertahanan(B), Pasukan(B));
        P = Next(P);
    }

    //---------------------- simpan data player 2 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, 10);
    CopyQueue(P2.Skill, &Skill);
    if ( IsEmptyQueue(Skill) ) {
        fprintf(fp, "%d ", 0);
    }
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");

    // simpan banyak bangunan
    fprintf(fp, "%d\n", CountList(P2.list_bangunan));

    // simpan bangunan
    // format : 
    // id level sudahserang pertahanan pasukan  
    // id level sudahserang pertahanan pasukan
    // ..........   
    P = First(P2.list_bangunan);
    while ( P != NULL ) {
        CreateBangunanEmpty(&B);
        GetBangunanByID(list_bangunan, Info(P), &B);
        fprintf(fp, "%d %d %d %d %d\n", Id(B), Level(B), SudahSerang(B), Pertahanan(B), Pasukan(B));
        P = Next(P);
    }

    fclose(fp);
}

void NthSave(const char* savefile, int N) {
    START_file(savefile, 1);
    while ( N > 1 ) {
        if ( CC == '-' ) {
            N--;
        }
        ADV();
    }
}

void LoadGame(const char* savefile, GameCondition *G, int *Turn, int N) {
    
    // NthSave(savefile, N);
    
    // GcPlayer(*G, 1).
}
