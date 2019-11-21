#include "game.h"


void InitPlayer(Game *G) {
    // Masing-masing pemain memiliki skill IU saat memulai permainan
    startSkill(&Player(*G, 1).Skill);
    startSkill(&Player(*G, 2).Skill);

    // Masing-masing pamain memiliki satu bangunan saat memulai permainan
    CreateEmptyList(&Player(*G, 1).list_bangunan);
    CreateEmptyList(&Player(*G, 2).list_bangunan);
    InsertList(&Player(*G, 1).list_bangunan, 1);
    InsertList(&Player(*G, 2).list_bangunan, 2);   
}

void InitMap(Game *G, Config conf) {
    int N = conf.conf_banyak_bangunan;
    int r = conf.conf_peta.NPetaBrsEff;
    int c = conf.conf_peta.NPetaKolEff;
    MakePeta(&(*G).map, r, c);
    CopyTabBangunan(conf.conf_list_bangunan, &(*G).ListBangunan);
    IsiPeta((*G).ListBangunan, &(*G).map);
    (*G).Relasi = conf.conf_relasi;
}

void InitTurn(Game* G) {
    CurTurn(*G) = 1;
}

void InitGame(Game* G)
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade
{
    MakeData();
    // temporary variable
    Config conf;

    // read config
    extract_config("config.txt", &conf);
    // printf("Berhasil load file config\n");

    // init map
    InitMap(G, conf);
    // printf("Berhasil inisialisasi map\n");
}

void LoadFromFile(Game* G, Kata filename)
{
	printf("loaded from "); PrintKata(filename); ENDL;
}

boolean IsGameEnded(Game G){
    return (IsPlayerLose(G, 1) || IsPlayerLose(G, 2));
}

boolean IsPlayerLose(Game G, int player){
    return IsEmptyList(Player(G, player).list_bangunan);
}

void StartGame(Game* G)
// Memulai permainan
{
    command_in_game(G);
}

void command_in_game(Game* G){
    char Attack[7] = "ATTACK";
    char Level[9] = "LEVEL_UP";
    char Skill[6] = "SKILL";
    char Undo[5] = "UNDO";
    char End[9] = "END_TURN";
    char Save[5] = "SAVE";
    char Move[5] = "MOVE";
    char Exit[5] = "EXIT";
    Kata attack, level, skill, undo, end, save, move, EXIT;
    MakeKata(&attack,Attack,6);
    MakeKata(&level,Level,8);
    MakeKata(&skill,Skill,5);
    MakeKata(&undo,Undo,4);
    MakeKata(&end,End,8);
    MakeKata(&save,Save,4);
    MakeKata(&move,Move,4);
    MakeKata(&EXIT,Exit,4);
    ENDL;
    TulisPeta((*G).ListBangunan, (*G).map);
    printf("Player "); print(CurTurn(*G)); ENDL;
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan((*G).ListBangunan, CurPlayer(*G).list_bangunan);
    TulisSkill(CurPlayer(*G).Skill);
    printf("ENTER COMMAND: ");
    Kata command;
    InputKata(&command);
    
    while((CompareKata(command,attack) == 0) && (CompareKata(command,level) == 0) &&(CompareKata(command,skill) == 0)
    && (CompareKata(command,undo) == 0) && (CompareKata(command,end) == 0) && (CompareKata(command,save) == 0)
    && (CompareKata(command,move) == 0) && (CompareKata(command,EXIT) == 0)) {
        printf("Masukan salah, tolong input kembali !\n");
        printf("Berikut daftar Command yang dapat digunakan:\n");
        printf("//=====================================\\\\\n");
        printf("||           ATTACK    SKILL           ||\n");
        printf("||  LEVEL_UP       UNDO      END_TURN  ||\n");
        printf("||            SAVE      MOVE           ||\n");
        printf("||                 EXIT                ||\n");
        printf("\\\\=====================================//\n\n");
        printf("ENTER COMMAND: ");
        InputKata(&command);
    }

    if(CompareKata(command,attack)){
        command_Attack(G);
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,level)){
        command_Level_up(G);
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,skill)){
        command_Skill(G);
        printf("Skill Berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,undo)){
        command_Undo(G);
        printf("Undo berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,end)){
        command_End_turn(G);
        // printf("End Turn berhasil\n");
    }else if (CompareKata(command,save)){
        command_Save(G);
        printf("Save berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,move)){
        command_Move(G);
        printf("Move Berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else{ //Ketika menulis EXIT
        command_Exit();
    }
    command_in_game(G);
}

void input_between_msg(int s, int e){
    printf("Masukkan input antara "); print(s); printf(" dan "); print(e); printf("!"); ENDL;
}

boolean valid_range(int s, int x, int e){
    return s <= x && x <= e;
}

int InputValidIntBetween(int s, int e){
    int tmp;
    do{
        InputInt(&tmp);
        if(!valid_range(s, tmp, e))
            input_between_msg(s, e);
    } while(!valid_range(s, tmp, e));
    return tmp;
}

void command_Start(Game* G) {
    // init player
    InitPlayer(G);

    // init turn
    InitTurn(G);

    // start game
    StartGame(G);
}

void command_Attack(Game* G) {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan((*G).ListBangunan, CurPlayer(*G).list_bangunan);

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang digunakan untuk menyerang : ");
    int idBAtt = InputValidIntBetween(1, CountList(CurPlayer(*G).list_bangunan));

    Bangunan BAtt;
    idBAtt = ListElmt(CurPlayer(*G).list_bangunan, idBAtt);
    GetBangunanByID((*G).ListBangunan, idBAtt, &BAtt);

    // print daftar bangunan yang dapat diserang
    ListBangunan BTerhubung;
    GetBangunanTerhubung((*G).Relasi, idBAtt, &BTerhubung);

    printf("Daftar bangunan yang dapat diserang:\n");
    TulisDaftarBangunan((*G).ListBangunan, BTerhubung);

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang: ");
    int idBDef = InputValidIntBetween(1, CountList(BTerhubung));

    Bangunan BDef;
    idBDef = ListElmt(BTerhubung, idBDef);
    GetBangunanByID((*G).ListBangunan, idBDef, &BDef);

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan: ");
    int jml_pas = InputValidIntBetween(1, Pasukan(BAtt));

    attack(&BAtt, &BDef, jml_pas);
    UpdateBangunan(&(*G).ListBangunan, idBAtt, BAtt);
    UpdateBangunan(&(*G).ListBangunan, idBDef, BDef);
    UpdateList(&CurPlayer(*G).list_bangunan, BAtt, CurTurn(*G));
    UpdateList(&CurPlayer(*G).list_bangunan, BDef, CurTurn(*G));
    UpdateList(&OtherPlayer(*G).list_bangunan, BAtt, OtherTurn(*G));
    UpdateList(&OtherPlayer(*G).list_bangunan, BDef, OtherTurn(*G));

    // cek jika permainan berakhir
    if (IsGameEnded(*G)) {
        command_Exit();
    }
}

void command_Level_up(Game* G) {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan((*G).ListBangunan, CurPlayer(*G).list_bangunan);
    
    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up: ");
    int idBLvlUp = InputValidIntBetween(1, CountList(CurPlayer(*G).list_bangunan));

    Bangunan BLvl;
    idBLvlUp = ListElmt(CurPlayer(*G).list_bangunan, idBLvlUp);
    GetBangunanByID((*G).ListBangunan, idBLvlUp, &BLvl);

    if(Level(BLvl) < 4){
        if (IsLvlUpValid(BLvl)){
            levelup(&BLvl);
            UpdateBangunan(&(*G).ListBangunan, idBLvlUp, BLvl);
            printf("Level ");printTypeBangunan(BLvl); 
            printf("-mu meningkat menjadi %d !\n", Level(BLvl));
        }else{
            printf("Jumlah pasukan "); printTypeBangunan(BLvl);
            printf(" kurang untuk level up"); ENDL;
        }
    }else{
        printf("Level Bangunan sudah Maksimum, tidak dapat melakukan level up lagi\n");
    }
    command_in_game(G);
}

void command_Skill(Game* G) {
    // use skill
    if ( IsEmptyQueue(Player(*G, CurTurn(*G)).Skill) ) {
        printf("Anda tidak memiliki skill!\n");
    } else {
        // Menyimpan kondisi sekarang ke dalam stackt
        PushStackt(&(*G).GameConditions, InfoTopStackt((*G).GameConditions));
        useSkill(&Player(*G, CurTurn(*G)).Skill);
    }
}

void command_Undo(Game* G) {
    // undo
    GameCondition Gc;

    // Mengembalikan kondisi sebelumnya
    PopStackt(&(*G).GameConditions, &Gc);
}

void command_End_turn(Game* G) {
    // Ganti turn
    CurTurn(*G)%=2;
    CurTurn(*G)++;

    // Reset stackt
    ResetStackt(&(*G).GameConditions);

    // AddPasukan awal Turn
    Bangunan B;
    int i;
    int idB;
    int CountBangunan = CountList(CurPlayer(*G).list_bangunan);
    for (i = 1; i <= CountBangunan ; i++){
        idB = ListElmt(CurPlayer(*G).list_bangunan, i);
        GetBangunanByID((*G).ListBangunan, idB, &B);
        add_pasukan(&B);
        UpdateBangunan(&(*G).ListBangunan, idB, B);
        UpdateList(&CurPlayer(*G).list_bangunan, B, CurTurn(*G));
    }
    // Memulai turn baru
    StartGame(G);
}

void command_Save(Game* G) {
    SaveGame(InfoTopStackt((*G).GameConditions), (*G).ListBangunan, InfoTopStackt((*G).GameConditions).turn);
}

void command_Move(Game* G) {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan((*G).ListBangunan, CurPlayer(*G).list_bangunan);

    // input bangunan yang dipilih
    printf("Pilih bangunan : ");
    int idBMov = InputValidIntBetween(1, CountList(CurPlayer(*G).list_bangunan));

    Bangunan BMov;
    idBMov = ListElmt(CurPlayer(*G).list_bangunan, idBMov);
    GetBangunanByID((*G).ListBangunan, idBMov, &BMov);

    // print daftar bangunan terdekat
    ListBangunan BTerhubung;
    GetBangunanTerhubung((*G).Relasi, idBMov, &BTerhubung);

    printf("Daftar bangunan terdekat:\n");
    TulisDaftarBangunan((*G).ListBangunan, BTerhubung);

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");
    int idBSucc = InputValidIntBetween(1, CountList(BTerhubung));

    Bangunan BSucc;
    idBSucc = ListElmt(BTerhubung, idBSucc);
    GetBangunanByID((*G).ListBangunan, idBSucc, &BSucc);

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");
    int jml_pas = InputValidIntBetween(1, Pasukan(BSucc));

    move(&BSucc, &BMov, jml_pas);

    UpdateBangunan(&(*G).ListBangunan, idBMov, BMov);
    UpdateBangunan(&(*G).ListBangunan, idBSucc, BSucc);
    UpdateList(&CurPlayer(*G).list_bangunan, BMov, CurTurn(*G));
    UpdateList(&CurPlayer(*G).list_bangunan, BSucc, CurTurn(*G));
    UpdateList(&OtherPlayer(*G).list_bangunan, BMov, OtherTurn(*G));
    UpdateList(&OtherPlayer(*G).list_bangunan, BSucc, OtherTurn(*G));
}

void command_Exit(){
    printf("Exiting the program...\n"); 
    exit(0); 
}