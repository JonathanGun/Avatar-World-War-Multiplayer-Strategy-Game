#include "graph.h"

/* Konstruktor, Destruktor */
adrNode AlokNode(int X){
    adrNode P = (adrNode) malloc((sizeof(NodeGraph)+1));
    if(P != Nil){
        IdGraph(P) = X;
        NPred(P) = 0;
        Trail(P) = Nil;
        NextGraph(P) = Nil;
    }
}
void DealokNode(adrNode P)
{
    free(P);
}
adrSucc AlokSucc(adrNode Pn){
    adrSucc P = (adrSucc) malloc(sizeof(SuccGraph)+1);
    if(P!= Nil){
        Succ(P) = Pn;
        NextSucc(P) = Nil;
    }
}
void DealokSuccNode(adrSucc Pt){
    free(Pt);
}
void CreateGraph(Graph* G, int n){
    adrNode P = AlokNode(1);
    First(*G) = P;
    for(int i = 2; i <= n; i++){
        AddNodeGraph(G, i);
    }
}

void AddNodeGraph(Graph *G,int n)
/* I.S. Graph G terdefinisi */
/* F.S. ngeadd elemen ke dalam graph */
{
    adrNode P = AlokNode(n);
    adrNode A = First(*G);
    while(NextGraph(A) != NilGraph){
        A = NextGraph(A);
    }
    NextGraph(A) = P;
}

/* OPERASI SEARCH */
adrNode SearchNode(Graph G, int X){
//$ Mencari node dengan id X dalam graph G
    boolean found = false;
    adrNode A = First(G);
    while(A != Nil && IdGraph(A) != X){
        A = NextGraph(A);
    }
    if(A != Nil){
        return A;
    }
    else{
        return Nil;
    }
}

/** SELEKTOR **/
void SetBangunanTerhubung(Graph *GR, int r, int c){
/*I.S. r  dan c adalah id dari graph yang valid
F.S. c merupakan trail dari r */
    AddLastTrail(GR,r,c);
    AddLastTrail(GR,c,r);
}

/* ----- OPERASI GRAF ----- */
void GetBangunanTerhubung(Graph GR, int idxB, ListBangunan* AdjList){
    // input indeks bangunan, return semua bangunan yg terhubung dgn dia di *AdjList
    // proses: traverse ke bwh sejumlah r, traverse ke kanan hingga ujung (sejumlah c), tambah ke AdjList jika Connect(G) == true
    CreateEmptyList(AdjList);
    adrNode P = SearchNode(GR,idxB);
    adrSucc PT = Trail(P);
    int i = 1;
    while(NextSucc(PT) != NilGraph){
        InsertList(AdjList,IdGraph(Succ(NextSucc(PT))));
        PT = NextSucc(PT);
    }
}

void AddLastTrail(Graph *GR, int idB, int Trail){
    // I.S. idB, Trail terdefinisi dan ada dalam suatu id graph, trail 
    // F.S. Trail dimasukan sebagai trail terakhir di idB
    adrNode P = SearchNode(*GR,idB);
    adrNode PTrail = SearchNode(*GR,Trail);
    adrSucc Pn = AlokSucc(PTrail);
    adrSucc PT = Trail(P);
    if(PT != Nil){
        while(NextSucc(PT) != Nil){
            PT = NextSucc(PT);
        }
        NextSucc(PT) = Pn;
    }
    else{
        Trail(P) = Pn;
    }
}

void PrintGraph(Graph GR){
    adrNode P = First(GR);
    while(P != NilGraph){
        prints(IdGraph(P));
        printf("- ");
        adrSucc tmp = Trail(P);
        while(tmp != NilGraph){
            prints(IdGraph(Succ(tmp)));
            tmp = NextSucc(tmp);
        } ENDL;
        P = NextGraph(P);
    }
}
