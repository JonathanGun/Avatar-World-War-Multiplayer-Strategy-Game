#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include "../util/util.h"
#include "../util/mesinfile.h"
#include "../graph/graph.h"
#include "../bangunan/arraydin_bangunan.h"
#include "../peta/peta.h"

void extract_config(char* fileconfig);
// Mengekstrak informasi dalam "Config"

void extract_peta();
// Mengekstrak dimensi peta

int extract_banyak_bangunan();
// Mengekstrak banyak bangunan

void extract_listBangunan(int banyak_bangunan);
// Mengekstrak list bangunan

void extract_relasi(int banyak_bangunan);
// Mengekstrak relasi

#endif
