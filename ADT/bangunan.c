#include "bangunan.h"
void levelup(Bangunan *B);
/* Menaikkan level dari Bangunan Pemain */

void attack(Bangunan *BAtt, Bangunan *BDef, int jumlah_penyerang);
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */

void move(Bangunan *BAwal, Bangunan *BAkhir, int jumlah_pasukan_pindah);
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */

void add_pasukan(Bangunan *B);
/* Menghitung perubahan jumlah pasukan saat awal turn */

#endif