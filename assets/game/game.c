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

void InitMap()
/* */
{
    IsiPeta();
}

void InitTurn()
/* */
{
    CurTurn() = 1;
}

// void InitSave(Game* G) {
//     STARTKATA("save/")
//     Salin_Save();
// } 

void InitGame()
// Membaca file config dan menginisialisasi attribut pada Game G
// a. Pada saat permainan dimulai, game akan membaca konfigurasi permainan dari file
// eksternal (dijelaskan pada bab selanjutnya).
// b. Queue ​ skill setiap pemain berisi 1 buah skill, yaitu Instant Upgrade
{
    MakeData();

    // read config
    extract_config("resources/config.txt");
    if(DEBUG) printf("Berhasil load file config\n");

    // init map
    InitMap();
    if(DEBUG) printf("Berhasil inisialisasi map\n");

    // init save
    // InitSave(G);
}

void LoadGame(GameCondition Gc)
// Load permainan yang telah disimpan
// I.S : Sembarang
// F.S : G.GameCondition = Gc
{

}

void SaveGame()
/* */
{
    // temporary variable
    Queue Skill;
    int X;
    Bangunan B;
    address P;

    FILE * fp;
    int i;
    /* open the file for writing*/
    fp = fopen ("assets/save/save.txt","w");

    // simpan turn
    fprintf (fp, "%d\n", CurTurn());

    //---------------------- simpan data player 1 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, 10);
    CopyQueue(Player(1).Skill, &Skill);
    if ( IsEmptyQueue(Skill) ) {
        fprintf(fp, "%d ", 0);
    }
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");

    // simpan banyak bangunan
    fprintf(fp, "%d\n", CountList(Player(1).list_bangunan));

    // simpan bangunan
    // format : 
    // id level sudahserang pertahanan pasukan  
    // id level sudahserang pertahanan pasukan
    // ..........   
    P = First(Player(1).list_bangunan);
    while ( P != NULL ) {
        CreateBangunanEmpty(&B);
        GetBangunanByID(G.ListBangunan, Info(P), &B);
        fprintf(fp, "%d %d %d %d %d\n", Id(B), Level(B), SudahSerang(B), Pertahanan(B), Pasukan(B));
        P = Next(P);
    }

    //---------------------- simpan data player 2 -----------------------
    // simpan skill
    CreateEmptyQueue(&Skill, 10);
    CopyQueue(Player(2).Skill, &Skill);
    if ( IsEmptyQueue(Skill) ) {
        fprintf(fp, "%d ", 0);
    }
    while( !IsEmptyQueue(Skill) ) {
        Del(&Skill, &X);
        fprintf(fp, "%d ", X);
    }
    fprintf(fp, "\n");

    // simpan banyak bangun
    // Ambil kondisi game sekarang
    GameCondition Gc = InfoTopStackt(G.GameConditions);
    fprintf(fp, "%d\n", CountList(Player(2).list_bangunan));
    
    // simpan bangunan
    // format : 
    // id level sudahserang pertahanan pasukan
    // id level sudahserang pertahanan pasukan
    // ..........   
    P = First(Player(2).list_bangunan);
    while ( P != NULL ) {
        CreateBangunanEmpty(&B);
        GetBangunanByID(G.ListBangunan, Info(P), &B);
        fprintf(fp, "%d %d %d %d %d\n", Id(B), Level(B), SudahSerang(B), Pertahanan(B), Pasukan(B));
        P = Next(P);
    }

    /* close the file*/  
    fclose (fp);
}

void LoadFromFile(Kata filename)
{
	printf("loaded from "); PrintKata(filename); ENDL;
    printf("Load berhasil!\n");
}

boolean IsGameEnded(){
    return (IsPlayerLose(1) || IsPlayerLose(2));
}

boolean IsPlayerLose(int player){
    return IsEmptyList(Player(player).list_bangunan);
}

void StartGame()
// Memulai permainan
{
    command_in_game();
}
