#include "game.h"

// Variabel permainan global
/* Game adalah variabel  yang mengendalikan jalannya permainan */
Game G;
SaveData Save_data;

void MainMenu()
// Menampilkan menu utama dari game
{
    gui_logo();
    Kata command;
    MakeCommand();
    do{
        printf(">>> ");
        InputKata(&command);
        if(!valid_command(command)){
            printf("Masukan salah, tolong input kembali!\n"); ENDL;
        }
    } while(!valid_command(command));

    if(CompareKata(command,LOAD)){
        command_Load();
    } else if (CompareKata(command,START_W)){
        command_Start();
    } else { 
        command_Exit();
    } 
}

void InitPlayer()
// Inisialisasi player:
// - pada awal permainan masing-masing player memiliki satu bangunan dengan id 1 dan 2
// - masing-masing player memiliki satu skill instant upgrade
{
    CreateEmptyList(&Player(1).list_bangunan);
    CreateEmptyList(&Player(2).list_bangunan);
    InsertList(&Player(1).list_bangunan, 1);
    InsertList(&Player(2).list_bangunan, 2);

    startSkill(&Player(1).Skill);
    startSkill(&Player(2).Skill);
}

void InitTurn()
// Inisialisasi turn
// turn dimulai dari player pertama
{
    CurTurn() = 1;
}

void InitSave()
// Melakukan load data save
{
    LoadSavedGame();
}

void InitData()
// Inisialisasi data permainan (tabel status (rate tambah, perlindungan, dll) bangunan tiap levelnya) dan save
{
    MakeData();
    InitSave();
}

void InitGame(char* config_file)
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade
{
    // read config
    extract_config(config_file);
    if(DEBUG) printf("Berhasil load file config\n");

    // init map
    InitPeta();
    if(DEBUG) printf("Berhasil inisialisasi map\n");

}

void LoadGame(int NthData)
// Load data ke-NthData
{
    Data data = Save_data.data[NthData];

    // extract config
    InitGame(data.config_file);

    // load turn
    InfoTopStackt(G.GameConditions).turn = data.Gc.turn;

    // load tab bangunan
    CopyTabBangunan(data.Gc.ListBangunan, &InfoTopStackt(G.GameConditions).ListBangunan);

    // load player
    CopyPlayer(data.Gc.Players[0], &InfoTopStackt(G.GameConditions).Players[0]);
    CopyPlayer(data.Gc.Players[1], &InfoTopStackt(G.GameConditions).Players[1]);
}

boolean IsGameEnded()
// IsGameEnded true jika permainan berakhir
{
    // Permainan dinyatakan berakhir jika salah satu permain kalah
    return (IsPlayerLose(1) || IsPlayerLose(2));
}

boolean IsPlayerLose(int player)
// IsPlayeLose(n) true jika player ke-n kalah (tidak memiliki bangunan)
{
    // Player n dinyatakan kalah jika list bangunannya kosong
    return IsEmptyList(Player(player).list_bangunan);
}
