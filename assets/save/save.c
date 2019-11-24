#include "save.h"

void UpdateSavedGame(int NthData, Kata savename)
// Melakukan update pada Save_data setelah melakukan save
// I.S. savename valid
// F.S. save_data ke nthdata berisi data kondisi game saat ini
{
    GameCondition Gc = InfoTopStackt(G.GameConditions);

    // update config
    Save_data.data[NthData].config_file = G.config_file;
    // update not_empty
    Save_data.data[NthData].not_empty = true;
    // update savename
    CopyKataToString(savename, &Save_data.data[NthData].savename);
    // update game condition
    CopyGameConditions(Gc, &Save_data.data[NthData].Gc);

}

void SaveGame(int NthData, Kata savename)
// Menyimpan data pada slot ke-NthData dengan savename "savename"
// I.S. savename valid
// F.S. file dengan nama savename berisi data kondisi game saat itu
{
    // update dave data
    UpdateSavedGame(NthData, savename);
    
    // temporary variable
    GameCondition Gc = InfoTopStackt(G.GameConditions);
    Bangunan B; Queue Skill; address P; FILE *fp; int X, i;

    // file yaitu dari save1.tx sampai save<MaxSaveData>.txt
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

    /* ======================== Simpan data bangunan ========================== */
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

    /* ======================== Simpan player 1 ========================== */
    // simpan skill
    CreateEmptyQueue(&Skill, CountQueue(Player(1).Skill));
    CopyQueue(Player(1).Skill, &Skill);
    fprintf(fp, "%d\n", CountQueue(Skill));
    if ( !IsEmptyQueue(Skill) ) {
        while( !IsEmptyQueue(Skill) ) {
            Del(&Skill, &X);
            fprintf(fp, "%d ", X);
        }
        fprintf(fp, "\n");
    }
    
    // format : <Shield> <Crit> <AttUp>
    fprintf(
        fp, 
        "%d %d %d\n", 
        Player(1).ShieldActive,
        Player(1).CritHitActive,
        Player(1).AttUpActive
        );

    /* ======================== Simpan player 2 ========================== */
    // simpan skill
    CreateEmptyQueue(&Skill, CountQueue(Player(2).Skill));
    CopyQueue(Player(2).Skill, &Skill);
    fprintf(fp, "%d\n", CountQueue(Skill));
    if ( !IsEmptyQueue(Skill) ) {
        while( !IsEmptyQueue(Skill) ) {
            Del(&Skill, &X);
            fprintf(fp, "%d ", X);
        }
        fprintf(fp, "\n");
    }

    // format : <Shield> <Crit> <AttUp>
    fprintf(
        fp, 
        "%d %d %d\n", 
        Player(2).ShieldActive,
        Player(2).CritHitActive,
        Player(2).AttUpActive
        );

    // akhir file
    fprintf (fp, "$\n");

    fclose(fp);
}

void CheckSaveFile()
// Membaca seluruh file penyimpanan
// data ke-i bernilai true jika file save<i>.txt tidak kosong
// I.S. sembarang
// F.S. save_data terisi dengan data dari save<i>.txt
{
    int i; FILE *fp;char filename[21] = "assets/save/save0.txt";
    
    for ( i = 1; i <= MaxSaveData; i++ ) {

        // inisialisasi nama file
        filename[16] = i+'0';

        // membuka file save<i>.txt
        fp = fopen(filename, "r");

        // not_empty data ke i bernilai true jika file save<i>.txt tidak kosong
        int c = fgetc(fp);
        if (c != EOF) {
            Save_data.not_empty = true;
            Save_data.data[i].not_empty = true;
        }
    }
    // Maksimal data permain yang dapat disimpan
    Save_data.Max = MaxSaveData;
}


void LoadSavedGame()
// Membaca keseluruhan data dan menyimpannya ke dalam Save_data
// I.S. sembarang
// F.S. data berisi data dari file save yang dipilih
{
    // Cek masing-masing file
    CheckSaveFile();
    
    char savefile[21] = "assets/save/save0.txt";

    int NBangunan, i, j, NSkill;
    for ( i = 1; i <= Save_data.Max; i++ ) {

        // inisialisasi nama file
        savefile[16] = i+'0';

        // file yang dibaca hanya file yang tidak kosong
        if ( !Save_data.data[i].not_empty ) {
            continue;
        }

        
        STARTKATA(savefile); if ( i > 1) ADV();
        /* ======================== Load savename ========================== */
        ADVKATA();
        CopyKataToString(CKata, &Save_data.data[i].savename);
        /* ======================== Load config path ========================== */
        ADVKATA();
        CopyKataToString(CKata, &Save_data.data[i].config_file);

        /* ======================== Load turn ========================== */
        ADV_file();
        ADV_file();
        Save_data.data[i].Gc.turn = Token.Bil;

        /* ======================== Load data bangunan ========================== */
        ADV_file();
        NBangunan = Token.Bil;

        ADV_file();
        CreateEmptyList(&Save_data.data[i].Gc.Players[0].list_bangunan);
        CreateEmptyList(&Save_data.data[i].Gc.Players[1].list_bangunan);
        CreateEmptyTabBangunan(&Save_data.data[i].Gc.ListBangunan, NBangunan);
        
        for ( j = 1; j <= NBangunan; j++ ) {
            Type(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Val; ADV_file(); // tipe
            Row(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil; ADV_file(); // row
            Col(Save_data.data[i].Gc.ListBangunan.TB[j].posisi) = Token.Bil; ADV_file(); // column           
            Id(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // id
            Pasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // jumlah pasukan
            Level(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // level
            RateTambah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // penambahan pasukan
            MaxPasukan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // maksimum penambahan pasukan
            Pertahanan(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // pertahanan
            SudahSerang(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // sudahserang
            SudahPindah(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ADV_file(); // sudahpindah
            BangunanOwner(Save_data.data[i].Gc.ListBangunan.TB[j]) = Token.Bil; ; // pemilik
            
            // menambahkan bangunan kedalam listbangunan player jika owner bernilai 1 atau 2
            if ( Token.Bil > 0 ) {
                InsertList(&Save_data.data[i].Gc.Players[Token.Bil-1].list_bangunan, Save_data.data[i].Gc.ListBangunan.TB[j].id);
            }
            ADV_file();
        }
        Save_data.data[i].Gc.ListBangunan.NeffTB = NBangunan;

       /* ======================== Load data player 1 ========================== */

        // load skill
        NSkill = Token.Bil;

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[0].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            // menambahkan skill pada player
            Add(&Save_data.data[i].Gc.Players[0].Skill, Token.Bil); ADV_file();
        }
        Save_data.data[i].Gc.Players[0].ShieldActive = Token.Bil; ADV_file();
        Save_data.data[i].Gc.Players[0].CritHitActive = Token.Bil; ADV_file();
        Save_data.data[i].Gc.Players[0].AttUpActive = Token.Bil; ADV_file();

        /* ======================== Load data player 2 ========================== */

        // load skill
        NSkill = Token.Bil;

        ADV_file();
        CreateEmptyQueue(&Save_data.data[i].Gc.Players[1].Skill, 10);
        for ( j = 1; j <= NSkill; j++ ) {
            // menambahkan skill pada player
            Add(&Save_data.data[i].Gc.Players[1].Skill, Token.Bil); ADV_file();
        }
        Save_data.data[i].Gc.Players[1].ShieldActive = Token.Bil; ADV_file();
        Save_data.data[i].Gc.Players[1].CritHitActive = Token.Bil; ADV_file();
        Save_data.data[i].Gc.Players[1].AttUpActive = Token.Bil;
    }
}

void PrintSaveInfo()
// I.S. sembarang
// F.S. data save file tertampil di layar
{
    int i; Data data;

    for ( i = 1; i <= MaxSaveData; i++ ) {
        // load data ke-i
        data = Save_data.data[i];

        // menampilkan data permainan jika data tidak kosong
        if ( data.not_empty ) {
            // data tidak kosong
            printf("╔═ Data %d ═════════════════════════════════╗\n", i);
            printf("║                                          ║\n");
            printf("║ Savename : %s                    ║\n", data.savename);
            printf("║ Config : %s            ║\n", data.config_file);
            printf("║ Bangunan P1 : %d                        ", NbList(data.Gc.Players[0].list_bangunan)); printf("%*s║\n", NbList(data.Gc.Players[0].list_bangunan) < 10 ? 2:1, "");
            printf("║ Bangunan P2 : %d                        ", NbList(data.Gc.Players[1].list_bangunan)); printf("%*s║\n", NbList(data.Gc.Players[1].list_bangunan) < 10 ? 2:1, "");
            printf("║ Total bangunan : %d                     ", data.Gc.ListBangunan.NeffTB); printf("%*s║\n", data.Gc.ListBangunan.NeffTB < 10 ? 2:1, "");
            printf("║                                          ║\n");
            printf("╚══════════════════════════════════════════╝\n");
        } else {
            // data kosong
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