#include "util/boolean.h"

#ifndef GRAPH_H
#define GRAPH_H

#define NilGraph NULL

typedef struct tNodeGraph* adrNode;
typedef struct tNodeGraph {
	boolean Connect;
    adrNode Trail;
    adrNode Next;
} adrNode;
typedef struct adrNode Graph;

/* ----- SELEKTOR ----- */
#define Connect(G) (G)->Connect
#define Trail(G) (G)->Trail
#define Next(G) (G)->Next
#define GraphNext(G) (G)->Next

#endif