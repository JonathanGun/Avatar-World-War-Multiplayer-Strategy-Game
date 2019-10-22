/* File: graph.c */
/* Tanggal: 22 Oktober 2019 */
/* *** Definisi ABSTRACT DATA TYPE GRAPH *** */

#include "graph.h"

/* Definisi tipe data GRAPH: memiliki ID ( dalam matriks baris ) dan relasinya ( dalam matriks kolom ) ke ID lainnya.
 indeks dari suatu GRAPH adalah titiknya dalam map.
 Bila terdapat 2 graph dan GRAPH A memiliki relasi ke GRAPH B maka pasti GRAPH B memiliki relasi ke GRAPH A */

/* ----- KONSTRUKTOR ----- */
GRAPH MakeGRAPH(int ID, int NbRelasi, int x, int y)
/*Membuat Graph dengan banyak relasi sejumlah banyaknya elemen*/
/*Relasi GRAPH kosong*/
/*Koordinat GRAPH adalah A */
{
    GRAPH G;
    ID(G) = ID;
    G.Relasi = (int *) malloc (sizeof(int) * (NbRelasi+1)); //indeks dari 0
    KoorX(G) = x;
    KoorY(G) = y;
    NbRelasi(G) = NbRelasi;
    return G;
}

MGRAPH MakeMGRAPH(int NbGraph)
/* Membuat matrix of GRAPH kosong */
{
    MGRAPH MG;
    MG.TG = (GRAPH *) malloc (sizeof(GRAPH) * (NbGraph+1));
    NbGraph(MG) = NbGraph;
    return MG;
}

/* ----- INTERAKSI IN/ OUT DEVICE ----- */
void BacaRelasi (GRAPH *G)
/* Membaca masing masing relasi di graph */
/* Misalnya ada relasi dari GRAPH G ke ID sekian, tulis 1, selain itu 0 */
{
    for(int i = 1; i<= NbRelasi(*G) ; i++){
        scanf(Relasi(*G,i));
    }
}
void BacaMGRAPH (MGRAPH *MG)
/* Membaca relasi berulang ulang sampai semua GRAPH dalam MGRAPH relasinya terdefinisi */
{
    for(int i = 1; i<= NbGraph(*MG) ; i++){
        BacaRelasi(&Graph(*MG,i));
    }
}
void InsertGRAPH(GRAPH G, MGRAPH *MG, int idx)
/* Menyisipkan GRAPH G ke dalam MGRAPH MG dengan indeks idx */
{
     Graph(*MG,idx) = G;
}
void TulisGRAPH (GRAPH G)
/* Menuliskan relasi ke layar*/
/* Relasi dituliskan dalam bentuk true atau false */
/* Bila suatu GRAPH memiliki relasi dengan GRAPH lain, akan bernilai 1, kalau tidak akan bernilai 0 */
/* F.S. Relasi tertulis di layar dengan format "R1 R2 R3 ... RN" */
/* Contoh penulisan relasi : 0 1 1 0 1 0 
   Dibaca: GRAPH memiliki relasi ke GRAPH ber ID 2, 3 , dan 5
   GRAPH tidak mungkin memiliki relasi ke dirinya sendiri*/
{
    for(int i = 1 ; i<= NbRelasi(G)-1 ; i++){
        printf("%d ",Relasi(G,i));
    }
    printf("%d\n",Relasi(G,NbRelasi(G)));
}

void TulisMGRAPH(MGRAPH MG)
/* Menulis matriks graph secara keseluruhan */
{
    for(int j = 1; j<= NbGraph(MG) ; j++){
        TulisGRAPH(Graph(MG,j));
    }
}

void Dealokasi(MGRAPH *MG)
/* Mengembalikan array eksplisit Relasi dan TabGraph ke sistem */
{
    free((*MG).TG);
    for(int i = 1; i<= NbGraph(*MG); i++){
        free(Graph(*MG,i).Relasi);
    }
}

/* ----- OPERATOR BOOLEAN ----- */
boolean IsRelasiValid (GRAPH G, int X)
/* Menghasilkan true jika masukan 1 <= X <= NbRelasi(G) */
{
    return(X>=1 && X<=NbRelasi(G));
}
boolean IsRelated (GRAPH G1,GRAPH G2)
/* Menghasilkan true GRAPH saling terhubung */
{
    return(Relasi(G1,ID(G2))); //kalo relasi di indeks ID G2 adalah 1 maka true, bila 0 maka false
}
boolean SearchRelasi (GRAPH G, int X)
/* Menghasilkan true jika relasi graph G ke X adalah 1*/
{
    if(!IsRelasiValid(G,X)){
        return false;
    }
    return(Relasi(G,X));
}
