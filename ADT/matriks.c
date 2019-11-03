#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

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
void MakeMatriks (int NB, int NK, Matriks * M)
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
indeks GetFirstIdxBrs (Matriks M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks GetFirstIdxKol (Matriks M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks GetLastIdxBrs (Matriks M)
/* Mengirimkan indeks baris terbesar M */
{
	return NBrsEff(M);
}

indeks GetLastIdxKol (Matriks M)
/* Mengirimkan indeks kolom terbesar M */
{
	return NKolEff(M);
}

boolean IsIdxEff (Matriks M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return (((BrsMin <= i) && (i <= NBrsEff(M))) && ((KolMin <= j) && (j <= NKolEff(M))));
}

ElType GetElmtDiagonal (Matriks M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return MatElmt(M, i, i);
}


/* ********** Assignment  Matriks ********** */
void CopyMatriks (Matriks MIn, Matriks * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	MakeMatriks(NBrsEff(MIn),NKolEff(MIn),MHsl);
	forall(MIn, i, j){
		MatElmt(*MHsl, i, j) = MatElmt(MIn, i, j);
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMatriks (Matriks * M, int NB, int NK)
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
	forall(*M, i, j){
		int tmp; intput(tmp);
		MatElmt(*M, i, j) = tmp;
	}
}

void TulisMatriks (Matriks M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	forn(i, NBrsEff(M)){
		forn(j, NKolEff(M)){
			if (j >= NKolEff(M)) print(MatElmt(M, i, j));
			else prints(MatElmt(M, i, j));
		}
		if (i != NBrsEff(M)) ENDL;
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matriks TambahMatriks (Matriks M1, Matriks M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
	forall(M1, i, j) MatElmt(M1, i, j) += MatElmt(M2, i, j);
	return M1;
}

Matriks KurangMatriks (Matriks M1, Matriks M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
	forall(M1, i, j) MatElmt(M1, i, j) -= MatElmt(M2, i, j);
	return M1;
}

Matriks KaliMatriks (Matriks M1, Matriks M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	Matriks M3; MakeMatriks(NBrsEff(M1), NKolEff(M2), &M3);
	forn(i, NBrsEff(M1)){
		forn(j, NKolEff(M2)){
			MatElmt(M3, i, j) = 0;
			forn(k, NBrsEff(M2)){
				MatElmt(M3, i, j) += MatElmt(M1, i, k)*MatElmt(M2, k, j);
			}
		}
	}
	return M3;
}

Matriks KaliKons (Matriks M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	PKaliKons(&M, X);
	return M;
}

void PKaliKons (Matriks * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	forall(*M, i, j) MatElmt(*M, i, j) *= K;
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matriks ********** */
boolean EQ (Matriks M1, Matriks M2)
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

boolean NEQ (Matriks M1, Matriks M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return !EQ(M1, M2);
}

boolean EQSize (Matriks M1, Matriks M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* ********** Operasi lain ********** */
int NBElmt (Matriks M)
/* Mengirimkan banyaknya elemen M */
{
	return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP Matriks ********** */
boolean IsBujurSangkar (Matriks M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (Matriks M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	if (!IsBujurSangkar(M)) return false;
	forall(M, i, j) if (MatElmt(M, i, j) != MatElmt(M, j, i)) return false;
	return true;
}

boolean IsSatuan (Matriks M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
	if (!IsBujurSangkar(M)) return false;
	forall(M, i, j){
		if (i == j) {if (MatElmt(M, i, i) != 1) return false;}
		else if (MatElmt(M, i, j) != 0) return false;
	}
	return true;
}

boolean IsSparse (Matriks M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
	int cnt = 0;
	forall(M, i, j) if (MatElmt(M, i, j) != 0) cnt++;
	return cnt*20 <= NBElmt(M);
}

Matriks Inverse1 (Matriks M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	PInverse1(&M);
	return M;
}

Matriks reduce(Matriks m, int rx, int cx){
    Matriks newm; CopyMatriks(m, &newm);
    forall(m, r, c){
    	int newr = r, newc = c;
        if (r > rx) newr--;
        if (c > cx) newc--;
        MatElmt(newm,newr,newc) = MatElmt(m,r,c);
    }
    NBrsEff(newm)--;
    NKolEff(newm)--;
    return newm;
}

int mypow(int n) {
	if (n%2==0) return 1;
	return -1;
}

float Determinan (Matriks M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	// Basis
    if (NBrsEff(M) == GetFirstIdxBrs(M)) return MatElmt(M,GetFirstIdxBrs(M),GetFirstIdxBrs(M));

    // Rekursi
    float ans = 0;
    for(int c = GetFirstIdxKol(M); c <= NKolEff(M); c++){
    	ans += MatElmt(M,GetFirstIdxBrs(M),c)*Determinan(reduce(M, GetFirstIdxBrs(M), c))*mypow(c+1);
    }
    return ans;
}

void PInverse1 (Matriks * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	forall(*M, i, j) MatElmt(*M, i, j) *= -1;
}

void Transpose (Matriks * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	for(int i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
		for(int j = i+1; j <= GetLastIdxKol(*M); j++){
			swap(MatElmt(*M, i, j), MatElmt(*M, j, i));
		}
	}
}