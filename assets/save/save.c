#include "save.h"

void UpdataSavedGame(int NthData, Kata savename) {

    GameCondition Gc = InfoTopStackt(G.GameConditions);
    Save_data.data[NthData].config_file = G.config_file;
    Save_data.data[NthData].not_empty = true;
    CopyKataToString(savename, &Save_data.data[NthData].savename);
    CopyGameConditions(Gc, &Save_data.data[NthData].Gc);

}

void SaveGame(int NthData, Kata savename) {
    
    // temporary variable
    GameCondition Gc = InfoTopStackt(G.GameConditions);
    Bangunan B; Queue Skill; address P; FILE *fp; int X, i;

    
    char savefile[21] = "assets/save/save0.txt";
    savefile[16] = NthData+'0';

    // membuka file
    fp = fopen (savefile,"w");

    // simpan savename
    fprintf (fp, "%s\n", Save_data.data[NthData].savename);

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
    fprintf (fp, "$\n");

    fclose(fp);
}

void CheckSaveFile() {
    int i;
    FILE *fp;
    char filename[21] = "assets/save/save0.txt";
    for ( i = 1; i <= MaxSaveData; i++ ) {
        filename[16] = i+'0';
        fp = fopen(filename, "r");
        int c = fgetc(fp);
        if (c != EOF) {
            Save_data.data[i].not_empty = true;
        }
    }
    Save_data.Max = MaxSaveData;
}


void LoadSavedGame() {

    CheckSaveFile();
    
    char savefile[21] = "assets/save/save0.txt";

    int NBangunan, i, j, NSkill;
    for ( i = 1; i <= Save_data.Max; i++ ) {


        savefile[16] = i+'0';

        if ( !Save_data.data[i].not_empty ) {
            continue;
        }

        // load config path

        STARTKATA(savefile);
        if ( i > 1) ADV();
        ADVKATA();
        CopyKataToString(CKata, &Save_data.data[i].savename);
        ADVKATA();
        CopyKataToString(CKata, &Save_data.data[i].config_file);

        // load data

        ADV_file();

        // load turn
        ADV_file();
        Save_data.data[i].Gc.turn = Token.Bil;

        // load data bangunan
        ADV_file();
        NBangunan = Token.Bil;

        ADV_file();
        CreateEmptyList(&Save_data.data[i].Gc.Players[0].list_bangunan);
        CreateEmptyList(&Save_data.data[i].Gc.Players[1].list_bangunan);
        CreateEmptyTabBangunan(&Save_data.data[i].Gc.ListBangunan, NBangunan);
        for ( j = 1; j <= NBangunan; j++ ) {
            Type(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Val;
            ADV_file();
            Row(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil;
            ADV_file();
            Col(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil;
            ADV_file();
            Id(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            Pasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            Level(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            RateTambah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            MaxPasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            Pertahanan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            SudahSerang(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            SudahPindah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            ADV_file();
            BangunanOwner(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil;
            if ( Token.Bil > 0 ) {
                InsertList(&Save_data.data[i].Gc.Players[Token.Bil-1].list_bangunan, Save_data.data[i].Gc.ListBangunan.TB[j].id);
            }
            ADV_file();
        }
        Save_data.data[i].Gc.ListBangunan.NeffTB = NBangunan;

        // load data player

        // player 1

        // load skill
        NSkill = Token.Bil;

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[0].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            Add(&Save_data.data[i].Gc.Players[0].Skill, Token.Bil);
            ADV_file();
        }
        Save_data.data[i].Gc.Players[0].ShieldActive = Token.Bil;
        ADV_file();
        Save_data.data[i].Gc.Players[0].CritHitActive = Token.Bil;
        ADV_file();
        Save_data.data[i].Gc.Players[0].AttUpActive = Token.Bil;
        ADV_file();

        // player 2

        // load skill
        NSkill = Token.Bil;

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[1].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            Add(&Save_data.data[i].Gc.Players[1].Skill, Token.Bil);
            ADV_file();
        }
        Save_data.data[i].Gc.Players[1].ShieldActive = Token.Bil;
        ADV_file();
        Save_data.data[i].Gc.Players[1].CritHitActive = Token.Bil;
        ADV_file();
        Save_data.data[i].Gc.Players[1].AttUpActive = Token.Bil;
    }

}

void TulisSave() {
    int i;
    Data data;
    for ( i = 1; i <= MaxSaveData; i++ ) {
        data = Save_data.data[i];
        if ( data.not_empty ) {
            printf("╔═ Data %d ═════════════════════════════════╗\n", i);
            printf("║                                          ║\n");
            printf("║ Savename : %s                    ║\n", data.savename);
            printf("║ Config : %s            ║\n", data.config_file);
            printf("║ Bangunan P1 : %d                        ", CountList(data.Gc.Players[0].list_bangunan)); printf("%*s║\n", CountList(data.Gc.Players[0].list_bangunan) < 10 ? 2:1, "");
            printf("║ Bangunan P2 : %d                        ", CountList(data.Gc.Players[1].list_bangunan)); printf("%*s║\n", CountList(data.Gc.Players[1].list_bangunan) < 10 ? 2:1, "");
            printf("║ Total bangunan : %d                      ║\n", data.Gc.ListBangunan.NeffTB);
            printf("║                                          ║\n");
            printf("╚══════════════════════════════════════════╝\n");
        } else {
            printf("╔═ Data %d ═════════════════════════════════╗\n", i);
            printf("║                                          ║\n");
            printf("║                                          ║\n");
            printf("║                  S L O T                 ║\n");
            printf("║                                          ║\n");
            printf("║                K O S O N G               ║\n");
            printf("║                                          ║\n");
            printf("║                                          ║\n");
            printf("╚══════════════════════════════════════════╝\n");
        }
    }
}