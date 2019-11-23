#include "game.h"
#include "game_command.h"

Game G;
void InitPlayer()
/* */
{
    // Masing-masing pemain memiliki skill IU saat memulai permainan
    startSkill(&Player(1).Skill);
    startSkill(&Player(2).Skill);

    // Masing-masing pamain memiliki satu bangunan saat memulai permainan
    CreateEmptyList(&Player(1).list_bangunan);
    CreateEmptyList(&Player(2).list_bangunan);
    InsertList(&Player(1).list_bangunan, 1);
    InsertList(&Player(2).list_bangunan, 2);
}

void InitTurn()
/* */
{
    CurTurn() = 1;
}

void InitSave() {
    LoadSavedGame("assets/save/save.txt");
}

void InitData() {

    MakeData();

    // init save
    InitSave();

}

void InitGame(const char* config_file)
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


void LoadFromFile(Kata filename)
{
	printf("loaded from "); PrintKata(filename); ENDL;
    printf("Load berhasil!\n");
}

void StartGame()
// Memulai permainan
{
    command_in_game();
}

void LoadGame(int NthData) {
    Data data = Save_data.data[NthData];

    // extract config
    InitGame(data.config_file);

    // load turn
    InfoTopStackt(G.GameConditions).turn = data.Gc.turn;

    // load tab bangunan
    CopyTabBangunan(data.Gc.ListBangunan, &InfoTopStackt(G.GameConditions).ListBangunan);
    // TulisIsiTabBangunan2(data.Gc.ListBangunan);
    // TulisIsiTabBangunan2(InfoTopStackt(G.GameConditions).ListBangunan);

    // load player
    CopyPlayer(data.Gc.Players[0], &InfoTopStackt(G.GameConditions).Players[0]);
    CopyPlayer(data.Gc.Players[1], &InfoTopStackt(G.GameConditions).Players[1]);

    StartGame();
}

void ExitGame()
// mengakhiri permainan
{
    command_Exit();
}

boolean IsGameEnded(){
    return (IsPlayerLose(1) || IsPlayerLose(2));
}

boolean IsPlayerLose(int player){
    return IsEmptyList(Player(player).list_bangunan);
}