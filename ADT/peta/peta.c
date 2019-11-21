#include "peta.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(Peta *P, int NB, int NK)
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M. kosong dengan ukuran NBxNK
*/
{
	NPetaBrsEff(*P) = NB;
	NPetaKolEff(*P) = NK;
	forpeta(*P, r, c) {
		PetaElmt(*P, r, c) = 0;
	}
}

void CopyPeta(Peta P1, Peta *P2){
	forpeta(P1, r, c) PetaElmt(*P2, r, c) = PetaElmt(P1, r, c);
}

void IsiPeta(TabBangunan B, Peta *P){
	for(int i = 1; i <= NbBangunan(B); ++i){
		Bangunan cur = ElmtTB(B, i);
		PetaElmt(*P, cur.posisi.r-1, cur.posisi.c-1) = cur.id;
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta(TabBangunan B, Peta P)
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
	fori(i, NPetaKolEff(P)+2) printf("*"); ENDL;
	fori(i, NPetaBrsEff(P)){
		printf("*");
		fori(j, NPetaKolEff((P))){
			if(PetaElmt(P, i, j) == 0)
				printf(" ");
			else{
				Bangunan cur;
				GetBangunanByID(B, PetaElmt(P, i, j), &cur);
				if(cur.owner == 1)
					print_red(cur.type);
				else if(cur.owner == 2)
					print_blue(cur.type);
				else
					printf("%c", cur.type);
			}
		}
		printf("*");
		ENDL;
	}
	fori(i, NPetaKolEff(P)+2) printf("*"); ENDL;
}
