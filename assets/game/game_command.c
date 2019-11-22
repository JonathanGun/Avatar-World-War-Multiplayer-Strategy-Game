#include "game_command.h"
#include "game.h"

char Load[5] = "LOAD";
char Start[6] = "START";
char Exit[5] = "EXIT";
Kata LOAD, START_W, EXIT;

char Attack[7] = "ATTACK";
char Level[9] = "LEVEL_UP";
char Skill[6] = "SKILL";
char Undo[5] = "UNDO";
char End[9] = "END_TURN";
char Save[5] = "SAVE";
char Move[5] = "MOVE";
Kata ATTACK, LEVEL, SKILL, UNDO, END_TURN, SAVE, MOVE;

boolean valid_command(Kata input){
    return(
        CompareKata(input,LOAD)     ||
        CompareKata(input,START_W)  ||
        CompareKata(input,EXIT)
    );
}

void MakeCommand(){
    MakeKata(&LOAD,Load,4);
    MakeKata(&START_W,Start,5);
    MakeKata(&EXIT,Exit,4);
}

boolean valid_aksi(Kata input){
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

void MakeAksi(){
    MakeKata(&ATTACK,Attack,6);
    MakeKata(&LEVEL,Level,8);
    MakeKata(&SKILL,Skill,5);
    MakeKata(&UNDO,Undo,4);
    MakeKata(&END_TURN,End,8);
    MakeKata(&SAVE,Save,4);
    MakeKata(&MOVE,Move,4);
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

void show_valid_command(){
    printf("Berikut daftar Command yang dapat digunakan:\n");
    printf("//=====================================\\\\\n");
    printf("||           ATTACK    SKILL           ||\n");
    printf("||  LEVEL_UP       UNDO      END_TURN  ||\n");
    printf("||            SAVE      MOVE           ||\n");
    printf("||                 EXIT                ||\n");
    printf("\\\\=====================================//\n");
    ENDL;
}

void command_in_game(){
    MakeAksi();

    TulisPeta();
    printf("Player "); print(CurTurn()); ENDL;
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(G.ListBangunan, CurPlayer().list_bangunan);
    TulisSkill(CurPlayer().Skill);
    
    Kata command;
    do{
        show_valid_command();
        printf(">>> ");
        InputKata(&command);
        if(!valid_aksi(command)){
            printf("Masukan salah, tolong input kembali !\n");
        }
    } while(!valid_aksi(command));

    if(CompareKata(command,ATTACK)){
        command_Attack(G);
        if(DEBUG)printf("Attack Berhasil!\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,LEVEL)){
        command_Level_up(G);
        if(DEBUG)printf("Level up berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,SKILL)){
        command_Skill(G);
        if(DEBUG)printf("Skill Berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,UNDO)){
        command_Undo(G);
        if(DEBUG)printf("Undo berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,END_TURN)){
        command_End_turn(G);
        if(DEBUG)printf("End Turn berhasil\n");
    }else if (CompareKata(command,SAVE)){
        command_Save(G);
        if(DEBUG)printf("Save berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else if (CompareKata(command,MOVE)){
        command_Move(G);
        if(DEBUG)printf("Move Berhasil\n");
        printf("Press ENTER to continue"); getchar();
    }else{ //Ketika menulis EXIT
        command_Exit();
    }
    command_in_game();
}

void command_Start() {
    // init player
    InitPlayer();
    if(DEBUG) printf("Berhasil init player\n");

    // init turn
    InitTurn();
    if(DEBUG) printf("Berhasil init turn\n");

    // START game
    StartGame();
}

void command_Attack() {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(G.ListBangunan, CurPlayer().list_bangunan);

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang digunakan untuk menyerang : ");
    int idBAtt = InputValidIntBetween(1, CountList(CurPlayer().list_bangunan));

    Bangunan BAtt;
    idBAtt = ListElmt(CurPlayer().list_bangunan, idBAtt);
    GetBangunanByID(G.ListBangunan, idBAtt, &BAtt);

    // print daftar bangunan yang dapat diserang
    ListBangunan BTerhubung;
    GetBangunanTerhubung(G.Relasi, idBAtt, &BTerhubung);

    printf("Daftar bangunan yang dapat diserang:\n");
    TulisDaftarBangunan(G.ListBangunan, BTerhubung);

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang: ");
    int idBDef = InputValidIntBetween(1, CountList(BTerhubung));

    Bangunan BDef;
    idBDef = ListElmt(BTerhubung, idBDef);
    GetBangunanByID(G.ListBangunan, idBDef, &BDef);

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan: ");
    int jml_pas = InputValidIntBetween(1, Pasukan(BAtt));

    attack(&BAtt, &BDef, jml_pas);
    UpdateBangunan(&G.ListBangunan, idBAtt, BAtt);
    UpdateBangunan(&G.ListBangunan, idBDef, BDef);
    UpdateList(&CurPlayer().list_bangunan, BAtt, CurTurn());
    UpdateList(&CurPlayer().list_bangunan, BDef, CurTurn());
    UpdateList(&OtherPlayer().list_bangunan, BAtt, OtherTurn());
    UpdateList(&OtherPlayer().list_bangunan, BDef, OtherTurn());

    // cek jika permainan berakhir
    if (IsGameEnded()) {
        command_Exit();
    }
}

void command_Level_up() {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(G.ListBangunan, CurPlayer().list_bangunan);
    
    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up: ");
    int idBLvlUp = InputValidIntBetween(1, CountList(CurPlayer().list_bangunan));

    Bangunan BLvl;
    idBLvlUp = ListElmt(CurPlayer().list_bangunan, idBLvlUp);
    GetBangunanByID(G.ListBangunan, idBLvlUp, &BLvl);

    if(Level(BLvl) < 4){
        if (IsLvlUpValid(BLvl)){
            levelup(&BLvl);
            UpdateBangunan(&G.ListBangunan, idBLvlUp, BLvl);
            printf("Level ");printTypeBangunan(BLvl); 
            printf("-mu meningkat menjadi %d !\n", Level(BLvl));
        }else{
            printf("Jumlah pasukan "); printTypeBangunan(BLvl);
            printf(" kurang untuk LEVEL up"); ENDL;
        }
    }else{
        printf("Level Bangunan sudah Maksimum, tidak dapat melakukan LEVEL up lagi\n");
    }
    command_in_game();
}

void command_Skill() {
    // use skill
    if ( IsEmptyQueue(Player(CurTurn()).Skill) ) {
        printf("Anda tidak memiliki skill!\n");
    } else {
        // Menyimpan kondisi sekarang ke dalam stackt
        PushStackt(&G.GameConditions, InfoTopStackt(G.GameConditions));
        useSkill(&Player(CurTurn()).Skill);
    }
}

void command_Undo() {
    // UNDO
    GameCondition Gc;

    // Mengembalikan kondisi sebelumnya
    PopStackt(&G.GameConditions, &Gc);
}

void command_End_turn() {
    // Ganti turn
    CurTurn()%=2;
    CurTurn()++;

    // Reset stackt
    ResetStackt(&G.GameConditions);

    // AddPasukan awal Turn
    Bangunan B;
    int idB;
    int CountBangunan = CountList(CurPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        idB = ListElmt(CurPlayer().list_bangunan, i);
        GetBangunanByID(G.ListBangunan, idB, &B);
        add_pasukan(&B);
        UpdateBangunan(&G.ListBangunan, idB, B);
        UpdateList(&CurPlayer().list_bangunan, B, CurTurn());
    }
    // Memulai turn baru
    StartGame();
}

void command_Save() {
    SaveGame(InfoTopStackt(G.GameConditions), G.ListBangunan);
}

void command_Move() {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(G.ListBangunan, CurPlayer().list_bangunan);

    // input bangunan yang dipilih
    printf("Pilih bangunan : ");
    int idBMov = InputValidIntBetween(1, CountList(CurPlayer().list_bangunan));

    Bangunan BMov;
    idBMov = ListElmt(CurPlayer().list_bangunan, idBMov);
    GetBangunanByID(G.ListBangunan, idBMov, &BMov);

    // print daftar bangunan terdekat
    ListBangunan BTerhubung;
    GetBangunanTerhubung(G.Relasi, idBMov, &BTerhubung);

    printf("Daftar bangunan terdekat:\n");
    TulisDaftarBangunan(G.ListBangunan, BTerhubung);

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");
    int idBSucc = InputValidIntBetween(1, CountList(BTerhubung));

    Bangunan BSucc;
    idBSucc = ListElmt(BTerhubung, idBSucc);
    GetBangunanByID(G.ListBangunan, idBSucc, &BSucc);

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");
    int jml_pas = InputValidIntBetween(1, Pasukan(BMov));

    move(&BMov, &BSucc, jml_pas);

    UpdateBangunan(&G.ListBangunan, idBMov, BMov);
    UpdateBangunan(&G.ListBangunan, idBSucc, BSucc);
    UpdateList(&CurPlayer().list_bangunan, BMov, CurTurn());
    UpdateList(&CurPlayer().list_bangunan, BSucc, CurTurn());
    UpdateList(&OtherPlayer().list_bangunan, BMov, OtherTurn());
    UpdateList(&OtherPlayer().list_bangunan, BSucc, OtherTurn());
}

void command_Exit(){
    printf("Exiting the program...\n"); 
    exit(0); 
}