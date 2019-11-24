#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "../util/util.h"

#define NMaxKata 100
#define BLANK ' '
#define NL '\n'
#define MARK '$'

/* STRUKTUR ADT */
typedef struct {
	char TabKata[NMaxKata+1];
	int Length;
} Kata;

extern boolean EndKata;
extern Kata CKata;
extern char CC;
extern boolean EOP;

/****************************** MESIN KARAKTER ******************************/
boolean START(char const *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   filename berupa nama file yang akan diproses, atau 0 jika ingin menerima input dari stdin
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
/* mengembalikan apakah start berhasil/tidak (untuk mengatasi EOP di awal CC) */
void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != EOP/EOF/feof(pita)
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          Jika  CC = MARK maka EOP akan menyala (true) */
boolean IsBlank();
/* Mengembalikan true jika CC = BLANK atau EOL */

/******************************* MESIN KATA *******************************/
boolean STARTKATA(char const *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   filename berupa nama file yang akan diproses, atau 0 jika ingin menerima input dari stdin
   I.S. : sembarang
   F.S. : CKata adalah kata pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
/* mengembalikan apakah startkata berhasil/tidak (untuk mengatasi EOP di awal CC) */
void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ IsBlank() atau CC = MARK */
void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.*/

/***** KONSTRUKTOR KATA *****/
void MakeKata(Kata* K, char C[], int length);
// Membuat kata dari array of character C dengan panjang length

/***** KELOMPOK BACA TULIS *****/
void BacaInt(int *X);
// Membaca sebuah integer dari file yang telah distart
// I.S. X sembarang
// F.S. X terisi angka selanjutnya dari sebuah file
void InputInt(int* X);
// Membaca sebuah integer dari stdin (hingga spasi/EOL/mark)
// I.S. X sembarang
// F.S. X terisi angka yang diinput oleh user
void BacaKata(Kata *K);
// Membaca sebuah kata dari file yang telah distart
// I.S. K sembarang
// F.S. K terisi kata selanjutnya dari sebuah file
void InputKata(Kata* K);
// Membaca sebuah kata dari stdin (hingga spasi/eol/mark)
// I.S. K sembarang
// F.S. K terisi kata yang diinput oleh user
void PrintKata(Kata K);
// Menuliskan representasi K sebagai kumpulan karakter
// I.S. K terdefinisi
// F.S. K tertulis di layar

/***** OPERASI LAIN *****/
int Char2Int();
/* Mengembalikan representasi integer dari angka yang terselip di kata saat ini (CKata) */
/* misal
20 : 20
A3B0 : 30
BJAHSCnakscnajsasd100 : 100
*/
boolean CompareKata(Kata K1, Kata K2);
// Mengembalikan true jika kedua kata identik (panjangnya sama dan isi tiap karakternya sama)
void CopyKataToString(Kata K, char **C);
// I.S. K terdefinisi, C bebas
// F.S. C berisi kumpulan karakter dari K

#endif