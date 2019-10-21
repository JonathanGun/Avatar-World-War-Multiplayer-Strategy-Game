#include <stdio.h>
#include <stdlib.h>
#include "arraydinpos.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define floatput(a)   scanf("%f", &a)
#define print(a)      printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(T, i)    for(IdxType i = GetFirstIdx(T);   i <= GetLastIdx(T);    ++i)
#define fori1(T, i)   for(IdxType i = GetFirstIdx(T)+1; i <= GetLastIdx(T);    ++i)
#define forii(T, i)   for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T);   --i)
#define forii1(T, i)  for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T)+1; --i)
#define formax(T, i)  for(IdxType i = GetFirstIdx(T);   i <= MaxElement(T);    ++i)
#define forn(T, i, n) for(IdxType i = GetFirstIdx(T);   i <= n;                ++i)

TabInt InverseTab (TabInt T){
  TabInt T2; MakeEmpty(&T2, MaxElement(T)); CopyTab(T, &T2);
  fori(T2, i) ArrElmt(T2, GetFirstIdx(T2)+NbElmt(T2)-i) = ArrElmt(T,i);
  return T2;
}

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
  MaxEl(*T) = maxel;
  TI(*T) = (ElType *) malloc (sizeof(int) * (maxel+1));
  formax(*T, i) ArrElmt(*T, i) = ValUndef;
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
  MaxEl(*T) = 0;
  free(TI(*T)); 
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  formax(T, i) if (ArrElmt(T, i) == ValUndef) return i-1;
  return MaxElement(T);
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return NbElmt(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((GetFirstIdx(T) <= i) && (i <= MaxElement(T)));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((GetFirstIdx(T) <= i) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (!GetLastIdx(T));
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (MaxElement(T) == GetLastIdx(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  int n;
  do intput(n); while ((n < 0) || (n > MaxElement(*T)));

  if (n){
    ElType tmp;
    forn(*T, i, n){
      intput(tmp);
      ArrElmt(*T, i) = tmp;
    }
  }
  else MakeEmpty(T, 0);
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  printf("[");
  fori(T, i)
    if (i != GetLastIdx(T)) printf("%d,",ArrElmt(T, i));
    else (printf("%d",ArrElmt(T, i)));
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  TabInt T3; MakeEmpty(&T3, MaxEl(T1));
  fori(T3, i)
    if (plus) ArrElmt(T3,i) = ArrElmt(T1,i) + ArrElmt(T2,i);
    else ArrElmt(T3,i) = ArrElmt(T1,i) - ArrElmt(T2,i);
  return T3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
  if (NbElmt(T1) != NbElmt(T2)) return false;
  forn(T1, i, GetLastIdx(T1)){
    if (ArrElmt(T1, i) != ArrElmt(T2, i)) return false;
  }
  return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
  fori(T, i) if (ArrElmt(T, i) == X) return i;
  return IdxUndef;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
  fori(T, i) if (ArrElmt(T, i) == X) return true;
  return false; 
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  int mx, mn; mx = ArrElmt(T, 1); mn = ArrElmt(T, 1);
  fori(T, i) mx = max(ArrElmt(T, i), mx);
  fori(T, i) mn = min(ArrElmt(T, i), mn);
  *Max = mx; *Min = mn;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
  MakeEmpty(Tout, MaxEl(Tin));
  fori(Tin,i) ArrElmt(*Tout,i) = ArrElmt(Tin,i);
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
  int sum = 0;
  fori(T, i) sum += ArrElmt(T, i);
  return sum;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
  int cnt = 0;
  fori(T, i) if (ArrElmt(T, i) == X) cnt++;
  return cnt;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
  if (IsEmpty(T)) return false;
  fori(T, i) if (ArrElmt(T, i)%2 != 0) return false;
  return true;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
  fori1(*T,i) fori1(*T,j) if (ArrElmt(*T,j) < ArrElmt(*T,j-1)) swap(ArrElmt(*T,j), ArrElmt(*T,j-1));  
  if (!asc) *T = InverseTab(*T);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  ArrElmt(*T, NbElmt(*T)+1) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  *X = ArrElmt(*T, NbElmt(*T));
  ArrElmt(*T, NbElmt(*T)) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
  TI(*T) = (ElType *) realloc (TI(*T), sizeof(int) * (MaxEl(*T)+num));
  forn(*T, i, MaxEl(*T)+num){
    if (i > MaxEl(*T)) ArrElmt(*T, i) = ValUndef;
  }
  MaxEl(*T) += num;
}

void ShrinkTab(TabInt *T, int num) {GrowTab(T, -num);}
void CompactTab(TabInt *T) {GrowTab(T, NbElmt(*T)+1-MaxEl(*T));}