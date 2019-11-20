#include "peta.h"
#include <stdio.h>
#include <stdlib.h>

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
	Mem(*P) = (int *) malloc (sizeof(int) * (NB+1) * (NK+1));
	forpeta(*P, r, c) PetaElmt(*P, r, c) = -1;
}

void CopyPeta(Peta P1, Peta *P2){
	forpeta(P1, r, c) PetaElmt(*P2, r, c) = PetaElmt(P1, r, c);
}

void UpdatePeta(TabBangunan B, Peta *P){
	for(int i = 1; i <= NbBangunan(B); ++i){
		Bangunan cur = ElmtTB(B, i);
		PetaElmt(*P, cur.posisi.r-1, cur.posisi.c-1) = cur.id;
		print(cur.id); printf(" masuk at "); printf("(%d,%d)", cur.posisi.r-1, cur.posisi.c-1);ENDL;
		TulisPeta(B, *P);
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
			int id = PetaElmt(P, i, j);
			if(id == -1){
				printf(" ");
			} else {
				Bangunan cur = ElmtTB(B, PetaElmt(P, i, j));
				if (BangunanOwner(cur) == 1)
					print_red(Type(cur));
				else if (BangunanOwner(cur) == 2)
					print_blue(Type(cur));
				else
					printf("%c", Type(cur));
			}
		}
		printf("*");
		ENDL;
	}
	fori(i, NPetaKolEff(P)+2) printf("*"); ENDL;
}
