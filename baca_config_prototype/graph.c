#include "graph.h"
#include "boolean.h"
#include "macro.h"
#include <stdlib.h>
#include <stdio.h>

/* ----- KONSTRUKTOR ----- */
Graph CreateGraph(int r, int c){
    // membuat graph kosong dengan ukuran r*c
    if (r == 0) return NilGraph;
    Graph G = CreateList(c);
    Trail(G) = CreateGraph(r-1, c);
    return G;
}

Graph CreateList(int c){
    if(c == 1) return AlokasiGraph(false);
    Graph G = AlokasiGraph(false);
    NextGraph(G) = CreateList(c-1);
    return G;
}

/* ----- MANAJEMEN MEMORI ----- */
Graph AlokasiGraph(boolean X){
    Graph P = (Graph) malloc (sizeof(Graph)+1);
    if(P == NilGraph) return NilGraph;
    Connect(P) = X;
    Trail(P) = NilGraph;
    NextGraph(P) = NilGraph;
    return P;
}

void DealokasiGraph(Graph P){
    free(P);
}

/** SELEKTOR **/
void SetBangunanTerhubung(Graph G, int r, int c){
    G = TrailN(G, r-1);
    G = NextN(G, c-1);
    Connect(G) = true;
}

/* ----- OPERASI GRAF ----- */
void GetBangunanTerhubung(Graph G, int r, int c, TabInt* AdjList){
    // input indeks bangunan, return semua bangunan yg terhubung dgn dia di *AdjList
    // proses: traverse ke bwh sejumlah r, traverse ke kanan hingga ujung (sejumlah c), tambah ke AdjList jika Connect(G) == true
    MakeEmpty(AdjList, c);
    G = TrailN(G, r-1);
    int i = 1;
    while(G != NilGraph){
        if(Connect(G)) AddAsLastEl(AdjList, i);
        G = NextGraph(G);
        i++;
    }
}

Graph NextN(Graph G, int n){
    // G ter-traverse ke kanan sejumlah n kali
    Graph F = G;
    fori(i, n) F = NextGraph(F);
    return F;
}

Graph TrailN(Graph G, int n){
    // G ter-traverse ke bawah sejumlah n kali
    Graph F = G;
    fori(i, n) F = Trail(F);
    return F;
}

void PrintGraph(Graph G){
    while(G != NilGraph){
        Graph tmp = G;
        while(tmp != NilGraph){
            prints(Connect(tmp));
            tmp = NextGraph(tmp);
        } ENDL;
        G = Trail(G);
    }
}