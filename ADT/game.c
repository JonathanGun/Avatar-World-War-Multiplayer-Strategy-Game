#include "game.h"
#include "../testcommand.c"

boolean FirstTurn;

void InitPlayer(Game *G, Config conf) {
    // Masing-masing pemain memiliki skill IU saat memulai permainan
    startSkill(&Player(*G, 1).Skill);
    startSkill(&Player(*G, 2).Skill);

    // Masing-masing pamain memiliki satu bangunan saat memulai permainan
    CreateEmptyList(&Player(*G, 1).list_bangunan);
    CreateEmptyList(&Player(*G, 2).list_bangunan);
    InsVLast(&Player(*G, 1).list_bangunan, 1);
    InsVLast(&Player(*G, 2).list_bangunan, 2);   
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
    extract_config(&conf);
    // printf("Berhasil load file config\n");

    // init player
    InitPlayer(G, conf);
    // printf("Berhasil inisialisasi player\n");

    // init map
    InitMap(G, conf);
    // printf("Berhasil inisialisasi map\n");

    // init turn
    InitTurn(G);
    // printf("Turn pertama adalah %d\n", CurTurn(*G));

    // start game
    StartGame(G);
}

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

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
    startTurn(Player(*G, CurTurn(*G)));
    TulisPeta((*G).ListBangunan, (*G).map);
    command_in_game(G);
}

void command_Attack(Game* G) {
    // print daftar bangunan
    TulisDaftarBangunan((*G).ListBangunan, Player(*G, CurTurn(*G)).list_bangunan);

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang digunakan untuk menyerang :\n");

    // print daftar bangunan yang dapat diserang

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang :\n");

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan :\n");

    // cek jika permainan berakhir
    if (IsGameEnded(*G)) {
        printf("game ended\n");
    } else {
        command_in_game(G);
    }
}

void command_Level_up(Game* G) {
    // print daftar bangunan

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up : ");

    command_in_game(G);
}

void command_Skill(Game* G) {
    // use skill
    useSkill(&Player(*G, CurTurn(*G)).Skill);

    command_in_game(G);
}

void command_Undo(Game* G) {
    // undo

    command_in_game(G);
}

void command_End_turn(Game* G) {
    // end turn
    // 1 -> 2, 2 -> 1
    CurTurn(*G)%=2;
    CurTurn(*G)++;

    // if(FirstTurn && CurTurn(*G) == 1){
    //     FirstTurn = false;
    // }
    // if(!FirstTurn) startTurn(Player(*G, CurTurn(*G)));

    StartGame(G);
}

void command_Save(Game* G) {
    
    // input lokasi save
    printf("Lokasi save file : ");
}

void command_Move(Game* G) {

    // print daftar bangunan

    // input bangunan yang dipilih
    printf("Pilih bangunan : ");

    // print daftar bangunan terdekat

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");

    command_in_game(G);
}