#include "mesinkata.h"

/* State Mesin */
char CC;
boolean EOP;
boolean FirstTimeLoad = true;
boolean EndKata;
Kata CKata;
static FILE * pita;
static int retval;

// MESIN KARAKTER //
boolean START(char const *filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   filename berupa nama file yang akan diproses, atau 0 jika ingin menerima input dari stdin
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
/* mengembalikan apakah start berhasil/tidak (untuk mengatasi EOP di awal CC) */
{
    EOP = false;
    if (filename == 0) pita = stdin;
    else pita = fopen(filename, "r");
    if(FirstTimeLoad){
      FirstTimeLoad = false;
      ADV();
    } 
    return (pita != 0);
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != EOP/EOF/feof(pita)
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          Jika  CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    if(pita != stdin) EOP = (EOF && feof(pita));
    if (EOP) fclose(pita);
}

boolean IsBlank()
/* Mengembalikan true jika CC = BLANK atau EOL */
{
  return CC == BLANK || CC == NL;
}

// MESIN KATA //
boolean STARTKATA(char const *filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   filename berupa nama file yang akan diproses, atau 0 jika ingin menerima input dari stdin
   I.S. : sembarang
   F.S. : CKata adalah kata pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */
/* mengembalikan apakah startkata berhasil/tidak (untuk mengatasi EOP di awal CC) */
{
  boolean valid = (START(filename) != 0);
  if (!valid) {
    EndKata = true;
    return valid;
  }

  EndKata = (CC == MARK || (EOF && feof(pita)));
  return valid;
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  IgnoreBlank();
  SalinKata();
}

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ IsBlank() atau CC = MARK */
{
  while(IsBlank()) ADV();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.*/
{
  int i = 0;
  while(!IsBlank() && CC != '\n'){
    i++;
    CKata.TabKata[i] = CC;
    ADV();    
  }
  CKata.Length = i;
}

/***** KONSTRUKTOR KATA *****/
void MakeKata(Kata* K, char C[], int length)
// Membuat kata dari array of character C dengan panjang length
{
  (*K).Length = length+1;
  for (int i = 1; i < length+1; i++){
    (*K).TabKata[i] = C[i-1];
  }
}

/***** KELOMPOK BACA TULIS *****/
void BacaInt(int *X)
// Membaca sebuah integer dari file yang telah distart
// I.S. X sembarang
// F.S. X terisi angka selanjutnya dari sebuah file
{
  ADVKATA();
  *X = Char2Int();
}

void InputInt(int* X)
// Membaca sebuah integer dari stdin (hingga spasi/EOL/mark)
// I.S. X sembarang
// F.S. X terisi angka yang diinput oleh user
{
  STARTKATA(0);
  BacaInt(X);
}

void BacaKata(Kata *K)
// Membaca sebuah kata dari file yang telah distart
// I.S. K sembarang
// F.S. K terisi kata selanjutnya dari sebuah file
{
  ADVKATA();
  for (int i = 1; i <= CKata.Length; i++) {
    (*K).TabKata[i] = CKata.TabKata[i];
  }
  (*K).TabKata[CKata.Length+1] = 0;
  (*K).Length = CKata.Length+1;
}

void InputKata(Kata* K)
// Membaca sebuah kata dari stdin (hingga spasi/eol/mark)
// I.S. K sembarang
// F.S. K terisi kata yang diinput oleh user
{
  STARTKATA(0);
  BacaKata(K);
}

void PrintKata(Kata K)
// Menuliskan representasi K sebagai kumpulan karakter
// I.S. K terdefinisi
// F.S. K tertulis di layar
{
  for(int i = 1; i <= K.Length; i++){
    printf("%c", K.TabKata[i]);
  }
}

/***** OPERASI LAIN *****/
int Char2Int()
/* Mengembalikan representasi integer dari angka yang terselip di kata saat ini (CKata) */
/* misal
20 : 20
A3B0 : 30
BJAHSCnakscnajsasd100 : 100
*/
{
  int n = CKata.Length+1;
  char *array = CKata.TabKata;
  int number = 0;
  int mult = 1;

  while (n--) {
    if ((array[n] < '0' || array[n] > '9') && array[n] != '-') {
      if (number) break;
      else continue;
    }

    if (array[n] == '-') {
      if (number) {
        number = -number;
        break;
      }
    } else {
      number += (array[n] - '0') * mult;
      mult *= 10;
    }
  }
  return number;
}

boolean CompareKata(Kata K1, Kata K2)
// Mengembalikan true jika kedua kata identik (panjangnya sama dan isi tiap karakternya sama)
{
  if(K1.Length != K2.Length) return false;
  for(int i = 1; i <= K1.Length; i++){
    if(K1.TabKata[i] != K2.TabKata[i]) return false;
  }
  return true;
}

void CopyKataToString(Kata K, char **C)
// I.S. K terdefinisi, C bebas
// F.S. C berisi kumpulan karakter dari K
{
  int i;
  *C = (char*)malloc(sizeof(char)*(K.Length));
  for ( i = 1; i <= K.Length; i++ ) {
    (*C)[i-1] = K.TabKata[i];
  }
}
