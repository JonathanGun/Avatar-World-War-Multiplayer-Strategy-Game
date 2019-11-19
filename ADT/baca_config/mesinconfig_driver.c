#include "config_reader.h"
//g++ mesinconfig_driver.c config_reader.c mesinconfig.c ../util/mesinkata.c ../graph/graph.c ../arraydin.c ../listbangunan.c -o a

int main(){
	Config conf;
	extract_config(&conf);
	printf("Dimensi peta: "); prints(conf.conf_peta.NPetaBrsEff); println(conf.conf_peta.NPetaKolEff);
	printf("Jumlah bangunan: "); println(conf.conf_banyak_bangunan);
	printf("Relasi bangunan :\n");
	PrintGraph(conf.conf_relasi);
}