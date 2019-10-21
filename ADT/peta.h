/* Definisi Peta */

#ifndef peta_H
#define peta_H

#include "boolean.h"
#include "arraydinpos.h"
#include "matriks.h"
#include "bangunan.h"

typedef struct {
	char kar;
	int color;
} ReprElmt;
typedef struct {
	TabInt info; // info bangunan
	Matriks repr; //representasi
} Peta;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(int NB, int NK, Peta *P);
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M.repr kosong dengan ukuran NBxNK
*/

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta(Peta P);
/* I.S. P terdefinisi */
/* F.S. Nilai P.repr(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi, dikelilingi box bintang (*) */
/* Proses: Mengupdate P.repr sesuai dengan P.info, lalu menulis nilai setiap elemen P.repr ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks representasi peta 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*****
* C *
*T F*
*  C*
*****
*/

#endif