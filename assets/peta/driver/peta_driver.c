#include "../peta.h"

int main(){
	int r, c;
	printf("Masukkan dimensi peta r <spasi> c: "); InputInt(&r); InputInt(&c);
	MakePeta(r, c);
	printf("Ini layout peta yang akan muncul di Game:"); ENDL;
	PrintPeta();
}