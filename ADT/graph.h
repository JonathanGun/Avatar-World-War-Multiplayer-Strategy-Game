/* File: graph.h */
/* Tanggal: 22 Oktober 2019 */
/* *** Definisi ABSTRACT DATA TYPE GRAPH *** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

typedef struct {
	int ID; /* ID dari suatu graph */
    int *Relasi; /*List relasi ke ID lainnya*/
    int NbRelasi; /* Banyaknya relasi */
} GRAPH;

typedef struct {
	GRAPH *TG; /* List of graph, ditampilkan dalam matrix */
    int NbGRAPH; /* Jumlah graph */
} MGRAPH;

/* Primitive selektor */
#define Relasi(G,i)         (G).Relasi[i]
#define ID(G)               (G).ID
#define NbRelasi(G)         (G).NbRelasi
#define Graph(MG,i)         (MG).TG[i]
#define NbGraph(MG)         (MG).NbGRAPH
/* Definisi tipe data GRAPH: memiliki ID ( dalam matriks baris ) dan relasinya ( dalam matriks kolom ) ke ID lainnya.
 Bila terdapat 2 graph dan GRAPH A memiliki relasi ke GRAPH B maka pasti GRAPH B memiliki relasi ke GRAPH A */

/* ----- KONSTRUKTOR ----- */
GRAPH MakeGRAPH(int ID, int NbRelasi);
/*Membuat Graph dengan banyak relasi sejumlah banyaknya elemen*/
/*Relasi GRAPH kosong*/
/*Koordinat GRAPH adalah A */
MGRAPH MakeMGRAPH(int NbGraph);
/* Membuat matrix of GRAPH kosong */
void Dealokasi(MGRAPH *MG);
/* Mengembalikan array eksplisit Relasi dan TabGraph ke sistem */
void CreateMGRAPH(MGRAPH *MG);
/* I.S. Matrix of Graph terdefinisi */
/*Membuat matrix of GRAPH dan mengisinya */
void CorrectMGRAPH(MGRAPH  *MG);
/* Membetulkan Matrix of Graph , yaitu misalnya ada relasi G1 ke G2 tapi tidak ada sebaliknya, */
/* maka relasi G2 ke G1 akan dikoreksi menjadi 1 */

/* ----- INTERAKSI IN/ OUT DEVICE ----- */
void BacaRelasi (GRAPH *G);
/* Membaca masing masing relasi di graph */
/* Misalnya ada relasi ke ID sekian, tulis 1, selain itu 0 */
void BacaMGRAPH (MGRAPH *MG);
/* Membaca relasi berulang ulang sampai semua GRAPH dalam MGRAPH relasinya terdefinisi */
void InsertGRAPH(GRAPH G, MGRAPH *MG, int idx);
/* Menyisipkan GRAPH G ke dalam MGRAPH MG dengan indeks idx */
void TulisGRAPH (GRAPH G);
/* Menuliskan relasi ke layar*/
/* Relasi dituliskan dalam bentuk true atau false */
/* Bila suatu GRAPH memiliki relasi dengan GRAPH lain, akan bernilai 1, kalau tidak akan bernilai 0 */
/* F.S. Relasi tertulis di layar dengan format "R1 R2 R3 ... RN" */
/* Contoh penulisan relasi : 0 1 1 0 1 0 
   Dibaca: GRAPH memiliki relasi ke GRAPH ber ID 2, 3 , dan 5
   GRAPH tidak mungkin memiliki relasi ke dirinya sendiri*/
void TulisMGRAPH(MGRAPH MG);
/* Menulis matriks graph secara keseluruhan */
void TulisRelasi(MGRAPH MG);
/* Menuliskan relasi antar mgraph secara simple */
/* contoh : Relasi bangunan 1 : 13, 14 */
/*          Relasi bangunan 2 : 15, 1, 6, 7 */
/*          dst */

/* ----- MEMBACA DARI FILE ----- */
MGRAPH BacaFileGRAPH();
/* Membaca MGRAPH dari suatu file yang kita input nama filenya */

/* ----- OPERATOR BOOLEAN ----- */
boolean IsRelasiValid (int X);
/* Menghasilkan true jika masukan X = 0 atau X = 1 */
boolean IsRelated (GRAPH G1,GRAPH G2);
/* Menghasilkan true GRAPH saling terhubung */
boolean AdaRelasi (GRAPH G, int X);
/* Menghasilkan true jika relasi graph G ke ID adalah 1*/

#endif
