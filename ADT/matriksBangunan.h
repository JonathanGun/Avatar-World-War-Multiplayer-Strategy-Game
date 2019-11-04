/* ********** Definisi TYPE Matriks dengan indeks dan elemen integer ********** */

#ifndef matriks_H
#define matriks_H

#include "boolean.h"
#include "bangunan.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef Bangunan ElType;
typedef struct {
    ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatriksBangunan;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (int NB, int NK, MatriksBangunan * M);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatElmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA Matriks" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MatriksBangunan M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MatriksBangunan M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MatriksBangunan M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MatriksBangunan M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MatriksBangunan M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MatriksBangunan M, indeks i);
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  Matriks ********** */
void CopyMatriks (MatriksBangunan MIn, MatriksBangunan * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMatriks (MatriksBangunan * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matriks ********** */
boolean EQ (MatriksBangunan M1, MatriksBangunan M2);
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MatriksBangunan M1, MatriksBangunan M2);
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MatriksBangunan M1, MatriksBangunan M2);
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MatriksBangunan M);
/* Mengirimkan banyaknya elemen M */

#endif