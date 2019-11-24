#include "../point.c"

int main(){
	printf("======== Program Penjabaran Informasi Beberapa Titik =======\n");
	printf("\t\tOleh Jonathan Yudi Gunawan\n");
	printf("\t\t\t13518084\n");
	printf("============================================================\n");

	int n;
	printf("Jumlah titik yang ingin diinput: ");
	scanf("%d", &n);

	POINT p;
	for (int i = 0; i < n; ++i){
		printf("Masukkan %d titik lagi dengan format X<spasi>Y<enter>:\n", n-i);
		printf(">>> "); BacaPOINT(&p);

		printf("Titik %d : ", i+1); TulisPOINT(p);
		printf("\nTerletak di kuadran %d\n", Kuadran(p));
		
		if (IsOnSbX(p)){
			printf("Terletak di sumbu X\n");
		}

		if (IsOnSbY(p)){
			printf("Terletak di sumbu Y\n");
		}
		
		if (IsOrigin(p)){
			printf("Terletak di pusat koordinat (0,0)\n");
		} else {
			printf("Jarak ke pusat koordinat (0,0): %.3f\n", Jarak0(p));
		}

		POINT tmp;
		printf("\nBerikut informasi tambahan:\n");
		printf("Titik di kanannya\t\t: "); TulisPOINT(NextX(p));
		printf("\nTitik di atasnya\t\t: "); TulisPOINT(NextY(p));

		tmp = p; GeserKeSbX(&tmp);
		printf("\nProyeksi ke sumbu X\t\t: "); TulisPOINT(tmp);
		tmp = p; GeserKeSbY(&tmp);
		printf("\nProyeksi ke sumbu Y\t\t: "); TulisPOINT(tmp);

		tmp = p; Mirror(&tmp, true);
		printf("\nCerminan terhadap sumbu X\t: "); TulisPOINT(tmp);
		tmp = p; Mirror(&tmp, false);
		printf("\nCerminan terhadap sumbu Y\t: "); TulisPOINT(tmp);
		printf("\n");
	
		int edit;
		printf("\nMau merotasi titik tadi? (YES = 1/ NO = 0)\n");
		printf(">>> "); scanf("%d", &edit);

		if (edit){
			float s;
			printf("\nMasukkan sudut rotasi (dalam derajat):\n");
			printf(">>> "); scanf("%f", &s);

			tmp = p; Putar(&tmp, s);
			printf("Setelah rotasi\t\t\t: "); TulisPOINT(tmp);
			printf("\n");
		}
		printf("\n");
	}
	

	return 0;
}