#ifndef GRAPH_H
#define GRAPH_H

#include "../util/util.h"
#include "../bangunan/listbangunan.h"

#define NilGraph NULL

typedef struct tNodeGraph* adrNode;
typedef struct tNodeGraph {
	boolean Connect;
    adrNode Trail;
    adrNode Next;
} NodeGraph;
typedef adrNode Graph;

/* ----- SELEKTOR ----- */
#define Connect(G) (G)->Connect
#define Trail(G) (G)->Trail
#define NextGraph(G) (G)->Next

Graph CreateGraph(int r, int c);
Graph CreateList(int c);
Graph AlokasiGraph(boolean X);
void DealokasiGraph(Graph P);
void SetBangunanTerhubung(Graph G, int r, int c);
void GetBangunanTerhubung(Graph G, int r, ListBangunan* AdjList);
Graph NextGraphN(Graph G, int n);
Graph TrailN(Graph G, int n);
void PrintGraph(Graph G);

#endif