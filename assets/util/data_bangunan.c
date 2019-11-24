#include "data_bangunan.h"

Matriks AttCastle,AttTower,AttFort,AttVillage;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void MakeMatriks (Matriks * M, int NB, int NK)
/* Membentuk sebuah Matriks “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

void MakeData()
/* Membentuk Matriks yang berisi Atribut Bangunan untuk keperluan LEVEL UP */
/* I.S. Sembarang */
/* F.S. Terbentuk 4 Matriks yang memuat atribut atribut Bangunan Dengan Ketentuan : Nomor Baris
merepresentasikan Level Bangunan, dan Nomor Kolom Merepresentasikan Atribut Bangunan yang berbeda
dimana Kolom 1 merepresentasikan A, Kolom 2 merepresentasikan M, Kolom 3 merepresentasikan P, dan
Kolom 4 merepresentasikan U */
{
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