/* File: graph.c */
/* Tanggal: 22 Oktober 2019 */
/* *** Definisi ABSTRACT DATA TYPE GRAPH *** */

#include "graph.h"

/* Definisi tipe data GRAPH: memiliki ID ( dalam matriks baris ) dan relasinya ( dalam matriks kolom ) ke ID lainnya.
 indeks dari suatu GRAPH adalah titiknya dalam map.
 Bila terdapat 2 graph dan GRAPH A memiliki relasi ke GRAPH B maka pasti GRAPH B memiliki relasi ke GRAPH A */

/* ----- KONSTRUKTOR ----- */
GRAPH MakeGRAPH(int ID, int NbRelasi)
/*Membuat Graph dengan banyak relasi sejumlah banyaknya elemen*/
/*Relasi GRAPH kosong*/
/*Koordinat GRAPH adalah A */
{
    GRAPH G;
    ID(G) = ID;
    G.Relasi = (int *) malloc (sizeof(int) * (NbRelasi+1)); //indeks dari 0
    NbRelasi(G) = NbRelasi;
    return G;
}

MGRAPH MakeMGRAPH(int NbGraph)
/* Membuat matrix of GRAPH kosong */
{
    MGRAPH MG;
    MG.TG = (GRAPH *) malloc (sizeof(GRAPH) * (NbGraph+1));
    for(int i  = 1 ; i<= NbGraph ; i++){
        MG.TG[i] = MakeGRAPH(i,NbGraph);
    }
    NbGraph(MG) = NbGraph;
    return MG;
}

void Dealokasi(MGRAPH *MG)
/* Mengembalikan array eksplisit Relasi dan TabGraph ke sistem */
{
    free((*MG).TG);
    for(int i = 1; i<= NbGraph(*MG); i++){
        free(Graph(*MG,i).Relasi);
    }
}

void CreateMGRAPH(MGRAPH *MG)
/* I.S. Matrix of Graph terdefinisi */
/*Membuat matrix of GRAPH dan mengisinya */
{
    int N;
    printf("Tuliskan banyaknya bangunan: ");
    scanf("%d",&N);
    *MG = MakeMGRAPH(N);
    printf("Tuliskan relasi antar bangunan: \n");
    BacaMGRAPH(MG);
    CorrectMGRAPH(MG);
}

void CorrectMGRAPH(MGRAPH  *MG)
/* Membetulkan Matrix of Graph , yaitu misalnya ada relasi G1 ke G2 tapi tidak ada sebaliknya, */
/* maka relasi G2 ke G1 akan dikoreksi menjadi 1 */
{
    for(int i = 1 ; i<= NbGraph(*MG) ; i++){
        for(int j = 1 ; j<= NbRelasi(Graph(*MG,i)) ; j++){
            if(IsRelated(Graph(*MG,i),Graph(*MG,j)) && !IsRelated(Graph(*MG,j),Graph(*MG,i))){
                Relasi(Graph(*MG,j),i) = 1;
            }
        }
    }
}

/* ----- INTERAKSI IN/ OUT DEVICE ----- */
void BacaRelasi (GRAPH *G)
/* Membaca masing masing relasi di graph */
/* Misalnya ada relasi dari GRAPH G ke ID sekian, tulis 1, selain itu 0 */
{
    for(int i = 1; i<= NbRelasi(*G) ; i++){
        scanf("%d",&Relasi(*G,i));
        if(!IsRelasiValid(Relasi(*G,i))){
            Relasi(*G,i) = (Relasi(*G,i) < 0) ? 0 : 1; //kalo relasi < 0 berarti 0 , kalo > 1 maka 1
        }
    }
}
void BacaMGRAPH (MGRAPH *MG)
/* Membaca relasi berulang ulang sampai semua GRAPH dalam MGRAPH relasinya terdefinisi */
{
    for(int i = 1; i<= NbGraph(*MG) ; i++){
        printf("Tuliskan relasi bangunan ke-%d : ",i);
        Graph(*MG,i) = MakeGRAPH(i,NbGraph(*MG));
        BacaRelasi(&Graph(*MG,i));
        Relasi(Graph(*MG,i),i) = 0;
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
void TulisRelasi(MGRAPH MG)
/* Menuliskan relasi antar mgraph secara simple */
/* contoh : Relasi bangunan 1 : 13, 14 */
/*          Relasi bangunan 2 : 15, 1, 6, 7 */
/*          dst */
{
    int jmlrelasi = 0;
    for(int i = 1; i<=NbGraph(MG) ; i++){
        for(int j = 1; j<=NbRelasi(Graph(MG,i)) ; j++){
            if(AdaRelasi(Graph(MG,i),j)){
                if(jmlrelasi == 0){
                    printf("Relasi bangunan ke-%d : %d",i,j);
                }
                else{
                    printf(", %d",j);
                }
                jmlrelasi++;
            }
        }
        if(jmlrelasi == 0){
            printf("Relasi bangunan ke-%d tidak ada",i);
        }
        printf("\n");
        jmlrelasi = 0;
    }
}


/* ----- OPERATOR BOOLEAN ----- */
boolean IsRelasiValid (int X)
/* Menghasilkan true jika masukan X = 0 atau X = 1 */
{
    return(X==1 || X==0);
}
boolean IsRelated (GRAPH G1,GRAPH G2)
/* Menghasilkan true GRAPH saling terhubung */
{
    return(Relasi(G1,ID(G2)) == 1); //kalo relasi di indeks ID G2 adalah 1 maka true, bila 0 maka false
}
boolean AdaRelasi (GRAPH G, int X)
/* Menghasilkan true jika relasi graph G ke X adalah 1*/
{
    return(Relasi(G,X));
}
