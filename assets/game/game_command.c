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
    printf(">>> ");
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

boolean bangunan_same_owner(Bangunan B){
    return B.owner == CurTurn();
}

boolean bangunan_diff_owner(Bangunan B){
    return !bangunan_same_owner(B);
}

boolean bangunan_sudah_serang(Bangunan B){
    return B.sudahserang;
}

boolean bangunan_sudah_pindah(Bangunan B){
    return B.sudahpindah;
}

void wait_next_command(){
    printf("<Press ENTER to continue>"); getchar();
}

void TriggerSkill(){
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
    int CountBangunan = CountList(CurPlayer().list_bangunan);
    for (int i = 1; i <= CountBangunan ; i++){
        int idBLvl = ListElmt(CurPlayer().list_bangunan, i);
        Bangunan *BLvl = &ElmtTB(idBLvl);
        if(Level(*BLvl) != 4){
            CekLvl = false;
        }
    }
    if(CekLvl){//Jika semua bangunan level 4 maka player mendapatkan skill Instant Reinforcement
        if(Add(&CurPlayer().Skill,6)){ //Jika kapasitas skill tidak penuh
            printf("Player ");print(CurTurn());printf(" mendapatkan skill Instant Reinforcement ...");ENDL;
        }else{
            printf("Player ");print(CurTurn());
            printf(" tidak dapat menambahkan skill Instant Reinforcement ...");ENDL;
        }
    }
}

void command_in_game(){
    MakeAksi();

    TulisPeta();
    printf("Player "); print(CurTurn()); ENDL;
    printf("Daftar bangunan:"); ENDL;
    TulisDaftarBangunan(CurPlayer().list_bangunan);
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
        wait_next_command();
    }else if (CompareKata(command,LEVEL)){
        command_Level_up(G);
        if(DEBUG)printf("Level up berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,SKILL)){
        command_Skill(G);
        if(DEBUG)printf("Skill Berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,UNDO)){
        command_Undo(G);
        if(DEBUG)printf("Undo berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,END_TURN)){
        command_End_turn(G);
        if(DEBUG)printf("End Turn berhasil\n");
    }else if (CompareKata(command,SAVE)){
        command_Save(G);
        if(DEBUG)printf("Save berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,MOVE)){
        command_Move(G);
        if(DEBUG)printf("Move Berhasil\n");
        wait_next_command();
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
    ListBangunan ListPB = CurPlayer().list_bangunan;
    FilterListTanpa(&ListPB, bangunan_sudah_serang);
    if(CountList(ListPB) == 0){
        printf("Semua bangunan sudah digunakan untuk menyerang. Silakan pilih command lain!"); ENDL;
        return;
    }
    int idBAtt; ListBangunan BTerhubung;
    do{
        TulisDaftarBangunan(ListPB);

        // input bangunan yang ingin digunakan menyerang
        printf("Bangunan yang digunakan untuk menyerang : ");
        idBAtt = InputValidIntBetween(0, CountList(ListPB));
        if(idBAtt == 0) return;
        idBAtt = ListElmt(ListPB, idBAtt);

        // print daftar bangunan yang dapat diserang
        GetBangunanTerhubung(G.Relasi, idBAtt, &BTerhubung);
        FilterListTanpa(&BTerhubung, bangunan_same_owner);

        if(CountList(BTerhubung) == 0){
            printf("Tidak ada bangunan musuh/netral di sekitar bangunan ini! Silakan pilih bangunan lain!"); ENDL;
            printf("Atau ketik 0 untuk batal serang"); ENDL; ENDL;
        }
    } while(CountList(BTerhubung) == 0);

    printf("Daftar bangunan yang dapat diserang:\n");
    TulisDaftarBangunan(BTerhubung);

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang: ");
    int idBDef = InputValidIntBetween(1, CountList(BTerhubung));
    idBDef = ListElmt(BTerhubung, idBDef);

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan: ");
    int jml_pas = InputValidIntBetween(0, Pasukan(ElmtTB(idBAtt)));

    attack(idBAtt, idBDef, jml_pas);

    // cek jika permainan berakhir
    if (IsGameEnded()) {
        command_Exit();
    }
}

void command_Level_up() {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(CurPlayer().list_bangunan);
    
    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up: ");
    int idBLvlUp = InputValidIntBetween(1, CountList(CurPlayer().list_bangunan));
    idBLvlUp = ListElmt(CurPlayer().list_bangunan, idBLvlUp);

    levelup(idBLvlUp);
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
    // sebelum turn
    TriggerSkill();
    
    // Ganti turn
    if(ExtraTurnActive == false){
        CurTurn()%=2;
        CurTurn()++;
    }else{
        printf("Masih dalam turn player "); print(CurTurn());
        printf(" karena penggunaan skill Extra Turn !"); ENDL;
        ExtraTurnActive = false;
    }
    // Reset stackt
    ResetStackt(&G.GameConditions);

    // AddPasukan awal Turn
    add_pasukan();

    // Reset sudah serang dan sudah pindah
    ResetListBangunan();

    wait_next_command();
    
    // Memulai turn baru
    StartGame();
}

void command_Save() {
    SaveGame();
}

void command_Move() {
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    ListBangunan ListPB = CurPlayer().list_bangunan;
    FilterListTanpa(&ListPB, bangunan_sudah_pindah);
    if(CountList(ListPB) == 0){
        printf("Semua bangunan sudah pernah dipindah pasukannya pada turn ini. Silakan pilih command lain!"); ENDL;
        return;
    }
    int idBMov; ListBangunan BTerhubung;
    do{
        TulisDaftarBangunan(ListPB);

        // input bangunan yang dipilih
        printf("Pilih bangunan : ");
        idBMov = InputValidIntBetween(0, CountList(ListPB));
        if(idBMov == 0) return;
        idBMov = ListElmt(ListPB, idBMov);

        // print daftar bangunan terdekat
        GetBangunanTerhubung(G.Relasi, idBMov, &BTerhubung);
        FilterListTanpa(&BTerhubung, bangunan_diff_owner);

        if(CountList(BTerhubung) == 0){
            printf("Tidak ada bangunan milik kamu di sekitar bangunan ini! Silakan pilih bangunan lain!"); ENDL;
            printf("Atau ketik 0 untuk batal move"); ENDL; ENDL;
        }
    } while(CountList(BTerhubung) == 0);

    printf("Daftar bangunan terdekat:\n");
    TulisDaftarBangunan(BTerhubung);

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");
    int idBSucc = InputValidIntBetween(1, CountList(BTerhubung));
    idBSucc = ListElmt(BTerhubung, idBSucc);

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");
    int jml_pas = InputValidIntBetween(0, Pasukan(ElmtTB(idBMov)));

    move(idBMov, idBSucc, jml_pas);
}

void command_Exit(){
    red();
    printf("Exiting the program...\n");
    exit(0); 
}