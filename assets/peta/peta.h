#ifndef PETA_H
#define PETA_H

#include "../util/util.h"
#include "../bangunan/bangunan.h"
#include "../bangunan/arraydin_bangunan.h"
#include "../bangunan/list_bangunan.h"
#include "../graph/graph.h"

/* Selektor */
#define Mem(T) (T).Mem
#define PetaElmt(M, i, j) (M).Mem[(i)][(j)]
#define NPetaBrsEff(M) (M).NPetaBrsEff
#define NPetaKolEff(M) (M).NPetaKolEff
#define forpeta(P, r, c) fori(r, NPetaBrsEff(P)) fori(c, NPetaKolEff(P))

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void MakePeta(int NB, int NK);
/* Membentuk sebuah Peta "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Peta P sesuai dengan definisi di atas terbentuk */
/* Proses : Membuat M.TabInt dan M. kosong dengan ukuran NBxNK
*/

void CopyPeta(Peta P1, Peta *P2);

void InitPeta();

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisPeta();
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

void GetBangunanTerhubungPlayer(ListBangunan* L, int player);

void PrintOneTile(int i, int j, ListBangunan* Neighbor1, ListBangunan* Neighbor2);

#endif