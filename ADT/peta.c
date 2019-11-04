#include <stdio.h>
#include <stdlib.h>
#include "peta.h"

#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define ENDL          printf("\n")
#define fori(i, n)    for(int i = 1; i <= n; ++i)
#define formax(T, i, j) fori(i, NBrsEff(T)) fori(j, NKolEff(T))

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(Peta *P, int NB, int NK, int NBangunan){
	MakeMatriks(&Repr(*P), NB, NK);
	MakeEmpty(&Info(*P), NBangunan);
}

void MakeMatriks(Matriks * M, int NB, int NK){
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	Mem(*M) = (ReprType *) malloc (sizeof(ReprType) * ((NB+1) * (NK+1)));
	fori(r, NBrsEff(*M)){
		fori(c, NKolEff(*M)){
			MatElmt(*M, r, c).kar = ' ';
			MatElmt(*M, r, c).color = 'x';
		}
	}
}

boolean IsIdxEff (Matriks M, int i, int j) {
	return (((BrsMin <= i) && (i <= NBrsEff(M))) && ((KolMin <= j) && (j <= NKolEff(M))));
}


/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta(Peta P)
/* I.S. P terdefinisi */
/* F.S. Nilai P.repr(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P.repr sesuai dengan P.info, lalu menulis nilai setiap elemen P.repr ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks representasi peta 3x3
*****
* C *
*T F*
*  C*
*****
*/
{
	fori(i, NKolEff(Repr(P))+2) printf("*"); ENDL;
	fori(i, NBrsEff(Repr(P))){
		printf("*");
		fori(j, NKolEff(Repr(P))){
			if ((MatElmt(Repr(P), i, j)).color == 'm'){
				print_red(MatElmt(Repr(P), i, j).kar);
			} else if (MatElmt(Repr(P), i, j).color == 'b'){
				print_blue(MatElmt(Repr(P), i, j).kar);
			} else {
				printf("%c", MatElmt(Repr(P), i, j).kar);
			}
		}
		printf("*");
		ENDL;
	}
	fori(i, NKolEff(Repr(P))+2) printf("*"); ENDL;
}

void ConvertToRepr(Peta P)
/* I.S. P terdefinisi */
/* F.S. Info(P) diubah menjadi Repr(R) yang bersesuaian.
/* Proses: untuk semua elemen Info(P), dicek kepemilikannya, lalu diassign warna dan karakter bersesuaian */
/* Contoh: Castle Player 1 : C Biru, Fort Player 2: F Merah
*****
* C *
*T F*
*  C*
*****
*/
{
	fori(i, Info(P).MaxEl){
		Bangunan cur = GetBangunanByID(ArrElmt(Info(P), i));
		MatElmt(Repr(P), cur.posisi.x, cur.posisi.y).kar = cur.type;
		MatElmt(Repr(P), cur.posisi.x, cur.posisi.y).color = 'm';
	}
	return;
}