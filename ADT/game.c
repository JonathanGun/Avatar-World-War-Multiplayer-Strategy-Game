#include "game.h"

void InitPlayer(Game *G, Config conf) {

    // Masing-masing pemain memiliki skill UI saat memulai permainan
    Add(&(P1(*G)).Skill, 1);
    Add(&(P2(*G)).Skill, 1);

    // Masing-masing pamain memiliki satu bangunan saat memulai permainan
    First(P1(*G).list_bangunan) = First(conf.conf_list_bangunan);
    First(P2(*G).list_bangunan) = Next(First(conf.conf_list_bangunan));
}

void InitMap(Game *G, Config conf) {
    int N = conf.conf_banyak_bangunan;
    MakePeta(&(*G).map, N, N);
}

void InitGame(Game* G)
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade
{
    // temporary variable
    Config conf;

    // read config
    extract_config(conf);

    // init player
    InitPlayer(G, conf);

    // init map
    InitMap(G, conf);

}

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void StartGame(Game* G);
// Memulai permainan

void command_Attack() {
    // print daftar bangunan

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang digunakan untuk menyerang : ");

    // print daftar bangunan yang dapat diserang

    // input bangunan yang ingin diserang
    printf("Bangunan yang diserang : ");

    // input jumlah pasukan yang digunakan menyerang
    printf("Jumlah pasukan : ");
}

void command_Level_up() {
    // print daftar bangunan

    // input bangunan yang ingin digunakan menyerang
    printf("Bangunan yang akan di level up : ");
}

void command_Skill() {
    // use skill
}

void command_Undo() {
    // undo
}

void command_End_turn() {
    // end turn
}

void command_Save() {
    
    // input lokasi save
    printf("Lokasi save file : ");
}

void command_Move() {

    // print daftar bangunan

    // input bangunan yang dipilih
    printf("Pilih bangunan : ");

    // print daftar bangunan terdekat

    // input bangunan yang dipilih
    printf("Bangunan yang akan menerima : ");

    // input jumlah pasukan yang dipindahkan
    printf("Jumlah pasukan : ");
}