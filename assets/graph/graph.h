#ifndef GRAPH_H
#define GRAPH_H

#include "../util/util.h"
#include "../bangunan/list_bangunan.h"

/* Selektor */
#define IdGraph(P) (P)->Id
#define NPred(P) (P)->NPred
#define Trail(P) (P)->Trail
#define NextGraph(GR) (GR)->Next
#define Succ(P) (P)->Succ
#define NextSucc(P) (P)->Next
/* Konstruktor, Destruktor */

adrNode AlokNode(int X);
/* I.S. X adalah bilangan bulat valid */
/* F.S. Alokasi node dalam graph dengan ID X dan Npred, Trail dan Next diinisialisasikan 0,Nil,dan Nil  */
void DealokNode(adrNode P);
/* I.S. adrNode P valid */
/* F.S. Melakukan dealokasi dari P  */
adrSucc AlokSucc(adrNode Pn);
/* I.S. adrNode Pn valid */
/* F.S. Membuat address P , Mengalokasikan Succ(P) = Pn dan next = Nil */
void DealokSuccNode(adrSucc Pt);
/* I.S. adrSucc Pt valid */
/* F.S. Melakukan dealokasi pada SuccNode Pt */
void CreateGraph(Graph* G, int n);
/* I.S. Graph terdefinisi, mungkin kosong , n bilangan bulat valid */
/* F.S. Graph dibuat dengan Id dari First(G) adalah n */
void AddNodeGraph(Graph *G,int n);
/* I.S. Graph terdefinisi, mungkin kosong , n bilangan bulat valid */
/* F.S. Menambahkan Node di ujung graph dengan ID n */

/* OPERASI SEARCH */
adrNode SearchNode(Graph G, int X);
/* I.S. G berisi minimal 1 elemen, X adalah ID dari salah satu elemen graph */
/* F.S. Mengembalikan adrNode dari elemen dengan ID X */

/** SELEKTOR **/
void SetBangunanTerhubung(Graph *GR, int r, int c);
/* I.S. r  dan c adalah id dari graph yang valid */
/* F.S. c merupakan trail dari r */

/* ----- OPERASI GRAF ----- */
void GetBangunanTerhubung(Graph GR, int idxB, ListBangunan* AdjList);
/* I.S. idxB merupakan id yang valid dari suatu elemen dalam graph GR  */
/* F.S. ListBangunan terisi id dari semua bangunan yang terhubung dengan bangunan ber ID idxB */
void AddLastTrail(Graph *GR, int idB, int Trail);
// I.S. idB, Trail terdefinisi dan ada dalam suatu id graph, trail 
// F.S. Trail dimasukan sebagai trail terakhir di idB

void PrintGraph(Graph GR);
// memprint semua item di graph

#endif