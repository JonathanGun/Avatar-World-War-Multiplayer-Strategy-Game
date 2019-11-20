#include "data_bangunan.h"

Matriks AttCastle,AttTower,AttFort,AttVillage;

void MakeData(){
	MakeMatriks(&AttCastle, 4, 4);
	MatElmt(AttCastle, 1, 1) = 10;
	MatElmt(AttCastle, 2, 1) = 15;
	MatElmt(AttCastle, 3, 1) = 20;
	MatElmt(AttCastle, 4, 1) = 25;

	MatElmt(AttCastle, 1, 2) = 40;
	MatElmt(AttCastle, 2, 2) = 60;
	MatElmt(AttCastle, 3, 2) = 80;
	MatElmt(AttCastle, 4, 2) = 100;

	MatElmt(AttCastle, 1, 3) = 0;
	MatElmt(AttCastle, 2, 3) = 0;
	MatElmt(AttCastle, 3, 3) = 0;
	MatElmt(AttCastle, 4, 3) = 0;

	MatElmt(AttCastle, 1, 4) = 40;
	MatElmt(AttCastle, 2, 4) = 0;
	MatElmt(AttCastle, 3, 4) = 0;
	MatElmt(AttCastle, 4, 4) = 0;

	MakeMatriks(&AttTower, 4, 4);
	MatElmt(AttTower, 1, 1) = 5;
	MatElmt(AttTower, 2, 1) = 10;
	MatElmt(AttTower, 3, 1) = 20;
	MatElmt(AttTower, 4, 1) = 30;

	MatElmt(AttTower, 1, 2) = 20;
	MatElmt(AttTower, 2, 2) = 30;
	MatElmt(AttTower, 3, 2) = 40;
	MatElmt(AttTower, 4, 2) = 50;

	MatElmt(AttTower, 1, 3) = 1;
	MatElmt(AttTower, 2, 3) = 1;
	MatElmt(AttTower, 3, 3) = 1;
	MatElmt(AttTower, 4, 3) = 1;

	MatElmt(AttTower, 1, 4) = 30;
	MatElmt(AttTower, 2, 4) = 0;
	MatElmt(AttTower, 3, 4) = 0;
	MatElmt(AttTower, 4, 4) = 0;
	
	MakeMatriks(&AttFort, 4, 4);
	MatElmt(AttFort, 1, 1) = 10;
	MatElmt(AttFort, 2, 1) = 20;
	MatElmt(AttFort, 3, 1) = 30;
	MatElmt(AttFort, 4, 1) = 40;

	MatElmt(AttFort, 1, 2) = 20;
	MatElmt(AttFort, 2, 2) = 40;
	MatElmt(AttFort, 3, 2) = 60;
	MatElmt(AttFort, 4, 2) = 80;

	MatElmt(AttFort, 1, 3) = 0;
	MatElmt(AttFort, 2, 3) = 0;
	MatElmt(AttFort, 3, 3) = 1;
	MatElmt(AttFort, 4, 3) = 1;

	MatElmt(AttFort, 1, 4) = 80;
	MatElmt(AttFort, 2, 4) = 0;
	MatElmt(AttFort, 3, 4) = 0;
	MatElmt(AttFort, 4, 4) = 0;

	MakeMatriks(&AttVillage, 4, 4);
	MatElmt(AttVillage, 1, 1) = 5;
	MatElmt(AttVillage, 2, 1) = 10;
	MatElmt(AttVillage, 3, 1) = 15;
	MatElmt(AttVillage, 4, 1) = 20;

	MatElmt(AttVillage, 1, 2) = 20;
	MatElmt(AttVillage, 2, 2) = 30;
	MatElmt(AttVillage, 3, 2) = 40;
	MatElmt(AttVillage, 4, 2) = 50;

	MatElmt(AttVillage, 1, 3) = 0;
	MatElmt(AttVillage, 2, 3) = 0;
	MatElmt(AttVillage, 3, 3) = 0;
	MatElmt(AttVillage, 4, 3) = 0;

	MatElmt(AttVillage, 1, 4) = 20;
	MatElmt(AttVillage, 2, 4) = 0;
	MatElmt(AttVillage, 3, 4) = 0;
	MatElmt(AttVillage, 4, 4) = 0;
}