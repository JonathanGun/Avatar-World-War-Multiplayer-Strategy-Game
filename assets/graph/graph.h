#ifndef GRAPH_H
#define GRAPH_H

#include "../util/util.h"
#include "../bangunan/list_bangunan.h"

#define NilGraph NULL

/* Selektor */
#define Connect(GR) (GR)->Connect
#define Trail(GR) (GR)->Trail
#define NextGraph(GR) (GR)->Next

/* Konstruktor, Destruktor */
Graph CreateGraph(int n);
Graph CreateGraphUtil(int r, int c);
Graph CreateList(int c);
Graph AlokasiGraph(boolean X);
void DealokasiGraph(Graph P);

/* Setter, Getter */
void SetBangunanTerhubung(Graph GR, int r, int c);
void GetBangunanTerhubung(Graph GR, int r, ListBangunan* AdjList);

/* Traverse Graph */
Graph NextGraphN(Graph GR, int n);
Graph TrailN(Graph GR, int n);

/* I/O */
void PrintGraph(Graph GR);

#endif