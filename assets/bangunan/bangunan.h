#ifndef bangunan_H
#define bangunan_H

#include "../util/util.h"
#include "../util/data_bangunan.h"
#include "../skill/skill.h"
#include "list_bangunan.h"
#include "arraydin_bangunan.h"

#define Row(P) (P).r
#define Col(P) (P).c
#define Id(B) ((B).id)
#define Pasukan(B) ((B).jumlah_pasukan)
#define Level(B) ((B).level)
#define RateTambah(B) ((B).nilai_tambah_pasukan)
#define MaxPasukan(B) ((B).maksimum_tambah_pasukan)
#define Pertahanan(B) ((B).pertahanan)
#define SudahSerang(B) ((B).sudahserang)
#define SudahPindah(B) ((B).sudahpindah)
#define Type(B) ((B). type)
#define BangunanOwner(B) (B).owner

Point MakePoint (int X, int Y);
/* Membentuk sebuah Point dari komponen-komponennya */
void CreateBangunanEmpty(Bangunan *B);
/* */
void CopyBangunan(Bangunan Bin, Bangunan *B);
/* */
boolean IsBangunanEmpty(Bangunan B);
/* Mengecek apakah bangunan adalah bangunan kosong */
boolean IsLvlUpValid(Bangunan B);
/* Mengecek apakah bangunan valid untuk di level up, syarat level up adalah jumlah pasukan >= M/2 */
boolean not_IsLevelUpValid(Bangunan B);
/* */
void levelup(int idB);
/* Menaikkan level dari Bangunan Pemain */
void attack(int idBAtt, int idBDef, int jumlah_penyerang);
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh BAtt kepada BDef */
void move(int idBAwal, int idBAkhir, int jumlah_pasukan_pindah);
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */
void add_pasukan();
/* Menghitung perubahan jumlah pasukan saat awal turn */
void TulisBangunan(Bangunan B);
/* */
void printTypeBangunan(Bangunan B);
/* Mengeprint Type sebuah bangunan */
void TakeOwnership(Bangunan* B);

#endif