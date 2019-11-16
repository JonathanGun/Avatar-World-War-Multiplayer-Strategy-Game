#include "../util.h"
#include "mesinkata.h"
#include <stdio.h>

Kata CKata;
boolean EndKata;

// STARTKATA(0) -> stdin
// STARTKATA('namafile.txt') -> dari file

int main(){
	STARTKATA(0);
	int n;
	InputInt(&n);
	println(n);
	while(n--){
		Kata tmp;
		InputKata(&tmp);
		PrintKata(tmp);
	}

	return 0;
}