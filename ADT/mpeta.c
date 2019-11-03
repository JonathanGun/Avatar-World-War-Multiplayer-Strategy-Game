#include "peta.h"

int main(){
	Peta P;
	int R, C, NBangunan;
	R = 10;
	C = 10;
	NBangunan = 10;
	MakePeta(&P, R, C, NBangunan);
	ArrElmt(Info(P), 1) = 1;
	ArrElmt(Info(P), 2) = 2;
	ArrElmt(Info(P), 3) = 3;
	ArrElmt(Info(P), 4) = 4;
	TulisPeta(P);
	return 0;
}