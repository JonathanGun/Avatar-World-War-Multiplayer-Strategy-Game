#ifndef bangunan_H
#define bangunan_H

#include "boolean.h"
#include "point.h"

typedef struct {
	int id;
	int jumlah_pasukan;
	int level;
	int nilai_tambah_pasukan;
	int maksimum_tambah_pasukan;
	boolean pertahanan;
	boolean sudahserang;
	POINT posisi;
	char type;
} Bangunan;

#define Id(B) ((B).id)
#define Pasukan(B) ((B).jumlah_pasukan)
#define	Level(B) ((B).level)
#define RateTambah(B) ((B).nilai_tambah_pasukan)
#define MaxPasukan(B) ((B).maksimum_tambah_pasukan)
#define Pertahanan(B) ((B).pertahanan)
#define SudahSerang(B) ((B).sudahserang)
#define Type(B) ((B). type)


void levelup(Bangunan *B);
/* Menaikkan level dari Bangunan Pemain */

void attack(Bangunan *BAtt, Bangunan *BDef, int jumlah_penyerang);
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */

void move(Bangunan *BAwal, Bangunan *BAkhir, int jumlah_pasukan_pindah);
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */

void add_pasukan(Bangunan *B);
/* Menghitung perubahan jumlah pasukan saat awal turn */
/* Menghitung perubahan jumlah pasukan saat awal*/

Bangunan GetBangunanByID(int id);
/* Mendapatkan bangunan dari ID nya*/

#endif