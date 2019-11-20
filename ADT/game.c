#include "game.h"

void InitPlayer(Game *G, Config conf) {
    // Masing-masing pemain memiliki skill UI saat memulai permainan
    startSkill(&P1(*G).Skill);
    startSkill(&P1(*G).Skill);

    // Masing-masing pamain memiliki satu bangunan saat memulai permainan
    CreateEmptyList(&P1(*G).list_bangunan);
    CreateEmptyList(&P2(*G).list_bangunan);
    InsVLast(&P1(*G).list_bangunan, 1);
    InsVLast(&P2(*G).list_bangunan, 2);
    
}

void InitMap(Game *G, Config conf) {
    // int N = conf.conf_banyak_bangunan;
    // int r = conf.conf_peta.NPetaBrsEff;
    // int c = conf.conf_peta.NPetaKolEff;
    // MakePeta(&(*G).map, r, c);
    CopyPeta(conf.conf_peta, &(*G).map);
    // TulisPeta(conf.conf_list_bangunan, conf.conf_peta);
    (*G).Relasi = conf.conf_relasi;
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
    extract_config(&conf);
    printf("Berhasil load file config\n");

    // init player
    InitPlayer(G, conf);
    printf("Berhasil inisialisasi player\n");

    // init map
    InitMap(G, conf);
    printf("Berhasil inisialisasi map\n");
}

void LoadGame(Game* G, GameCondition Gc);
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.s : G.GameCondition = Gc

void LoadFromFile(Game* G, Kata filename)
{
	printf("loaded from "); PrintKata(filename); ENDL;
}

void StartGame(Game* G)
// Memulai permainan
{
	printf("Berikut isi file config: "); ENDL;
	printf("Daftar Bangunan:"); ENDL;
	// TulisIsiTab((*G).ListBangunan); ENDL;
	printf("Keterhubungan: "); ENDL;
	PrintGraph((*G).Relasi); ENDL;
	printf("Peta:"); ENDL;
	TulisPeta((*G).ListBangunan, (*G).map);

	printf("Game started!"); ENDL;
}

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