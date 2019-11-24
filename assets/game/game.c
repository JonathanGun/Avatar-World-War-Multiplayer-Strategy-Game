#include "game.h"
#include "game_command.h"

Game G;
SaveData Save_data;
// Variabel permainan global

void MainMenu() 
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
{   
    // permainan dimulai dari turn player 1
    CurTurn() = 1;
}

void InitSave() {

    // load data permainan
    LoadSavedGame();
}

void InitData() 
{
    //
    MakeData();

    // init save
    InitSave();

}

void InitGame(char* config_file)
{

    // read config
    extract_config(config_file);
    if(DEBUG) printf("Berhasil load file config\n");

    // init map
    InitPeta();
    if(DEBUG) printf("Berhasil inisialisasi map\n");

}

void StartGame()
// Memulai permainan
{
    command_in_game();
}

void LoadGame(int NthData) 
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

void ExitGame()
{
    red();
    printf("Exiting the program...\n");
    exit(0); 
}

boolean IsGameEnded()
{
    // Permainan dinyatakan berakhir jika salah satu permain kalah
    return (IsPlayerLose(1) || IsPlayerLose(2));
}

boolean IsPlayerLose(int player)
{
    // Player n dinyatakan kalah jika list bangunannya kosong
    return IsEmptyList(Player(player).list_bangunan);
}