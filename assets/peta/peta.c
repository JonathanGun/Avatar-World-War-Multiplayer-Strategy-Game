#include "peta.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(int NB, int NK)
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M. kosong dengan ukuran NBxNK
*/
{
	NPetaBrsEff(G.map) = NB;
	NPetaKolEff(G.map) = NK;
	forpeta(G.map, r, c) {
		PetaElmt(G.map, r, c) = 0;
	}
}

void InitPeta()
// Menginisialisasi peta
// I.S. G.map sembarang
// F.S. G.map terisi sesuai dengan array bangunan
{
	for(int i = 1; i <= NeffTB(InfoTopStackt(G.GameConditions).ListBangunan); ++i){
		Bangunan* cur = &ElmtTB(i);
		PetaElmt(G.map, (*cur).posisi.r-1, (*cur).posisi.c-1) = (*cur).id;
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void PrintPeta()
/* I.S. P terdefinisi */
/* F.S. Nilai P.(i,j) ditulis ke layar per baris per PetaKolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P. sesuai dengan P.info, lalu menulis nilai setiap elemen P. ke layar dengan traversal per baris dan per PetaKolom */
/* Contoh: menulis matriks peta 10x15
                1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
              ╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗
            1 ║   │   │   │   │   │   │   │   │ V │   │   │   │ T │   │ C ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            2 ║   │   │ C │   │   │   │   │   │   │   │   │   │   │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            3 ║ T │   │   │   │   │   │   │ V │   │   │   │   │   │ C │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            4 ║   │   │   │   │ F │   │   │   │   │   │   │   │   │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            5 ║   │   │   │   │   │   │   │   │   │   │   │ F │   │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            6 ║   │   │ T │   │   │   │   │   │   │   │   │   │   │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            7 ║   │   │   │   │   │   │   │   │   │ T │   │   │   │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            8 ║   │ C │   │   │   │ V │   │   │   │   │   │   │   │   │ T ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
            9 ║   │   │   │   │   │   │   │   │   │   │   │   │ C │   │   ║
              ╟───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───╢
           10 ║ C │   │ T │   │   │   │   │   │   │   │   │   │   │   │   ║
              ╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝
*/
{
	ListBangunan Neighbor1, Neighbor2;
	GetBangunanTerhubungPlayer(&Neighbor1, 1);
	GetBangunanTerhubungPlayer(&Neighbor2, 2);
    map_title();
	ENDL;


	// mid
	fori(i, NPetaBrsEff(G.map)){
		if(i == 0){
			PrintPadding();
			// num top
			yellow();
			printf("    ");
			fori(i, NPetaKolEff(G.map)) {
				printf("  ");
				print(i+1);
				if((i+2)/10 == 0) printf(" ");
			}
			ENDL;
			normal();

			//top
			PrintPadding();
			light_green();
			printf("    ╔");
			fori(i, 4*NPetaKolEff(G.map)-1) (i%4 == 3)?printf("╤"):printf("═");
			printf("╗"); ENDL;
			normal();
		}
		PrintPadding();

		// num left
		yellow();
		printf(" ");
		if((i+1)/10 == 0) printf(" ");
		print(i+1);
		normal();

		// cell (1 row)
		light_green();
		printf(" ║");
		normal();
		fori(j, NPetaKolEff((G.map))){
			PrintOneTile(i, j, &Neighbor1, &Neighbor2);
			light_green();
			(j == NPetaKolEff(G.map)-1)?printf(" ║"):printf(" │");
			normal();
		} ENDL;

		// border between cells
		PrintPadding();
		light_green();
		printf("    ");
		(i == NPetaBrsEff(G.map)-1)? printf("╚"): printf("╟");
		if(i == NPetaBrsEff(G.map)-1){
			fori(j, 4*NPetaKolEff(G.map)-1) (j%4==3)? printf("╧"):printf("═");
		} else {
			fori(j, 4*NPetaKolEff(G.map)-1) (j%4==3)? printf("┼"):printf("─");
		}
		(i == NPetaBrsEff(G.map)-1)? printf("╝"): printf("╢");
		printf("   ");
		ENDL;
		normal();
	}
	ENDL;
    map_description();
}

void PrintOneTile(int i, int j, ListBangunan* Neighbor1, ListBangunan* Neighbor2)
// I.S. semua parameter terdefinisi
// F.S peta ada satu petak tertulis di layar sesuai warna:
// merah : player 1
// orange : terhubung dgn player 1
// biru : player 2
// cyan : terhubung dgn player 2
// putih : tidak terhubung dan bukan milik player 1 ataupun 2
{
	if(PetaElmt(G.map, i, j) == 0){
		printf("  ");
		return;
	}
	Bangunan* cur = &ElmtTB(PetaElmt(G.map, i, j));
	if((*cur).owner == 1)
		red();
	else if((*cur).owner == 2)
		light_blue();
	else if(CurTurn() == 1){
		if(SearchList(*Neighbor1, PetaElmt(G.map, i, j)))
			orange();
		else if(SearchList(*Neighbor2, PetaElmt(G.map, i, j)))
			light_cyan();
		else
			normal();
	} else {
		if(SearchList(*Neighbor2, PetaElmt(G.map, i, j)))
			light_cyan();
		else if(SearchList(*Neighbor1, PetaElmt(G.map, i, j)))
			orange();
		else
			normal();
	}
	printf(" %c", (*cur).type);
	normal();
}

void PrintPadding()
// I.S. sembarang
// F.S. padding peta tertampil di layar (spasi n kali), n konstan
{
	printf("          ");
}

/**************************** OPERASI LAIN ****************************/
void GetBangunanTerhubungPlayer(ListBangunan* L, int player)
// I.S. L sembarang
// F.S. L terisi dengan daftar indeks bangunan yang terhubung dengan semua bangunan milik suatu player
{
	CreateEmptyList(L);
	address P = First(Player(player).list_bangunan);
    while(P != Nil){
    	ListBangunan LB;
    	GetBangunanTerhubung(G.Relasi, Info(P), &LB);
    	address Pn = First(LB);
    	while(Pn != Nil){
    		if(SearchList(*L, Info(Pn)) == Nil)
    			InsertList(L, Info(Pn));
    		Pn = Next(Pn);
    	}
        P = Next(P);
    }
}
