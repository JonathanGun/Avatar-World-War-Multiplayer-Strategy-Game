#include "graph.h"

/* ----- KONSTRUKTOR ----- */
Graph CreateGraph(int n){
    // membuat graph kosong untuk n bangunan
    return CreateGraphUtil(n, n);
}

Graph CreateGraphUtil(int r, int c){
    // membuat graph kosong dengan ukuran r*c
    if (r == 0) return NilGraph;
    Graph GR = CreateList(c);
    Trail(GR) = CreateGraphUtil(r-1, c);
    return GR;
}

Graph CreateList(int c){
    if(c == 1) return AlokasiGraph(false);
    Graph GR = AlokasiGraph(false);
    NextGraph(GR) = CreateList(c-1);
    return GR;
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
void SetBangunanTerhubung(Graph GR, int r, int c){
    GR = TrailN(GR, r-1);
    GR = NextGraphN(GR, c-1);
    Connect(GR) = true;
}

/* ----- OPERASI GRAF ----- */
void GetBangunanTerhubung(Graph GR, int r, ListBangunan* AdjList){
    // input indeks bangunan, return semua bangunan yg terhubung dgn dia di *AdjList
    // proses: traverse ke bwh sejumlah r, traverse ke kanan hingga ujung (sejumlah c), tambah ke AdjList jika Connect(G) == true
    CreateEmptyList(AdjList);
    GR = TrailN(GR, r-1);
    int i = 1;
    while(GR != NilGraph){
        if(Connect(GR)) InsertList(AdjList, i);
        GR = NextGraph(GR);
        i++;
    }
}

Graph NextGraphN(Graph GR, int n){
    // G ter-traverse ke kanan sejumlah n kali
    Graph F = GR;
    fori(i, n) F = NextGraph(F);
    return F;
}

Graph TrailN(Graph GR, int n){
    // G ter-traverse ke bawah sejumlah n kali
    Graph F = GR;
    fori(i, n) F = Trail(F);
    return F;
}

void PrintGraph(Graph GR){
    while(GR != NilGraph){
        Graph tmp = GR;
        while(tmp != NilGraph){
            prints(Connect(tmp));
            tmp = NextGraph(tmp);
        } ENDL;
        GR = Trail(GR);
    }
}