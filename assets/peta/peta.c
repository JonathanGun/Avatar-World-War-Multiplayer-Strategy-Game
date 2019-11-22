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

void CopyPeta(Peta P1, Peta *P2){
	forpeta(P1, r, c) PetaElmt(*P2, r, c) = PetaElmt(P1, r, c);
}

void IsiPeta(){
	for(int i = 1; i <= NbBangunan(G.ListBangunan); ++i){
		Bangunan cur = ElmtTB(G.ListBangunan, i);
		PetaElmt(G.map, cur.posisi.r-1, cur.posisi.c-1) = cur.id;
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta()
/* I.S. P terdefinisi */
/* F.S. Nilai P.(i,j) ditulis ke layar per baris per PetaKolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P. sesuai dengan P.info, lalu menulis nilai setiap elemen P. ke layar dengan traversal per baris dan per PetaKolom */
/* Contoh: menulis matriks esentasi peta 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*****
* C *
*T F*
*  C*
*****
*/
{
	printf("    ");
	fori(i, NPetaKolEff(G.map)) {
		printf(" ");
		print(i+1);
		printf(" ");
		if((i+1)/10 == 0) printf(" ");
	}
	ENDL;
	//top
	printf("   ╔");
	fori(i, 4*NPetaKolEff(G.map)-1) (i%4 == 3)?printf("╤"):printf("═");
	printf("╗"); ENDL;

	// mid
	fori(i, NPetaBrsEff(G.map)){
		// num left
		printf(" "); print(i+1);
		if((i+1)/10 == 0) printf(" ");
		printf("║");

		// cell (1 row)
		fori(j, NPetaKolEff((G.map))){
			printf(" ");
			if(PetaElmt(G.map, i, j) == 0)
				printf(" ");
			else{
				Bangunan cur;
				GetBangunanByID(G.ListBangunan, PetaElmt(G.map, i, j), &cur);
				if(cur.owner == 1)
					print_red(cur.type);
				else if(cur.owner == 2)
					print_blue(cur.type);
				else
					printf("%c", cur.type);
			}
			(j == NPetaKolEff(G.map)-1)?printf(" ║"):printf(" │");
		} ENDL;

		// border between cells
		printf("   ");
		(i == NPetaBrsEff(G.map)-1)? printf("╚"): printf("╟");
		if(i == NPetaBrsEff(G.map)-1){
			fori(j, 4*NPetaKolEff(G.map)-1) (j%4==3)? printf("╧"):printf("═");
		} else {
			fori(j, 4*NPetaKolEff(G.map)-1) (j%4==3)? printf("┼"):printf("─");
		}
		(i == NPetaBrsEff(G.map)-1)? printf("╝"): printf("╢");
		printf("   ");
		ENDL;
	}
}
