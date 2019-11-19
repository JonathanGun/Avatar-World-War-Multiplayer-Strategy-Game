#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (Matriks * M, int NB, int NK)
/* Membentuk sebuah Matriks “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* ********************** SELEKTOR ************************ */
boolean IsIdxValid (int i, int j){
    return((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return(BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return(NBrsEff(M));
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return(NKolEff(M));
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return((i>=BrsMin) && (i<=GetLastIdxBrs(M)) && (j>=KolMin) && (j<=GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return(Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */
void TulisMATRIKS (Matriks M)
/* Menulis isi dari matriks M */
/* I.S. Matriks M Terdefinisi dan Memiliki elemen
   F.S. Matriks Tercetak di layar */{
    for(indeks i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for(indeks j=GetFirstIdxKol(M); j<= GetLastIdxKol(M); j++){
            if((i == GetLastIdxBrs(M)) && (j == GetLastIdxKol(M))){
                printf("%d", Elmt(M,i,j));
            }
            else if(j==GetLastIdxKol(M)){
                printf("%d\n", Elmt(M,i,j));
            }
            else{
                printf("%d ", Elmt(M,i,j));
            }
        }
    }
}