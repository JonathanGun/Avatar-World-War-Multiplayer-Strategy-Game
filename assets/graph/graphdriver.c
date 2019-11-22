#include "newgraph.h"

int main(){
    Graph G = CreateGraph(1);
    AddNodeGraph(&G,2);
    AddNodeGraph(&G,3);
    AddNodeGraph(&G,4);
    PrintGraph(G);
}