#include "game.h"

Kata LOAD, START_W, EXIT;
Kata ATTACK, LEVEL, SKILL, UNDO, END_TURN, SAVE, MOVE;
void get_next_command()
/* I.S. sembarang
   F.S. command yang diinput user berjalan sesuai spek */
{
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
        command_Attack();
        if(DEBUG)printf("Attack Berhasil!\n");
        wait_next_command();
    }else if (CompareKata(command,LEVEL)){
        command_Level_up();
        if(DEBUG)printf("Level up berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,SKILL)){
        command_Skill();
        if(DEBUG)printf("Skill Berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,UNDO)){
        command_Undo();
        if(DEBUG)printf("Undo berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,END_TURN)){
        command_End_turn();
        if(DEBUG)printf("End Turn berhasil\n");
    }else if (CompareKata(command,SAVE)){
        command_Save();
        if(DEBUG)printf("Save berhasil\n");
        wait_next_command();
    }else if (CompareKata(command,MOVE)){
        command_Move();
        if(DEBUG)printf("Move Berhasil\n");
        wait_next_command();
    }else{ //Ketika menulis EXIT
        command_Exit();
    }
    get_next_command();
}

void command_Start()
/* Fungsi yang digunakan untuk memulai(inisialisasi) game saat pemain memberi komando START */
{
    // default config
    InitGame("resources/config.txt");

    // init player
    InitPlayer();

    // init turn
    InitTurn();
    if(DEBUG) printf("Berhasil init turn\n");

    // START game
    get_next_command();
}

void command_Load()
/* I.S. Player memilih komando LOAD
   F.S. player memilih slot data permainan yang pernah di-save */
{
    TulisSave();

    if ( !Save_data.not_empty ) {
        printf("Tidak ada slot yang berisi data permainan!\n");
        wait_next_command();
        MainMenu();
    } else {
        printf("Pilih data yang ingin anda load atau ketik 0 untuk kembali ke main menu!\n");
        printf(">>> ");
        int NthData = InputValidIntBetween(0, Save_data.Max);

        if ( NthData == 0 ) {
            MainMenu();
        } else if ( !Save_data.data[NthData].not_empty ) {
            printf("Tidak ada data permainan pada slot ini!\n");
            wait_next_command();
            command_Load();
        } else {
            LoadGame(NthData);
            green();
            printf("Load data berhasil!\n");
            normal();
            wait_next_command();    
            get_next_command();
        }
    }
}


void command_Attack()
/* I.S. Giliran player ke-X, player memilih komando attack
   F.S. player menyerang bangunan lawan dengan serangan sebesar jumlah pasukan, bangunan lawan bisa jatuh atau bisa tetap bertahan*/
{
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    ListBangunan ListPB; CopyList(CurPlayer().list_bangunan, &ListPB);
    FilterListTanpa(&ListPB, bangunan_sudah_serang);
    if(NbList(ListPB) == 0){
        printf("Semua bangunan sudah digunakan untuk menyerang. Silakan pilih command lain!"); ENDL;
        return;
    }
    int idBAtt; ListBangunan BTerhubung;
    do{
        TulisDaftarBangunan(ListPB);

        // input bangunan yang ingin digunakan menyerang
        printf("Bangunan yang digunakan untuk menyerang : ");
        idBAtt = InputValidIntBetween(0, NbList(ListPB));
        if(idBAtt == 0) return;
        idBAtt = ListElmt(ListPB, idBAtt);

        // print daftar bangunan yang dapat diserang
        GetBangunanTerhubung(G.Relasi, idBAtt, &BTerhubung);
        FilterListTanpa(&BTerhubung, bangunan_same_owner);

        if(NbList(BTerhubung) == 0){
            printf("Tidak ada bangunan musuh/netral di sekitar bangunan ini! Silakan pilih bangunan lain!"); ENDL;
            printf("Atau ketik 0 untuk batal serang"); ENDL; ENDL;
        }
    } while(NbList(BTerhubung) == 0);

    printf("Daftar bangunan yang dapat diserang:\n");
    TulisDaftarBangunan(BTerhubung);

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang: ");
    int idBDef = InputValidIntBetween(1, NbList(BTerhubung));
    idBDef = ListElmt(BTerhubung, idBDef);

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan: ");
    int jml_pas = InputValidIntBetween(0, Pasukan(ElmtTB(idBAtt)));

    // push stackt
    PushStackt();

    attack(idBAtt, idBDef, jml_pas);

    // cek jika permainan berakhir
    if (IsGameEnded()) {
        command_Exit();
    }
}

void command_Level_up()
/* I.S. Player memilih komando LEVEL_UP
   F.S. Bila tidak ada bangunan yang bisa level up atau bangunan level maksimal semua, maka keluar pesan error,
   bila ada, akan ditampilkan daftar bangunan yang bisa level up dan player disuruh untuk memilih bangunan yang
   akan di level up. Lalu program melakukan level up ke bangunan tersebut
*/
{
    // print daftar bangunan
    ListBangunan ListPB; CopyList(CurPlayer().list_bangunan, &ListPB);
    FilterListTanpa(&ListPB, not_IsLevelUpValid);
    if(NbList(ListPB) == 0){
        printf("Semua bangunanmu tidak memiliki cukup pasukan untuk melakukan level-up"); ENDL;
        return;
    }
    FilterListTanpa(&ListPB, bangunan_level_maks);
    if(NbList(ListPB) == 0){
        printf("Semua bangunanmu sudah memiliki level maksimal!"); ENDL;
        return;
    }
    printf("Daftar bangunan:\n");
    TulisDaftarBangunan(ListPB);
    
    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up: ");
    int idBLvlUp = InputValidIntBetween(1, NbList(ListPB));
    idBLvlUp = ListElmt(ListPB, idBLvlUp);

    // push stackt
    PushStackt();

    levelup(idBLvlUp);
}

void command_Skill()
/* I.S. Player memilih komando SKILL
   F.S. Menampilkan semua daftar skill yang ada, bila tidak ada keluar pesan error. Bila ada, player otomatis menggunakan skill yang didapatkan lebih awal */
{
    // use skill
    if ( IsEmptyQueue(Player(CurTurn()).Skill) ) {
        printf("Anda tidak memiliki skill!\n");
    } else {      
        useSkill(&Player(CurTurn()).Skill);
        // Reset stackt
        ResetStackt();
    }
}

void command_Undo()
/* I.S. Player memilih komando UNDO 
   F.S. Game tertunda satu turn sebelumnya */
{

    if(IsEmptyStackt(G.GameConditions)){
        printf("Kamu tidak bisa melakukan Undo pada awal turn atau setelah melakukan skill...");ENDL;
    }else{
        // Mengembalikan kondisi sebelumnya
        PopStackt();
    }
}

void command_End_turn()
/* I.S. Player memilih komando END_TURN
   F.S. Game bergerak satu turn ke depan */
{
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
    ResetStackt();

    // AddPasukan awal Turn
    add_pasukan();

    // Reset sudah serang dan sudah pindah
    ResetListBangunan();

    wait_next_command();
    
    // Memulai turn baru
    get_next_command();
}

void command_Save() 
/* I.S. Player memilih komando SAVE
   F.S. Player memilih slot yang ingin digunakan dan meng-input nama file save-an */
{
    printf("Pilih slot yang ingin anda gunakan:\n");

    TulisSave();

    printf(">>> ");
    int NthData = InputValidIntBetween(1, Save_data.Max);

    printf("Input savename(tanpa spasi) : ");
    Kata savename;
    InputKata(&savename);

    SaveGame(NthData, savename);
    // LoadSavedGame();
}

void command_Move()
/* I.S. Player memilih komando MOVE
   F.S. Player memilih bangunan yang ingin memindahkan troop. Bila tidak ada bangunan sekitar, akan keluar pesan error */
{
    // print daftar bangunan
    printf("Daftar bangunan:\n");
    ListBangunan ListPB; CopyList(CurPlayer().list_bangunan, &ListPB);
    FilterListTanpa(&ListPB, bangunan_sudah_pindah);
    if(NbList(ListPB) == 0){
        printf("Semua bangunan sudah pernah dipindah pasukannya pada turn ini. Silakan pilih command lain!"); ENDL;
        return;
    }
    if(DEBUG){
        printf("Filtered bangunan_sudah_pindah:"); ENDL;
        TulisDaftarBangunan(ListPB);ENDL;
    }
    int idBMov; ListBangunan BTerhubung;
    do{
        TulisDaftarBangunan(ListPB);

        // input bangunan yang dipilih
        printf("Pilih bangunan : ");
        idBMov = InputValidIntBetween(0, NbList(ListPB));
        if(idBMov == 0) return;
        idBMov = ListElmt(ListPB, idBMov);

        // print daftar bangunan terdekat
        GetBangunanTerhubung(G.Relasi, idBMov, &BTerhubung);
        FilterListTanpa(&BTerhubung, bangunan_diff_owner);

        if(NbList(BTerhubung) == 0){
            printf("Tidak ada bangunan milik kamu di sekitar bangunan ini! Silakan pilih bangunan lain!"); ENDL;
            printf("Atau ketik 0 untuk batal move"); ENDL; ENDL;
        }
    } while(NbList(BTerhubung) == 0);

    printf("Daftar bangunan terdekat:\n");
    TulisDaftarBangunan(BTerhubung);

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");
    int idBSucc = InputValidIntBetween(1, NbList(BTerhubung));
    idBSucc = ListElmt(BTerhubung, idBSucc);

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");
    int jml_pas = InputValidIntBetween(0, Pasukan(ElmtTB(idBMov)));

    // push stackt
    PushStackt();

    move(idBMov, idBSucc, jml_pas);
}

void command_Exit()
/* Keluar dari permainan saat player memilih EXIT */
{
    red();
    printf("Exiting the program...\n");
    exit(0);
}
