#include "mesinconfig.h"
#include "../listbangunan.h"
#include "../peta.h"
#include "../graph/graph.h"

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

typedef struct {
    int conf_banyak_bangunan;
    Peta conf_peta;
    ListBangunan conf_list_bangunan;
    Graph conf_relasi;
} Config;

void extract_config(Config conf);
// Mengekstrak informasi dalam "Config"

void extract_dimensi_peta(Peta *peta);
// Mengekstrak dimensi peta

void extract_banyak_bangunan(int *banyak_bangunan);
// Mengekstrak banyak bangunan

void extract_listBangunan(int banyak_bangunan, ListBangunan list_bangunan);
// Mengekstrak list bangunan

void extract_relasi(int banyak_bangunan, Graph relasi);
// Mengekstrak relasi

#endif
