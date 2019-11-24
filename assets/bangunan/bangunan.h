#ifndef bangunan_H
#define bangunan_H

#include "../util/util.h"
#include "../util/data_bangunan.h"
#include "arraydin_bangunan.h"
#include "list_bangunan.h"
#include "../skill/skill.h"

/* SELEKTOR */
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

/* KONSTRUKTOR */
void CreateBangunanEmpty(Bangunan *B);
/* I.S. B Sembarang */
/* F.S. B terdefinisi sebagai bangunan kosong */

/** KELOMPOK TEST BANGUNAN **/
boolean IsLvlUpValid(Bangunan B);
/* Mengecek apakah bangunan valid untuk di level up, syarat level up adalah jumlah pasukan >= M/2 */
boolean not_IsLevelUpValid(Bangunan B);
/* Mengecek apakah bangunan tidak valid untuk di level up, syarat level up adalah jumlah pasukan >= M/2 */

/** KELOMPOK BACA TULIS **/
void printTypeBangunan(Bangunan B);
/* Mengeprint Type sebuah bangunan */

/** OPERASI PADA BANGUNAN **/
void levelup(int idB);
/* Menaikkan level dari Bangunan Pemain */
void attack(int idBAtt, int idBDef, int jumlah_penyerang);
/* Menghitung perubahan jumlah pasukan saat terjadi penyerangan oleh idBAtt kepada idBDef */
void move(int idBAwal, int idBAkhir, int jumlah_pasukan_pindah);
/* Menghitung perubahan jumlah pasukan saat terjadi perpindahan pasukan (Command : MOVE) */
void add_pasukan();
/* Menghitung perubahan jumlah pasukan saat awal turn */
void TakeOwnership(Bangunan* B);
/* memindah kepemilikan bangunan B ke giliran player saat ini, termasuk juga trigger skill2 yang didapat saat menyerang */
void CopyBangunan(Bangunan Bin, Bangunan *B);
/* I.S. Bin terdefinisi (boleh kosong), B sembarang */
/* F.S. B identik dengan Bin tapi bukan Bangunan yang sama */

#endif