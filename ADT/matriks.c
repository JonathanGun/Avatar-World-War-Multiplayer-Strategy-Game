#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (Matriks * M, int NB, int NK)
/* Membentuk sebuah Matriks “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}