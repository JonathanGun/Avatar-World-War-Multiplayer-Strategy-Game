/* File: graph.h */
/* Tanggal: 22 Oktober 2019 */
/* *** Definisi ABSTRACT DATA TYPE GRAPH *** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID; /* ID dari suatu graph */
	POINT Koor; /* koordinat */
    int *Relasi; /*List relasi ke ID lainnya*/
    int NbRelasi; /* Banyaknya relasi */
} GRAPH;

typedef struct {
	GRAPH *TG; /* List of graph, ditampilkan dalam matrix */
    int NbGRAPH; /* Jumlah graph */
} MGRAPH;

/* Primitive selektor */
#define KoorX(G)    (G).Koor.X
#define KoorY(G)    (G).Koor.Y
#define Relasi(G,i) (G).Relasi[i]
#define ID(G)       (G).ID
#define NbRelasi(G) (G).NbRelasi
#define Graph(MG,i) (MG).TG[i]
#define NbGraph(MG) (MG).NbGRAPH
/* Definisi tipe data GRAPH: memiliki ID ( dalam matriks baris ) dan relasinya ( dalam matriks kolom ) ke ID lainnya.
 indeks dari suatu GRAPH adalah titiknya dalam map.
 Bila terdapat 2 graph dan GRAPH A memiliki relasi ke GRAPH B maka pasti GRAPH B memiliki relasi ke GRAPH A */

/* ----- KONSTRUKTOR ----- */
GRAPH MakeGRAPH(int ID, int NbRelasi, int x, int y);
/*Membuat Graph dengan banyak relasi sejumlah banyaknya elemen*/
/*Relasi GRAPH kosong*/
/*Koordinat GRAPH adalah A */

MGRAPH MakeMGRAPH(int NbGraph);
/* Membuat matrix of GRAPH kosong */

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
void Dealokasi(MGRAPH *MG);
/* Mengembalikan array eksplisit Relasi dan TabGraph ke sistem */

/* ----- OPERATOR BOOLEAN ----- */
boolean IsRelasiValid (GRAPH G, int X);
/* Menghasilkan true jika masukan 1 <= X <= NRelasi(G) */
boolean IsRelated (GRAPH G1,GRAPH G2);
/* Menghasilkan true GRAPH saling terhubung */
boolean SearchRelasi (GRAPH G, int X);
/* Menghasilkan true jika relasi graph G ke ID adalah 1*/

#endif
