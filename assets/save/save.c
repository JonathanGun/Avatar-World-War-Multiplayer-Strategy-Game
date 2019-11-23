#include "save.h"

SaveData Save_data;

void SaveGame() {
    GameCondition Gc = InfoTopStackt(G.GameConditions);

    // temporary variable
    Queue Skill;
    int X;
    Bangunan B;
    address P;

    int i;
    FILE *fp;
    /* open the file for writing*/
    fp = fopen ("assets/save/save.txt","a");

    // simpan path config
    fprintf (fp, "%s\n", G.config_file);

    // simpan turn
    fprintf (fp, "%d\n", Gc.turn);

    // simpan data bangunan
    // format <type> <row> <col> <id> <pasukan> <level> <A> <M> <pertahanan> <sudahserang> <sudahpindah> <owner>
    fprintf(fp, "%d\n", Gc.ListBangunan.NeffTB);
    for ( i = 1; i <= Gc.ListBangunan.NeffTB; i++ ) {
        fprintf(
            fp,
            "%c %d %d %d %d %d %d %d %d %d %d %d\n", 
            Type(ElmtTB(i)),
            Row(ElmtTB(i).posisi),
            Col(ElmtTB(i).posisi),
            Id(ElmtTB(i)), 
            Pasukan(ElmtTB(i)), 
            Level(ElmtTB(i)), 
            RateTambah(ElmtTB(i)),
            MaxPasukan(ElmtTB(i)),
            Pertahanan(ElmtTB(i)),
            SudahSerang(ElmtTB(i)),
            SudahPindah(ElmtTB(i)),
            BangunanOwner(ElmtTB(i))
            );
    }

    //---------------------- simpan data player 1 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, CountQueue(Player(1).Skill));
    CopyQueue(Player(1).Skill, &Skill);
    fprintf(fp, "%d\n", CountQueue(Skill));
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");
    // format : <Shield> <Crit> <AttUp>
    fprintf(
        fp, 
        "%d %d %d\n", 
        Player(1).ShieldActive,
        Player(1).CritHitActive,
        Player(1).AttUpActive
        );

    //---------------------- simpan data player 2 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, CountQueue(Player(1).Skill));
    CopyQueue(Player(2).Skill, &Skill);
    fprintf(fp, "%d\n", CountQueue(Skill));
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");
    // format : <Shield> <Crit> <AttUp>
    fprintf(
        fp, 
        "%d %d %d\n", 
        Player(2).ShieldActive,
        Player(2).CritHitActive,
        Player(2).AttUpActive
        );

    // pembatas dengan save lain
    fprintf (fp, "$\n.\n");

    fclose(fp);
}

// void TulisSave() {
//     int i, j;
//     GameCondition Gc;
//     TabBangunan TB;
//     Bangunan B;
//     address P;
//     Queue Skill;
//     for ( i = 1; i <= Saves.Length; i++ ) {
//         Gc = Saves.data[i];
//         TB = Saves.tabBangunan;
//         printf("data %d ---------------", i);
//         printf("Turn : %d\n", Gc.turn);
//         printf(">>>>> Player 1 <<<<<\n");
//         PrintAllSkill(Saves.data[i].Players[0].Skill);
//         printf("bangunan: "); printf("<Id> <Level> <SudahSerang> <Pertahanan> <Pasukan>\n");
//         P = First(GcPlayer(Gc, 1).list_bangunan);
//         j = 1;
//         while ( P != Nil ) {
//             GetBangunanByID(TB, j, &B);
//             printf("%d. ", j);
//             printf("%d ", Id(B));
//             printf("%d ", Level(B));
//             printf("%s ", SudahSerang(B) ? "Ya":"Tidak");
//             printf("%s ", Pertahanan(B) ? "Ya":"Tidak");
//             printf("%d\n", Pasukan(B));
//             P = Next(P);    
//             j++;
//         }
//         printf(">>>>> Player 2 <<<<<\n");
//         printf("bangunan:\n");
//         P = First(GcPlayer(Gc, 2).list_bangunan);
//         j = 1;
//         while ( P != Nil ) {
//             GetBangunanByID(TB, j, &B);
//             printf("Bangunan %d\n", j);
//             printf("Id : %d\n", Id(B));
//             printf("Level : %d\n", Level(B));
//             printf("sudahserang : %s\n", SudahSerang(B) ? "Ya":"Tidak");
//             printf("pertahanan : %s\n", Pertahanan(B) ? "Ya":"Tidak");
//             printf("pasukan : %d\n", Pasukan(B));
//             P = Next(P);    
//             j++;
//         }
//     }
// }

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

    int NBangunan, i, j, NSkill;

    // load config path
    Save_data.Length = CountSave(savefile);

    STARTKATA(savefile);
    // printf("before start CC : %c\n", CC);
    i = 1;
    while ( i <= Save_data.Length ) {
        if ( CC == '.' ) {
            IgnoreLine();
            SalinKata();
            CopyKataToString(CKata, &Save_data.data[Save_data.Length].config_file);
            printf("config : %s\n", Save_data.data[Save_data.Length].config_file);
            i++;
        }
        ADV();
    }

    // load data

    START_file(savefile, 1);
    printf("aftet start file CC : %c\n", CC);

    ADV_file();
    for ( i = 1; i <= Save_data.Length; i++ ) {

        // load turn
        ADV_file();
        Save_data.data[1].Gc.turn = Token.Bil;
        printf("loaded turn : %d\n", Save_data.data[1].Gc.turn);

        // load data bangunan
        ADV_file();
        NBangunan = Token.Bil;
        printf("loaded NBangunan : %d\n", Token.Bil);

        ADV_file();
        CreateEmptyList(&Save_data.data[i].Gc.Players[0].list_bangunan);
        CreateEmptyList(&Save_data.data[i].Gc.Players[1].list_bangunan);
        CreateEmptyTabBangunan(&Save_data.data[i].Gc.ListBangunan, NBangunan);
        for ( j = 1; j <= NBangunan; j++ ) {
            printf(" ============== Bangunan %d ============ \n", j);
            Type(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Val;
            ADV_file();
            Row(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil;
            ADV_file();
            Col(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil;
            ADV_file();
            Id(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded id : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].id);
            ADV_file();
            Pasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded pasukan : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].jumlah_pasukan);
            ADV_file();
            Level(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded level : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].level);
            ADV_file();
            RateTambah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded A : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].nilai_tambah_pasukan);
            ADV_file();
            MaxPasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded M : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].maksimum_tambah_pasukan);
            ADV_file();
            Pertahanan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded pertahanan : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].pertahanan);
            ADV_file();
            SudahSerang(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded sudahserang : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].sudahserang);
            ADV_file();
            SudahPindah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            printf("loaded sudahpindah : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].sudahpindah);
            ADV_file();
            BangunanOwner(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            if ( Token.Bil > 0 ) {
                InsertList(&Save_data.data[i].Gc.Players[Token.Bil-1].list_bangunan, Save_data.data[i].Gc.ListBangunan.TB[j].id);
            }
            printf("loaded owner : %d\n", Save_data.data[i].Gc.ListBangunan.TB[j].owner);
            ADV_file();
        }
        Save_data.data[i].Gc.ListBangunan.NeffTB = NBangunan;

        printf("==========================================\n");

        // load data player

        // player 1

        // load skill
        NSkill = Token.Bil;
        printf("loaded P1 NSkill : %d\n", Token.Bil);

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[0].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            Add(&Save_data.data[i].Gc.Players[0].Skill, Token.Bil);
            printf("%d ", Token.Bil);
            ADV_file();
        }
        printf("\n");
        Save_data.data[i].Gc.Players[0].ShieldActive = Token.Bil;
        printf("loaded P1 Shield : %d\n", Token.Bil);
        ADV_file();
        Save_data.data[i].Gc.Players[0].CritHitActive = Token.Bil;
        printf("loaded P1 Crit : %d\n", Token.Bil);
        ADV_file();
        Save_data.data[i].Gc.Players[0].AttUpActive = Token.Bil;
        printf("loaded P1 AttUp : %d\n", Token.Bil);
        ADV_file();

        // player 2

        // load skill
        NSkill = Token.Bil;
        printf("loaded P2 NSkill : %d\n", Token.Bil);

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[1].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            Add(&Save_data.data[i].Gc.Players[1].Skill, Token.Bil);
            printf("%d ", Token.Bil);
            ADV_file();
        }
        printf("\n");
        Save_data.data[i].Gc.Players[1].ShieldActive = Token.Bil;
        printf("loaded P2 Shield : %d\n", Token.Bil);
        ADV_file();
        Save_data.data[i].Gc.Players[1].CritHitActive = Token.Bil;
        printf("loaded P2 Crit : %d\n", Token.Bil);
        ADV_file();
        Save_data.data[i].Gc.Players[1].AttUpActive = Token.Bil;
        printf("loaded P2 AttUp : %d\n", Token.Bil);
        printf("last CC : %c\n", CC);
        
        if ( i != Save_data.Length ) {
            ADVKATA();
            ADVKATA();
            ADVKATA();
            ADV_file();
        }
    }

}

