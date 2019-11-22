#ifndef GRAPH_H
#define GRAPH_H

#include "../util/util.h"
#include "../bangunan/list_bangunan.h"

#define NilGraph NULL
/*
typedef struct tNodeGraph* adrNode;
typedef struct tAdrSucc* adrSucc;
typedef struct tNodeGraph {
	int Id;
    int NPred;
    adrSucc Trail; // ke bawah
    adrNode Next; // ke kanan
} NodeGraph;
typedef struct tAdrSucc {
    adrNode Succ;
    adrSucc Next;
}
typedef struct {
    adrNode First;
}Graph;
*/
/* Selektor */
#define IdGraph(P) (P)->Id
#define NPred(P) (P)->NPred
#define Trail(P) (P)->Trail
#define NextGraph(GR) (GR)->Next
#define Succ(P) (P)->Succ
#define NextSucc(P) (P)->Next
/* Konstruktor, Destruktor */

adrNode AlokNode(int X);
void DealokNode(adrNode P);
adrSucc AlokSucc(adrNode Pn);
void DealokSuccNode(adrSucc Pt);
Graph CreateGraph(int n);
void AddNodeGraph(Graph *G,int n);

/* OPERASI SEARCH */
adrNode SearchNode(Graph G, int X);
//$ Mencari node dengan id X dalam graph G

/** SELEKTOR **/
void SetBangunanTerhubung(Graph *GR, int r, int c);
/*I.S. r  dan c adalah id dari graph yang valid
F.S. c merupakan trail dari r */

/* ----- OPERASI GRAF ----- */
void GetBangunanTerhubung(Graph GR, int idxB, ListBangunan* AdjList);
    // input indeks bangunan, return semua bangunan yg terhubung dgn dia di *AdjList
    // proses: traverse ke bwh sejumlah r, traverse ke kanan hingga ujung (sejumlah c), tambah ke AdjList jika Connect(G) == true

void AddLastTrail(Graph *GR, int idB, int Trail);
    // I.S. idB, Trail terdefinisi dan ada dalam suatu id graph, trail 
    // F.S. Trail dimasukan sebagai trail terakhir di idB

void PrintGraph(Graph GR);
    // memprint semua item di graph

#endif