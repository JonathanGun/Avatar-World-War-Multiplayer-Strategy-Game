#include "graph.h"
#include "util/boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* ----- KONSTRUKTOR ----- */
void CreateGraph(Graph* G){
    *G = AlokasiGraph(false);
}

/* ----- MANAJEMEN MEMORI ----- */
Graph AlokasiGraph(boolean X){
    Graph P = (Graph) malloc (sizeof(Graph));
    if (P != NilGraph) {
        Connect(P) = X;
        Trail(P) = NilGraph;
        NodeNext(P) = NilGraph;
    }
    return P;
}

void DealokasiGraph(Graph P){
    free(P);
}

/* ----- OPERASI GRAF ----- */
Graph GetBangunanTerhubung(Graph G, int r, int* AdjList){
    // input indeks bangunan, return semua bangunan yg terhubung dgn dia di *AdjList
    // proses: traverse ke bwh sejumlah r, traverse ke kanan hingga ujung, tambah ke AdjList jika Connect(G) == true
}

void NextN(Graph G, int n){
    // G ter-traverse ke kanan sejumlah n kali 
}

void TrailN(Graph G, int n){
    // G ter-traverse ke bawah sejumlah n kali
}