#include "mesinfile.h"

TOKEN_config Token;

boolean ValidCharacter() {
/* Mengirimkan true jika Character valid */
    return 
    ( 
        CC == '0'||
        CC == '1'||
        CC == '2'||
        CC == '3'||
        CC == '4'||
        CC == '5'||
        CC == '6'||
        CC == '7'||
        CC == '8'||
        CC == '9'||
        CC == 'C'||
        CC == 'T'||
        CC == 'V'||
        CC == 'F'||
        CC == '.' ||
        CC == MARK
    );
}

void IgnoreNotValidChar()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ( !ValidCharacter() ) ADV();
}


void START_file( char* fileconfig, int Line )
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    int i;
    /* Algoritma */
    START(fileconfig);


    for ( i = 1; i < Line; i++ ) {
        while ( CC != '\n' ) ADV();
        if ( CC == '\n' ) ADV();
    }

    IgnoreNotValidChar();
    if ( CC == MARK ) EndKata = true;
    else {
        EndKata = false;
        Salin_file();
    }
}

void ADV_file()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    /* Algoritma */
    if ( CC == MARK ) EndKata = true;
    else Salin_file();
}

void Salin_file()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    /* Algoritma*/
    Token.Bil = 0;
    for(;;) {   
        if ( !ValidCharacter() || EOP ) break;
        else {
            if ( CC == 'C' || CC == 'V' || CC == 'T' || CC == 'F' ) {
                Token.Val = CC;
                Token.Bil = -1;
            } else {
                Token.Val = 'N';
                Token.Bil = Token.Bil*10 + (CC-'0');
            }
            ADV();
        }
    }

    IgnoreNotValidChar();
}