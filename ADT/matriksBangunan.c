#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define ENDL          printf("\n")

#define formax(M, i)  for(indeks i = 1;	i <= M.BrsMax; ++i)
#define forn(i, n)    for(indeks i = 1; i <= n;        ++i)
#define forall(M,i,j) forn(i, NBrsEff(M)) forn(j, NKolEff(M))

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (int NB, int NK, MatriksBangunan * M)
/* Membentuk sebuah Matriks “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA Matriks" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MatriksBangunan M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks GetFirstIdxKol (MatriksBangunan M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks GetLastIdxBrs (MatriksBangunan M)
/* Mengirimkan indeks baris terbesar M */
{
	return NBrsEff(M);
}

indeks GetLastIdxKol (MatriksBangunan M)
/* Mengirimkan indeks kolom terbesar M */
{
	return NKolEff(M);
}

boolean IsIdxEff (MatriksBangunan M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return (((BrsMin <= i) && (i <= NBrsEff(M))) && ((KolMin <= j) && (j <= NKolEff(M))));
}

ElType GetElmtDiagonal (MatriksBangunan M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return MatElmt(M, i, i);
}


/* ********** Assignment  Matriks ********** */
void CopyMatriks (MatriksBangunan MIn, MatriksBangunan * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	MakeMatriks(NBrsEff(MIn),NKolEff(MIn),MHsl);
	forall(MIn, i, j){
		MatElmt(*MHsl, i, j) = MatElmt(MIn, i, j);
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMatriks (MatriksBangunan * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	MakeMatriks(NB, NK, M);
	// BacaBangunan(*M);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matriks ********** */
boolean EQ (MatriksBangunan M1, MatriksBangunan M2)
/* Mengirimkan true jika M1 = M2, yaitu NBMatElmt(M1) = NBMatElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	if (NBrsEff(M1) != NBrsEff(M2)) return false;
	if (NKolEff(M1) != NKolEff(M2)) return false;
	forn(i, NBrsEff(M1)){
		forn(j, NKolEff(M1)){
			if (MatElmt(M1, i, j) != MatElmt(M2, i, j)) return false;
		}
	}
	return true;
}

boolean NEQ (MatriksBangunan M1, MatriksBangunan M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return !EQ(M1, M2);
}

boolean EQSize (MatriksBangunan M1, MatriksBangunan M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* ********** Operasi lain ********** */
int NBElmt (MatriksBangunan M)
/* Mengirimkan banyaknya elemen M */
{
	return (NBrsEff(M)*NKolEff(M));
}