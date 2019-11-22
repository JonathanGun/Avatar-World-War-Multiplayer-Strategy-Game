#include "save.h"

void SaveGame(GameCondition Gc, TabBangunan list_bangunan) {
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

    // simpan turn
    fprintf (fp, "%d\n", Gc.turn);

    //---------------------- simpan data player 1 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, 10);
    CopyQueue(P1.Skill, &Skill);
    fprintf(fp, "%d\n", CountQueue(Skill));
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
    fprintf(fp, "%d\n", CountQueue(Skill));
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

    // pembatas dengan save lain
    fprintf (fp, "$");

    fclose(fp);
}

void TulisSave() {
    int i, j;
    GameCondition Gc;
    TabBangunan TB;
    Bangunan B;
    address P;
    Queue Skill;
    for ( i = 1; i <= Saves.Length; i++ ) {
        Gc = Saves.data[i];
        TB = Saves.tabBangunan;
        printf("data %d ---------------", i);
        printf("Turn : %d\n", Gc.turn);
        printf(">>>>> Player 1 <<<<<\n");
        PrintAllSkill(Saves.data[i].Players[0].Skill);
        printf("bangunan: "); printf("<Id> <Level> <SudahSerang> <Pertahanan> <Pasukan>\n");
        P = First(GcPlayer(Gc, 1).list_bangunan);
        j = 1;
        while ( P != Nil ) {
            GetBangunanByID(TB, j, &B);
            printf("%d. ", j);
            printf("%d ", Id(B));
            printf("%d ", Level(B));
            printf("%s ", SudahSerang(B) ? "Ya":"Tidak");
            printf("%s ", Pertahanan(B) ? "Ya":"Tidak");
            printf("%d\n", Pasukan(B));
            P = Next(P);    
            j++;
        }
        printf(">>>>> Player 2 <<<<<\n");
        printf("bangunan:\n");
        P = First(GcPlayer(Gc, 2).list_bangunan);
        j = 1;
        while ( P != Nil ) {
            GetBangunanByID(TB, j, &B);
            printf("Bangunan %d\n", j);
            printf("Id : %d\n", Id(B));
            printf("Level : %d\n", Level(B));
            printf("sudahserang : %s\n", SudahSerang(B) ? "Ya":"Tidak");
            printf("pertahanan : %s\n", Pertahanan(B) ? "Ya":"Tidak");
            printf("pasukan : %d\n", Pasukan(B));
            P = Next(P);    
            j++;
        }
    }
}

int CountSave(const char* savefile) {
    int Count = 0;
    START_file(savefile, 1);
    while (!EOP) {
        if ( CC == '$') {
            Count++;
        }
        ADV();
    }
    return Count;
}

void NthSave(const char* savefile, int *N) {
    int L = 0;
    do {
        L++;
        START_file(savefile, L);
        if ( CC == '$' ) {
            (*N)--;
        }
    } while (*N > 1);
    *N = L+1;
}

void LoadSavedGame(const char* savefile) {
    CreateEmptyTabBangunan(&Saves.tabBangunan, 20);
    int NSave = CountSave(savefile);
    // temporary variables
    Queue Skill;
    ListBangunan list_bangunan;
    Bangunan B;
    int i = 1;
    int N;
    while ( i <= NSave ) {
        N = i;
        printf("save ke %d\n",N);
        NthSave(savefile, &N);

        int jumlah_skill, jumlah_bangunan;
        int X;

        // load turn
        START_file(savefile, N);
        Saves.data[i].turn = Token.Bil;

        // ----------------- load data player1 ----------------------
        // load skill
        START_file(savefile, N + 1);
        jumlah_skill = Token.Bil;
        X = Token.Bil;
        START_file(savefile, N + 2);
        CreateEmptyQueue(&Skill, 10);
        while ( X > 0) {
            Add(&Skill, Token.Bil);
            ADV_file();
            X--;
        }
        GcPlayer(Saves.data[i], 1).Skill = Skill;

        // load bangunan
        CreateEmptyList(&list_bangunan);
        // load jumlah bangunan
        START_file(savefile, N + 3);
        jumlah_bangunan = Token.Bil;

        X = 1;
        while ( X <= jumlah_bangunan ) {
            CreateBangunanEmpty(&B);
            // load id
            START_file(savefile, N + 3 + X);
            Id(B) = Token.Bil;
            // printf("Token bil : %d\n", Id(B));
            InsertList(&list_bangunan, Id(B));
            // load level
            ADV_file();
            Level(B) = Token.Bil;
            // load sudah serang
            ADV_file();
            SudahSerang(B) = Token.Bil;
            // load pertahanan
            ADV_file();
            Pertahanan(B) = Token.Bil;
            // load pasukan
            ADV_file();
            Pasukan(B) = Token.Bil;
            Saves.tabBangunan.TB[Id(B)] = B;
            X++;
        }
        CopyList(list_bangunan, &GcPlayer(Saves.data[i], 1).list_bangunan);
        i++;

        N = N + 3 + jumlah_bangunan;
    }
    
    Saves.Length = NSave;
}

// void LoadGame(const char* savefile, GameCondition *G, TabBangunan *TB, int N) {

//     // temporary variables
//     Queue Skill;
//     ListBangunan list_bangunan;
//     Bangunan B;

//     int jumlah_skill, jumlah_bangunan;
//     int X;
//     NthSave(savefile, &N);

//     // load turn
//     START_file(savefile, N);
//     (*G).turn = Token.Bil;

//     // load data player1
//     // load skill
//     START_file(savefile, N + 1);
//     jumlah_skill = Token.Bil;
//     X = Token.Bil;
//     START_file(savefile, N + 2);
//     CreateEmptyQueue(&Skill, 10);
//     while ( X > 0) {
//         Add(&Skill, Token.Bil);
//         ADV_file();
//         X--;
//     }
//     GcPlayer(*G, 1).Skill = Skill;

//     // load bangunan
//     CreateEmptyList(&list_bangunan);
//     // load jumlah bangunan
//     START_file(savefile, N + 3);
//     jumlah_bangunan = Token.Bil;

//     X = 1;
//     while ( X <= jumlah_bangunan ) {
//         CreateBangunanEmpty(&B);
//         // load id
//         START_file(savefile, N + 3 + X);
//         Id(B) = Token.Bil;
//         InsertList(&list_bangunan, Id(B));
//         // load level
//         ADV_file();
//         Level(ElmtTB(*TB, Id(B))) = Token.Bil;
//         // load sudah serang
//         ADV_file();
//         SudahSerang(ElmtTB(*TB, Id(B))) = Token.Bil;
//         // load pertahanan
//         ADV_file();
//         Pertahanan(ElmtTB(*TB, Id(B))) = Token.Bil;
//         // load pasukan
//         ADV_file();
//         Pasukan(ElmtTB(*TB, Id(B))) = Token.Bil;
//         X++;
//     }
//     CopyList(list_bangunan, &GcPlayer(*G, 1).list_bangunan);

// }
