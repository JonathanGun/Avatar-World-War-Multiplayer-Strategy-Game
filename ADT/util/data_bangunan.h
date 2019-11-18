#ifndef __DATA_BANGUNAN_H_
#define __DATA_BANGUNAN_H_

#include "../matriks.h"

extern Matriks AttCastle,AttTower,AttFort,AttVillage;

void MakeData(){
	MakeMatriks(&AttCastle, 4, 4);
	MakeMatriks(&AttCastle, 4, 4);
	MakeMatriks(&AttFort, 4, 4);
	MakeMatriks(&AttVillage, 4, 4);
}

#endif