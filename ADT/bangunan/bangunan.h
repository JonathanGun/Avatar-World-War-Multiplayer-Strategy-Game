#ifndef bangunan_H
#define bangunan_H

#include "../util/util.h"
#include "../util/data_bangunan.h"
#include "point.h"

typedef struct {
	int id;
	int jumlah_pasukan;
	int level;
	int nilai_tambah_pasukan;
	int maksimum_tambah_pasukan;
	int owner;
	boolean pertahanan;
	boolean sudahserang;
	Point posisi;
	char type;
} Bangunan;

extern boolean AttackBerhasil;

#define Id(B) ((B).id)
#define Pasukan(B) ((B).jumlah_pasukan)
#define Level(B) ((B).level)
#define RateTambah(B) ((B).nilai_tambah_pasukan)
#define MaxPasukan(B) ((B).maksimum_tambah_pasukan)
#define Pertahanan(B) ((B).pertahanan)
#define SudahSerang(B) ((B).sudahserang)
#define Type(B) ((B). type)
#define BangunanOwner(B) (B).owner

void CreateBangunanEmpty(Bangunan *B);

void CopyBangunan(Bangunan Bin, Bangunan *B);

boolean IsBangunanEmpty(Bangunan B);

boolean IsLvlUpValid(Bangunan B);
/* Mengecek apakah bangunan valid untuk di level up, syarat level up adalah jumlah pasukan >= M/2 */
void levelup(Bangunan *B);
/* Menaikkan level dari Bangunan Pemain */
boolean attack(Bangunan *BAtt, Bangunan *BDef, int jumlah_penyerang);
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */
void move(Bangunan *BAwal, Bangunan *BAkhir, int jumlah_pasukan_pindah);
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */

void add_pasukan(Bangunan *B);
/* Menghitung perubahan jumlah pasukan saat awal turn */

void TulisBangunan(Bangunan B);

#endif