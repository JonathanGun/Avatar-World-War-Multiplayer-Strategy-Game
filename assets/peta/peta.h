#ifndef PETA_H
#define PETA_H

#include "../util/gui.h"
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
void InitPeta();
// Menginisialisasi peta
// I.S. G.map sembarang
// F.S. G.map terisi sesuai dengan array bangunan

/* ********** KELOMPOK BACA/TULIS ********** */
void PrintPeta();
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
void PrintOneTile(int i, int j, ListBangunan* Neighbor1, ListBangunan* Neighbor2);
// I.S. semua parameter terdefinisi
// F.S peta ada satu petak tertulis di layar sesuai warna:
// merah : player 1
// orange : terhubung dgn player 1
// biru : player 2
// cyan : terhubung dgn player 2
// putih : tidak terhubung dan bukan milik player 1 ataupun 2
void PrintPadding();
// I.S. sembarang
// F.S. padding peta tertampil di layar (spasi n kali), n konstan

/**************************** OPERASI LAIN ****************************/
void GetBangunanTerhubungPlayer(ListBangunan* L, int player);
// I.S. L sembarang
// F.S. L terisi dengan daftar indeks bangunan yang terhubung dengan semua bangunan milik suatu player

#endif