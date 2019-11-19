#include "macro.h"
#include "mesinkata.h"
#include <stdio.h>

Kata CKata;
boolean EndKata;

// ===== PENGGUNAAN MESIN KATA =====
// 	STARTKATA("namafile.txt") - start file
// 	InputInt(int*) - input int dari stdin
// 	InputKata(Kata*) - input kata dari stdin
// 	BacaInt(int*) - baca dari kata yg sudah distart
// 	BacaKata(Kata*) - baca kata dari file yg sudah distart 
// contoh implementasi:
int main(){
	// Kata K;
	// char c[7] = "AVATAR";
	// MakeKata(&K, c, 7);
	// PrintKata(K);
	// Kata N;
	// InputKata(&N);
	// print(CompareKata(K, N));

	// int n;
	// InputInt(&n);
	// println(n);
	// while(n--){
	// 	Kata tmp;
	// 	InputKata(&tmp);
	// 	PrintKata(tmp); ENDL;
	// }

	STARTKATA("config.txt");
	Kata L;
	BacaKata(&L);
	PrintKata(L);ENDL;
	Kata K;
	InputKata(&K);
	PrintKata(K); ENDL;
	print(CompareKata(K, L));
	// int r, c;
	// BacaInt(&r); BacaInt(&c);
	// prints(r); println(c);
	
	// int n;
	// BacaInt(&n);
	// println(n);

	// for(int i = 0; i < n; i++){
	// 	Kata b;
	// 	BacaKata(&b);
	// 	int x, y;
	// 	BacaInt(&x); BacaInt(&y);
	// 	PrintKata(b); prints(x); println(y);
	// }
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		int tmp;
	// 		BacaInt(&tmp);
	// 		prints(tmp);
	// 	} ENDL;
	// }

	return 0;
}