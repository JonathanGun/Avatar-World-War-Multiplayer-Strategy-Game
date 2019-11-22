#include "graph.h"

int main(){
    Graph G = CreateGraph(1);
    AddNodeGraph(&G,2);
    AddNodeGraph(&G,3);
    AddNodeGraph(&G,4);
    adrNode P = SearchNode(G,2);
    printf("%p\n",&P);
    printf("%d\n",IdGraph(P));
    SetBangunanTerhubung(&G,1,2);
    SetBangunanTerhubung(&G,1,4);
    SetBangunanTerhubung(&G,1,3);

    PrintGraph(G);
}