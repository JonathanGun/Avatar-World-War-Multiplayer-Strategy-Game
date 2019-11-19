#include "graph.h"
#include "../util/mesinkata.h"

boolean EndKata;
Kata CKata;

int main(){
	printf("Masukkan dimensi graph r<spasi>c: ");
	int r, c;
	InputInt(&r); InputInt(&c);
	Graph G = CreateGraph(r,c);
	PrintGraph(G);
	printf("Masukkan angka n (jumlah input habis ini): ");
	int n; InputInt(&n);
	while(n--){
		printf("Masukkan koordinat untuk dijadikan 1 r<spasi>c: ");
		int x; int y;
		InputInt(&x); InputInt(&y);
		SetBangunanTerhubung(G, x, y);
		PrintGraph(G);
	}
	printf("Bangunan Terhubung dengan row 1:");
	TabInt T;
	GetBangunanTerhubung(G, 1, c, &T);
	TulisIsiTab(T);
}