#ifndef __DATA_BANGUNAN_H_
#define __DATA_BANGUNAN_H_

#include "../matriks.h"

extern Matriks AttCastle,AttTower,AttFort,AttVillage;

void MakeData(){
	MakeMatriks(&AttCastle, 4, 4);
	MatELmt(AttVillage, 1, 1) = 10;
	MatELmt(AttVillage, 2, 1) = 15;
	MatELmt(AttVillage, 3, 1) = 20;
	MatELmt(AttVillage, 4, 1) = 25;

	MatELmt(AttVillage, 1, 2) = 40;
	MatELmt(AttVillage, 2, 2) = 60;
	MatELmt(AttVillage, 3, 2) = 80;
	MatELmt(AttVillage, 4, 2) = 100;

	MatELmt(AttVillage, 1, 3) = 0;
	MatELmt(AttVillage, 2, 3) = 0;
	MatELmt(AttVillage, 3, 3) = 0;
	MatELmt(AttVillage, 4, 3) = 0;

	MatELmt(AttVillage, 1, 4) = 40;
	MatELmt(AttVillage, 2, 4) = 0;
	MatELmt(AttVillage, 3, 4) = 0;
	MatELmt(AttVillage, 4, 4) = 0;

	MakeMatriks(&AttCastle, 4, 4);
	MatELmt(AttCastle, 1, 1) = 5;
	MatELmt(AttCastle, 2, 1) = 10;
	MatELmt(AttCastle, 3, 1) = 20;
	MatELmt(AttCastle, 4, 1) = 30;

	MatELmt(AttCastle, 1, 2) = 20;
	MatELmt(AttCastle, 2, 2) = 30;
	MatELmt(AttCastle, 3, 2) = 40;
	MatELmt(AttCastle, 4, 2) = 50;

	MatELmt(AttCastle, 1, 3) = 1;
	MatELmt(AttCastle, 2, 3) = 1;
	MatELmt(AttCastle, 3, 3) = 1;
	MatELmt(AttCastle, 4, 3) = 1;

	MatELmt(AttCastle, 1, 4) = 30;
	MatELmt(AttCastle, 2, 4) = 0;
	MatELmt(AttCastle, 3, 4) = 0;
	MatELmt(AttCastle, 4, 4) = 0;
	
	MakeMatriks(&AttFort, 4, 4);
	MatELmt(AttFort, 1, 1) = 10;
	MatELmt(AttFort, 2, 1) = 20;
	MatELmt(AttFort, 3, 1) = 30;
	MatELmt(AttFort, 4, 1) = 40;

	MatELmt(AttFort, 1, 2) = 20;
	MatELmt(AttFort, 2, 2) = 40;
	MatELmt(AttFort, 3, 2) = 60;
	MatELmt(AttFort, 4, 2) = 80;

	MatELmt(AttFort, 1, 3) = 0;
	MatELmt(AttFort, 2, 3) = 0;
	MatELmt(AttFort, 3, 3) = 1;
	MatELmt(AttFort, 4, 3) = 1;

	MatELmt(AttFort, 1, 4) = 80;
	MatELmt(AttFort, 2, 4) = 0;
	MatELmt(AttFort, 3, 4) = 0;
	MatELmt(AttFort, 4, 4) = 0;

	MakeMatriks(&AttVillage, 4, 4);
	MatELmt(AttVillage, 1, 1) = 5;
	MatELmt(AttVillage, 2, 1) = 10;
	MatELmt(AttVillage, 3, 1) = 15;
	MatELmt(AttVillage, 4, 1) = 20;

	MatELmt(AttVillage, 1, 2) = 20;
	MatELmt(AttVillage, 2, 2) = 30;
	MatELmt(AttVillage, 3, 2) = 40;
	MatELmt(AttVillage, 4, 2) = 50;

	MatELmt(AttVillage, 1, 3) = 0;
	MatELmt(AttVillage, 2, 3) = 0;
	MatELmt(AttVillage, 3, 3) = 0;
	MatELmt(AttVillage, 4, 3) = 0;

	MatELmt(AttVillage, 1, 4) = 20;
	MatELmt(AttVillage, 2, 4) = 0;
	MatELmt(AttVillage, 3, 4) = 0;
	MatELmt(AttVillage, 4, 4) = 0;
}

#endif